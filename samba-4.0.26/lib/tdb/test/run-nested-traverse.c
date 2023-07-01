#include "../common/tdb_private.h"
#include "lock-tracking.h"
#define fcntl fcntl_with_lockcheck
#include "../common/io.c"
#include "../common/tdb.c"
#include "../common/lock.c"
#include "../common/freelist.c"
#include "../common/traverse.c"
#include "../common/transaction.c"
#include "../common/error.c"
#include "../common/open.c"
#include "../common/check.c"
#include "../common/hash.c"
#include "tap-interface.h"
#undef fcntl
#include <stdlib.h>
#include <stdbool.h>
#include "external-agent.h"
#include "logging.h"

static struct agent *agent;

static bool correct_key(TDB_DATA key)
{
	return key.dsize == strlen("hi")
		&& memcmp(key.dptr, "hi", key.dsize) == 0;
}

static bool correct_data(TDB_DATA data)
{
	return data.dsize == strlen("world")
		&& memcmp(data.dptr, "world", data.dsize) == 0;
}

static int traverse2(struct tdb_context *tdb, TDB_DATA key, TDB_DATA data,
		     void *p)
{
	ok1(correct_key(key));
	ok1(correct_data(data));
	return 0;
}

static int traverse1(struct tdb_context *tdb, TDB_DATA key, TDB_DATA data,
		     void *p)
{
	ok1(correct_key(key));
	ok1(correct_data(data));
	ok1(external_agent_operation(agent, TRANSACTION_START, tdb_name(tdb))
	    == WOULD_HAVE_BLOCKED);
	tdb_traverse(tdb, traverse2, NULL);

	/* That should *not* release the transaction lock! */
	ok1(external_agent_operation(agent, TRANSACTION_START, tdb_name(tdb))
	    == WOULD_HAVE_BLOCKED);
	return 0;
}

int main(int argc, char *argv[])
{
	struct tdb_context *tdb;
	TDB_DATA key, data;

	plan_tests(17);
	agent = prepare_external_agent();

	tdb = tdb_open_ex("run-nested-traverse.tdb", 1024, TDB_CLEAR_IF_FIRST,
			  O_CREAT|O_TRUNC|O_RDWR, 0600, &taplogctx, NULL);
	ok1(tdb);

	ok1(external_agent_operation(agent, OPEN, tdb_name(tdb)) == SUCCESS);
	ok1(external_agent_operation(agent, TRANSACTION_START, tdb_name(tdb))
	    == SUCCESS);
	ok1(external_agent_operation(agent, TRANSACTION_COMMIT, tdb_name(tdb))
	    == SUCCESS);

	key.dsize = strlen("hi");
	key.dptr = (void *)"hi";
	data.dptr = (void *)"world";
	data.dsize = strlen("world");

	ok1(tdb_store(tdb, key, data, TDB_INSERT) == 0);
	tdb_traverse(tdb, traverse1, NULL);
	tdb_traverse_read(tdb, traverse1, NULL);
	tdb_close(tdb);

	return exit_status();
}
