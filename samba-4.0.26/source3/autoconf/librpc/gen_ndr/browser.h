/* header auto-generated by pidl */

#ifndef _PIDL_HEADER_browser
#define _PIDL_HEADER_browser

#include <stdint.h>

#include "libcli/util/ntstatus.h"

#include "librpc/gen_ndr/srvsvc.h"
#ifndef _HEADER_browser
#define _HEADER_browser

struct BrowserrSrvInfo100Ctr {
	uint32_t entries_read;
	struct srvsvc_NetSrvInfo100 *entries;/* [size_is(entries_read),unique] */
};

struct BrowserrSrvInfo101Ctr {
	uint32_t entries_read;
	struct srvsvc_NetSrvInfo101 *entries;/* [size_is(entries_read),unique] */
};

union BrowserrSrvInfoUnion {
	struct BrowserrSrvInfo100Ctr *info100;/* [case(100),unique] */
	struct BrowserrSrvInfo101Ctr *info101;/* [unique,case(101)] */
}/* [switch_type(uint32)] */;

struct BrowserrSrvInfo {
	uint32_t level;
	union BrowserrSrvInfoUnion info;/* [switch_is(level)] */
};


struct BrowserrServerEnum {
	int _dummy_element;
};


struct BrowserrDebugCall {
	int _dummy_element;
};


struct BrowserrQueryOtherDomains {
	struct {
		const char *server_unc;/* [charset(UTF16),unique] */
		struct BrowserrSrvInfo *info;/* [ref] */
	} in;

	struct {
		uint32_t *total_entries;/* [ref] */
		struct BrowserrSrvInfo *info;/* [ref] */
		WERROR result;
	} out;

};


struct BrowserrResetNetlogonState {
	int _dummy_element;
};


struct BrowserrDebugTrace {
	int _dummy_element;
};


struct BrowserrQueryStatistics {
	int _dummy_element;
};


struct BrowserResetStatistics {
	int _dummy_element;
};


struct NetrBrowserStatisticsClear {
	int _dummy_element;
};


struct NetrBrowserStatisticsGet {
	int _dummy_element;
};


struct BrowserrSetNetlogonState {
	int _dummy_element;
};


struct BrowserrQueryEmulatedDomains {
	int _dummy_element;
};


struct BrowserrServerEnumEx {
	int _dummy_element;
};

#endif /* _HEADER_browser */
#endif /* _PIDL_HEADER_browser */
