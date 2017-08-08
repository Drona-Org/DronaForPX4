
  #include "linker.h"
  PRT_UINT32 P_EVENT_POrbPublish = 2;
  PRT_UINT32 P_EVENT_POrbSubscribe = 3;
  PRT_UINT32 P_FUN_Publish = 2;
  PRT_UINT32 P_FUN_Subscribe = 4;
  PRT_UINT32 P_IORM_BootMaster = 0;
  PRT_UINT32 P_IORM_POrbMachine = 1;
  PRT_UINT32 P_MACHINE_BootMaster = 0;
  PRT_UINT32 P_MACHINE_POrbMachine = 1;
  PRT_UINT32 P_RENAME_BootMaster = 0;
  PRT_UINT32 P_RENAME_POrbMachine = 1;
  PRT_UINT32 _P_EVENTS_COUNT = 6;
  PRT_UINT32 _P_EVENT_HALT = 1;
  PRT_UINT32 _P_EVENT_NULL = 0;
  PRT_UINT32 _P_FOREIGN_TYPES_COUNT = 0;
  PRT_UINT32 _P_FUNS_COUNT = 3;
  PRT_UINT32 _P_FUN_PUSH_OR_IGN = 0;
  PRT_UINT32 _P_IORM_COUNT = 2;
  PRT_UINT32 _P_MACHINES_COUNT = 2;
  PRT_UINT32 _P_RENAME_COUNT = 2;
  PRT_VALUE P_GEND_VALUE_EVENT_HALT = 
  {
    PRT_VALUE_KIND_EVENT,
    1U
  };
  PRT_VALUE P_GEND_VALUE_EVENT_NULL = 
  {
    PRT_VALUE_KIND_NULL,
    0U
  };
  PRT_VALUE P_GEND_VALUE_EVENT_POrbPublish = 
  {
    PRT_VALUE_KIND_EVENT,
    2U
  };
  PRT_VALUE P_GEND_VALUE_EVENT_POrbSubscribe = 
  {
    PRT_VALUE_KIND_EVENT,
    3U
  };
  PRT_UINT32 P_GEND_EVENTSET_0[] = 
  {
    0x0U
  };
  PRT_UINT32 P_GEND_EVENTSET_1[] = 
  {
    0x0CU
  };
  PRT_EVENTSETDECL P_GEND_EVENTSETS[] = 
  {
    
    {
        P_GEND_EVENTSET_0
    },
    
    {
        P_GEND_EVENTSET_1
    }
  };
  PRT_EVENTSETDECL P_GEND_EVENTSET = 
  {
    P_GEND_EVENTSET_0
  };
  PRT_EVENTSETDECL P_GEND_EVENTSET_POrbSubscribe_POrbPublish = 
  {
    P_GEND_EVENTSET_1
  };
  PRT_FUNDECL P_FUN_IGNORE_PUSH_STRUCT = 
  {
    0U,
    NULL,
    NULL,
    1U,
    0U,
    0U,
    NULL,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_UINT32 P_GEND_LINKMAP_BootMaster[] = 
  {
    0U,
    1U
  };
  PRT_UINT32 P_GEND_LINKMAP_POrbMachine[] = 
  {
    0U,
    1U
  };
  PRT_UINT32 P_GEND_RENAMEMAP[] = 
  {
    0U,
    1U
  };
  PRT_EVENTDECL *P_GEND_EVENTS[] = 
  {
    &_P_EVENT_NULL_STRUCT,
    &_P_EVENT_HALT_STRUCT,
    &P_EVENT_POrbPublish_STRUCT,
    &P_EVENT_POrbSubscribe_STRUCT
  };
  PRT_FUNDECL *P_GEND_FUNS[] = 
  {
    &P_FUN_IGNORE_PUSH_STRUCT,
    &P_FUN_Publish_STRUCT,
    &P_FUN_Subscribe_STRUCT
  };
  PRT_MACHINEDECL *P_GEND_MACHINES[] = 
  {
    &P_MACHINE_BootMaster_STRUCT,
    &P_MACHINE_POrbMachine_STRUCT
  };
  PRT_UINT32 *P_GEND_LINKMAP[] = 
  {
    P_GEND_LINKMAP_BootMaster,
    P_GEND_LINKMAP_POrbMachine
  };
  PRT_PROGRAMDECL P_GEND_PROGRAM = 
  {
    4U,
    2U,
    2U,
    3U,
    0U,
    P_GEND_EVENTS,
    P_GEND_EVENTSETS,
    P_GEND_MACHINES,
    P_GEND_FUNS,
    NULL,
    P_GEND_LINKMAP,
    P_GEND_RENAMEMAP,
    0U,
    NULL
  };
  