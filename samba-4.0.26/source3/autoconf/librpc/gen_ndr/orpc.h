/* header auto-generated by pidl */

#ifndef _PIDL_HEADER_ObjectRpcBaseTypes
#define _PIDL_HEADER_ObjectRpcBaseTypes

#include <stdint.h>

#include "libcli/util/ntstatus.h"

#include "librpc/gen_ndr/misc.h"
#ifndef _HEADER_ObjectRpcBaseTypes
#define _HEADER_ObjectRpcBaseTypes

#define COM_MAJOR_VERSION	( 5 )
#define COM_MINOR_VERSION	( 1 )
#define dcom_ext_debugging	( "f1f19680-4d2a-11ce-a66a-0020af6e72f4" )
#define dcom_ext_extended_error	( "f1f19681-4d2a-11ce-a66a-0020af6e72f4" )
#define COM_C_AUTHZ_NONE	( 0xffff )
#define OBJREF_SIGNATURE	( 0x574f454d )
struct COMVERSION {
	uint16_t MajorVersion;
	uint16_t MinorVersion;
}/* [public] */;

/* bitmap ORPC_FLAGS */
#define ORPCF_NULL ( 0x00 )
#define ORPCF_LOCAL ( 0x01 )
#define ORPCF_RESERVED1 ( 0x02 )
#define ORPCF_RESERVED2 ( 0x04 )
#define ORPCF_RESERVED3 ( 0x08 )
#define ORPCF_RESERVED4 ( 0x10 )

struct ORPC_EXTENT {
	struct GUID id;
	uint32_t size;
	uint8_t *data;/* [size_is(((size+7)&~7))] */
}/* [public] */;

struct ORPC_EXTENT_ARRAY {
	uint32_t size;
	uint32_t reserved;
	struct ORPC_EXTENT **extent;/* [unique,size_is(((size+1)&~1))] */
};

struct ORPCTHIS {
	struct COMVERSION version;
	uint32_t flags;
	uint32_t reserved1;
	struct GUID cid;
	struct ORPC_EXTENT_ARRAY *extensions;/* [unique] */
}/* [public] */;

struct ORPCTHAT {
	uint32_t flags;
	struct ORPC_EXTENT_ARRAY *extensions;/* [unique] */
}/* [public] */;

struct STRINGBINDING {
	uint16_t wTowerId;
	const char * NetworkAddr;/* [flag(LIBNDR_FLAG_STR_NULLTERM|LIBNDR_FLAG_ALIGN2)] */
}/* [public,flag(LIBNDR_FLAG_NOALIGN)] */;

struct STRINGARRAY {
	struct STRINGBINDING **stringbindings;/* [unique] */
}/* [nopush,noprint,nopull,public] */;

struct DUALSTRINGARRAY {
	struct STRINGBINDING **stringbindings;/* [unique] */
	struct SECURITYBINDING **securitybindings;/* [unique] */
}/* [public,noprint,nopull,nopush] */;

struct SECURITYBINDING {
	uint16_t wAuthnSvc;
	uint16_t wAuthzSvc;
	const char * PrincName;/* [flag(LIBNDR_FLAG_STR_NULLTERM|LIBNDR_FLAG_ALIGN2)] */
}/* [flag(LIBNDR_FLAG_NOALIGN),public] */;

enum OBJREF_FLAGS
#ifndef USE_UINT_ENUMS
 {
	OBJREF_NULL=(int)(0x0),
	OBJREF_STANDARD=(int)(0x1),
	OBJREF_HANDLER=(int)(0x2),
	OBJREF_CUSTOM=(int)(0x4)
}
#else
 { __donnot_use_enum_OBJREF_FLAGS=0x7FFFFFFF}
#define OBJREF_NULL ( 0x0 )
#define OBJREF_STANDARD ( 0x1 )
#define OBJREF_HANDLER ( 0x2 )
#define OBJREF_CUSTOM ( 0x4 )
#endif
;

/* bitmap STDOBJREF_FLAGS */
#define SORF_NULL ( 0x0000 )
#define SORF_OXRES1 ( 0x0001 )
#define SORF_OXRES2 ( 0x0020 )
#define SORF_OXRES3 ( 0x0040 )
#define SORF_OXRES4 ( 0x0080 )
#define SORF_OXRES5 ( 0x0100 )
#define SORF_OXRES6 ( 0x0200 )
#define SORF_OXRES7 ( 0x0400 )
#define SORF_OXRES8 ( 0x0800 )
#define SORF_NOPING ( 0x1000 )

struct STDOBJREF {
	uint32_t flags;
	uint32_t cPublicRefs;
	uint64_t oxid;
	uint64_t oid;
	struct GUID ipid;
}/* [public] */;

struct u_standard {
	struct STDOBJREF std;
	struct STRINGARRAY saResAddr;
};

struct u_handler {
	struct STDOBJREF std;
	struct GUID clsid;
	struct STRINGARRAY saResAddr;
};

struct u_custom {
	struct GUID clsid;
	uint32_t cbExtension;
	uint32_t size;
	uint8_t *pData;
};

struct u_null {
	char _empty_;
};

union OBJREF_Types {
	struct u_null u_null;/* [case(OBJREF_NULL)] */
	struct u_standard u_standard;/* [case(OBJREF_STANDARD)] */
	struct u_handler u_handler;/* [case(OBJREF_HANDLER)] */
	struct u_custom u_custom;/* [case(OBJREF_CUSTOM)] */
}/* [nodiscriminant] */;

struct OBJREF {
	uint32_t signature;
	uint32_t flags;
	struct GUID iid;
	union OBJREF_Types u_objref;/* [switch_type(uint32),switch_is(flags)] */
}/* [flag(LIBNDR_FLAG_LITTLE_ENDIAN),public] */;

struct MInterfacePointer {
	uint32_t size;
	struct OBJREF obj;/* [subcontext(4)] */
}/* [public] */;

enum COMRESULT
#ifndef USE_UINT_ENUMS
 {
	COM_OK=(int)(0x00000000),
	COM_OUTOFMEMORY=(int)(0x80000002),
	COM_INVALIDARG=(int)(0x80000003),
	COM_NOINTERFACE=(int)(0x80000004),
	COM_ACCESSDENIED=(int)(0x80070005),
	COM_INVALID_OXID=(int)(0x80070776),
	COM_INVALID_OID=(int)(0x80070777),
	COM_INVALID_SET=(int)(0x80070778),
	COM_UNEXPECTED=(int)(0x8000FFFF),
	COM_CLSNOTFOUND=(int)(0x80040154)
}
#else
 { __donnot_use_enum_COMRESULT=0x7FFFFFFF}
#define COM_OK ( 0x00000000 )
#define COM_OUTOFMEMORY ( 0x80000002 )
#define COM_INVALIDARG ( 0x80000003 )
#define COM_NOINTERFACE ( 0x80000004 )
#define COM_ACCESSDENIED ( 0x80070005 )
#define COM_INVALID_OXID ( 0x80070776 )
#define COM_INVALID_OID ( 0x80070777 )
#define COM_INVALID_SET ( 0x80070778 )
#define COM_UNEXPECTED ( 0x8000FFFF )
#define COM_CLSNOTFOUND ( 0x80040154 )
#endif
;

#endif /* _HEADER_ObjectRpcBaseTypes */
#endif /* _PIDL_HEADER_ObjectRpcBaseTypes */
