#ifndef __AUTOCONF_SOURCE3_PARAM_PARAM_GLOBAL_H__
#define __AUTOCONF_SOURCE3_PARAM_PARAM_GLOBAL_H__

/* This file was automatically generated by mkparamdefs.pl. DO NOT EDIT */

/**
 * This structure describes global (ie., server-wide) parameters.
 */
struct loadparm_global 
{
	TALLOC_CTX *ctx; /* Context for talloced members */
	bool   bReadRaw;
	bool   bWriteRaw;
	char *  szConfigFile;
	bool   bAllowInsecureWidelinks;
	bool   bAllowTrustedDomains;
	bool   bAsyncSMBEchoHandler;
	bool   bBindInterfacesOnly;
	bool   bBrowseList;
	bool   bClientLanManAuth;
	bool   bClientNTLMv2Auth;
	bool   bClientPlaintextAuth;
	bool   bClientUseSpnego;
	bool   client_use_spnego_principal;
	bool   clustering;
	bool   bCreateKrb5Conf;
	bool   bDebugClass;
	bool   bDebugHiresTimestamp;
	bool   bDebugPid;
	bool   bDebugPrefixTimestamp;
	bool   bDebugUid;
	bool   bDeferSharingViolations;
	bool   bDisableNetbios;
	bool   bDisableSpoolss;
	bool   bDomainLogons;
	bool   bASUSupport;
	bool   bEnableCoreFiles;
	bool   bEnablePrivileges;
	bool   bEncryptPasswords;
	bool   enhanced_browsing;
	bool   getwd_cache;
	bool   bHostMSDfs;
	bool   bHostnameLookups;
	bool   bLanmanAuth;
	bool   bLargeReadwrite;
	bool   ldap_delete_dn;
	bool   ldap_ssl_ads;
	bool   bLoadPrinters;
	bool   bLocalMaster;
	bool   bLogWriteableFilesOnExit;
	bool   bMapUntrustedToDomain;
	bool   bMsAddPrinterWizard;
	bool   bMulticastDnsRegister;
	bool   bNISHomeMap;
	bool   bNmbdBindExplicitBroadcast;
	bool   bNTLMAuth;
	bool   bNTPipeSupport;
	bool   bNTStatusSupport;
	bool   bNullPasswords;
	bool   bObeyPamRestrictions;
	bool   bPamPasswordChange;
	bool   bPassdbExpandExplicit;
	bool   bPasswdChatDebug;
	bool   bRegistryShares;
	bool   bResetOnZeroVC;
	bool   bRpcBigEndian;
	bool   bStatCache;
	bool   bSyslogOnly;
	bool   bTimestampLogs;
	bool   bTimeServer;
	bool   tls_enabled;
	bool   bUnicode;
	bool   bUnixExtensions;
	bool   bUnixPasswdSync;
	bool   bUseMmap;
	bool   bUsershareAllowGuests;
	bool   bUsershareOwnerOnly;
	bool   bUseSpnego;
	bool   bUtmp;
	bool   bWINSsupport;
	bool   bWinbindEnumGroups;
	bool   bWinbindEnumUsers;
	bool   bWinbindNestedGroups;
	bool   bWinbindNormalizeNames;
	bool   bWinbindOfflineLogon;
	bool   bWinbindRefreshTickets;
	bool   bWinbindRpcOnly;
	bool   bWinbindSealedPipes;
	bool   bWinbindTrustedDomainsOnly;
	bool   bWinbindUseDefaultDomain;
	bool   bWINSdnsProxy;
	bool   bWINSproxy;
	char *  szAfsUsernameMap;
	char *  ctdbdSocket;
	char *  szDedicatedKeytabFile;
	char *  szRealm_lower;
	char *  dns_forwarder;
	char *  dos_charset;
	char *  szGuestaccount;
	char *  szIdmapBackend;
	char *  szLockDir;
	char *  szLogonDrive;
	char *  szLogonHome;
	char *  szLogonPath;
	char *  szLogonScript;
	char *  nbt_client_socket_address;
	char *  ncalrpc_dir;
	char *  szNetbiosName;
	char *  szNetbiosScope;
	char *  szNTPSignDSocketDirectory;
	char *  passdb_backend;
	char *  szPasswordServer;
	char *  szPidDir;
	char *  szPrivateDir;
	char *  szRealm_upper;
	char *  szSMBPasswdFile;
	char *  socket_options;
	char *  szTemplateHomedir;
	char *  szTemplateShell;
	char *  unix_charset;
	char *  szUtmpDir;
	char *  szWinbinddPrivilegedSocketDirectory;
	char *  szWinbinddSocketDirectory;
	char *  szWinbindSeparator;
	char *  szWorkgroup;
	char *  szWtmpDir;
	int   iAfsTokenLifetime;
	int   AlgorithmicRidBase;
	int   allow_dns_updates;
	int   cldap_port;
	int   client_ldap_sasl_wrapping;
	int   clientSchannel;
	int   client_signing;
	int   cli_maxprotocol;
	int   cli_minprotocol;
	int   ConfigBackend;
	int   ctdb_locktime_warn_threshold;
	int   ctdb_timeout;
	int   cups_connection_timeout;
	int   deadtime;
	int   dgram_port;
	int   domain_master;
	int   iIdmapCacheTime;
	int   iIdmapNegativeCacheTime;
	int   InitLogonDelay;
	int   iKeepalive;
	int   iKerberosMethod;
	int   kpasswd_port;
	int   krb5_port;
	int   ldap_connection_timeout;
	int   ldap_debug_level;
	int   ldap_debug_threshold;
	int   ldap_deref;
	int   ldap_follow_referral;
	int   ldap_page_size;
	int   ldap_passwd_sync;
	int   ldap_replication_sleep;
	int   ldap_ssl;
	int   ldap_timeout;
	int   lm_announce;
	int   lm_interval;
	int   iLockSpinTime;
	int   lpqcachetime;
	int   machine_password_timeout;
	int   mangle_prefix;
	int   map_to_guest;
	int   maxdisksize;
	int   max_log_size;
	int   max_mux;
	int   max_open_files;
	int   iMaxSmbdProcesses;
	int   iMaxStatCacheSize;
	int   max_ttl;
	int   max_wins_ttl;
	int   max_xmit;
	int   min_wins_ttl;
	int   name_cache_timeout;
	int   nbt_port;
	int   open_files_db_hash_size;
	int   oplock_break_wait_time;
	int   os_level;
	int   iPasswdChatTimeout;
	int   pwordlevel;
	int   PrintcapCacheTime;
	int   restrict_anonymous;
	int   security;
	int   server_role;
	int   serverSchannel;
	int   server_signing;
	int   ismb2_max_read;
	int   ismb2_max_trans;
	int   ismb2_max_write;
	int   srv_maxprotocol;
	int   srv_minprotocol;
	int   syslog;
	int   unamelevel;
	int   iUsernameMapCacheTime;
	int   iUsershareMaxShares;
	int   web_port;
	int   winbind_cache_time;
	int   winbind_expand_groups;
	int   winbind_max_clients;
	int   winbind_reconnect_delay;
	int   winbind_request_timeout;
	const char **  AuthMethods;
	const char **  szClusterAddresses;
	const char **  dcerpc_ep_servers;
	const char **  szDNSUpdateCommand;
	const char **  szEventLogs;
	const char **  szInitLogonDelayedHosts;
	const char **  szInterfaces;
	const char **  szNameResolveOrder;
	const char **  szNetbiosAliases;
	const char **  szNSUpdateCommand;
	const char **  szPreloadModules;
	const char **  szRNDCCommand;
	const char **  szSambaKCCCommand;
	const char **  server_services;
	const char **  smb_ports;
	const char **  szSPNUpdateCommand;
	const char **  szServicesList;
	const char **  szUsersharePrefixAllowList;
	const char **  szUsersharePrefixDenyList;
	const char **  szWinbindNssInfo;
	const char **  szWINSservers;
	char *  szAbortShutdownScript;
	char *  szAddGroupScript;
	char *  szAddMachineScript;
	char *  szAddPortCommand;
	char *  szAddPrinterCommand;
	char *  szAddShareCommand;
	char *  szAddUserScript;
	char *  szAddUserToGroupScript;
	char *  szAutoServices;
	char *  szChangeShareCommand;
	char *  szCheckPasswordScript;
	char *  szCupsServer;
	char *  szDefaultService;
	char *  szDeletePrinterCommand;
	char *  szDeleteShareCommand;
	char *  szDelGroupScript;
	char *  szDelUserFromGroupScript;
	char *  szDelUserScript;
	char *  szEnumPortsCommand;
	char *  szGetQuota;
	char *  szIPrintServer;
	char *  szLdapAdminDn;
	char *  szLdapSuffix;
	char *  logfile;
	char *  szLogNtTokenCommand;
	char *  szManglingMethod;
	char *  szMsgCommand;
	char *  szNISHomeMapName;
	char *  szOs2DriverMap;
	char *  szPanicAction;
	char *  szPasswdChat;
	char *  szPasswdProgram;
	char *  szSMBPerfcountModule;
	char *  szRemoteAnnounce;
	char *  szRemoteBrowseSync;
	char *  szRenameUserScript;
	char *  szRootdir;
	char *  szServerString;
	char *  szSetPrimaryGroupScript;
	char *  szSetQuota;
	char *  szShareBackend;
	char *  szShutdownScript;
	char *  szUsernameMapScript;
	char *  szUsernameMap;
	char *  szUsersharePath;
	char *  szWINSHook;
LOADPARM_EXTRA_GLOBALS
};

#endif /* __AUTOCONF_SOURCE3_PARAM_PARAM_GLOBAL_H__ */

