#include "POrb.h"
#include "linker.h"

extern PRT_PROCESS* MAIN_APPLICATION_PROCESS;

extern "C" {

    PRT_VALUE *P_FUN_POrbMachine_InitializeDisPatchListener_FOREIGN(PRT_MACHINEINST *context, PRT_VALUE **payload)
	{
		//initialize the dispatcher
        //POrbMavlink::POrbMasterMachine = PrtGetMachine(MAIN_APPLICATION_PROCESS, payload);
		return NULL;
	}
}

void P_DTOR_POrbMachine_IMPL(PRT_MACHINEINST *context)
{
}


void P_CTOR_POrbMachine_IMPL(PRT_MACHINEINST *context, PRT_VALUE *value)
{
}
