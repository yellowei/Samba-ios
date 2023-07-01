#!/bin/bash

test_info()
{
    cat <<EOF
Verify that 'ctdb ip' shows the correct output.

Prerequisites:

* An active CTDB cluster with at least 2 active nodes.

Steps:

1. Verify that the status on all of the ctdb nodes is 'OK'.
2. Run 'ctdb ip' on one of the nodes and verify the list of IP
   addresses displayed (cross check the result with the output of
   'ip addr show' on the node).
3. Verify that pipe-separated output is generated with the -X option.

Expected results:

* 'ctdb ip' shows the list of public IPs being served by a node.
EOF
}

. "${TEST_SCRIPTS_DIR}/integration.bash"

ctdb_test_init

set -e

cluster_is_healthy

echo "Getting list of public IPs..."
try_command_on_node -v 1 "$CTDB ip all | tail -n +2"
ips=$(sed \
	-e 's@ node\[@ @' \
	-e 's@\].*$@@' \
	"$outfile")
machineout=$(sed -r \
	-e 's@^| |$@\|@g' \
	-e 's@[[:alpha:]]+\[@@g' \
	-e 's@\]@@g' \
	"$outfile")

if ctdb_test_on_cluster ; then
	while read ip pnn ; do
		try_command_on_node $pnn "ip addr show to ${ip}"
		if [ -n "$out" ] ; then
			echo "GOOD: node $pnn appears to have $ip assigned"
		else
			die "BAD: node $pnn does not appear to have $ip assigned"
		fi
	done <<<"$ips" # bashism to avoid problem setting variable in pipeline.
fi

echo "Looks good!"

cmd="$CTDB -X ip all | tail -n +2"
echo "Checking that \"$cmd\" produces expected output..."

try_command_on_node 1 "$cmd"
if [ "$out" = "$machineout" ] ; then
    echo "Yep, looks good!"
else
    echo "Nope, it looks like this:"
    echo "$out"
    echo "Should be like this:"
    echo "$machineout"
    exit 1
fi
