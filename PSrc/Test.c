#include "Test.h"

// Type universe for program:
static PRT_TYPE P_GEND_TYPE_n = { PRT_KIND_NULL, { NULL } };
static PRT_TYPE P_GEND_TYPE_i = { PRT_KIND_INT, { NULL } };
static PRT_TYPE P_GEND_TYPE_f = { PRT_KIND_FLOAT, { NULL } };
static PRT_TYPE* P_TUP_T[] = { &P_GEND_TYPE_f, &P_GEND_TYPE_f, &P_GEND_TYPE_f };
static PRT_TUPTYPE P_TUP = { 3U, P_TUP_T };
static PRT_TYPE P_GEND_TYPE_T3fff = { PRT_KIND_TUPLE, { .tuple = &P_TUP } };
static PRT_SEQTYPE P_SEQTYPE = { &P_GEND_TYPE_T3fff };
static PRT_TYPE P_GEND_TYPE_ST3fff = { PRT_KIND_SEQ, { .seq = &P_SEQTYPE } };
static PRT_TYPE P_GEND_TYPE_m = { PRT_KIND_MACHINE, { NULL } };

// Function implementation prototypes:
PRT_VALUE* P_omplMotionPlanExternal_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_testArray_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_Anon_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon;

PRT_VALUE* P_Anon_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_1;

PRT_VALUE* P_Anon_IMPL_2(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_2;

PRT_VALUE* P_Anon_IMPL_3(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_3;

PRT_VALUE* P_Anon_IMPL_4(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_4;

PRT_VALUE* P_Anon_IMPL_5(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_5;

PRT_VALUE* P_Anon_IMPL_6(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_6;

PRT_VALUE* P_Anon_IMPL_7(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_7;

PRT_VALUE* P_Anon_IMPL_8(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_8;

PRT_VALUE* P_Anon_IMPL_9(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_9;

PRT_VALUE* P_Anon_IMPL_10(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_10;


PRT_EVENTDECL P_EVENT_Success = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "Success",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_receiveMotionPlan = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "receiveMotionPlan",
    4294967295U,
    &P_GEND_TYPE_i
};

PRT_EVENTDECL P_EVENT_executePlan = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "executePlan",
    4294967295U,
    &P_GEND_TYPE_i
};

PRT_EVENTDECL P_EVENT_requestMotionPlan = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "requestMotionPlan",
    4294967295U,
    &P_GEND_TYPE_ST3fff
};

PRT_FUNDECL P_FUNCTION_omplMotionPlanExternal =
{
    "omplMotionPlanExternal",
    &P_omplMotionPlanExternal_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_testArray =
{
    "testArray",
    &P_testArray_IMPL,
    NULL
};


PRT_EVENTDECL* P_MotionPlanner_RECV_INNER[] = { &P_EVENT_Success, &P_EVENT_executePlan, &_P_EVENT_HALT_STRUCT, &P_EVENT_receiveMotionPlan, &P_EVENT_requestMotionPlan };
PRT_EVENTSETDECL P_EVENTSET_MotionPlanner_RECV =
{
    5U,
    P_MotionPlanner_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_MotionPlanner =
{
    0U,
    "MotionPlanner",
    &P_GEND_TYPE_m,
    &P_EVENTSET_MotionPlanner_RECV
};

PRT_EVENTDECL* P_PlanExecutor_RECV_INNER[] = { &P_EVENT_Success, &P_EVENT_executePlan, &_P_EVENT_HALT_STRUCT, &P_EVENT_receiveMotionPlan, &P_EVENT_requestMotionPlan };
PRT_EVENTSETDECL P_EVENTSET_PlanExecutor_RECV =
{
    5U,
    P_PlanExecutor_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_PlanExecutor =
{
    1U,
    "PlanExecutor",
    &P_GEND_TYPE_m,
    &P_EVENTSET_PlanExecutor_RECV
};

PRT_EVENTDECL* P_Robot_RECV_INNER[] = { &P_EVENT_Success, &P_EVENT_executePlan, &_P_EVENT_HALT_STRUCT, &P_EVENT_receiveMotionPlan, &P_EVENT_requestMotionPlan };
PRT_EVENTSETDECL P_EVENTSET_Robot_RECV =
{
    5U,
    P_Robot_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_Robot =
{
    2U,
    "Robot",
    &P_GEND_TYPE_ST3fff,
    &P_EVENTSET_Robot_RECV
};

PRT_EVENTDECL* P_Project_RECV_INNER[] = { &P_EVENT_Success, &P_EVENT_executePlan, &_P_EVENT_HALT_STRUCT, &P_EVENT_receiveMotionPlan, &P_EVENT_requestMotionPlan };
PRT_EVENTSETDECL P_EVENTSET_Project_RECV =
{
    5U,
    P_Project_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_Project =
{
    3U,
    "Project",
    &P_GEND_TYPE_n,
    &P_EVENTSET_Project_RECV
};

PRT_VARDECL P_MotionPlanner_VARS[] = {
    { "myRobot", &P_GEND_TYPE_m },
    { "destinations", &P_GEND_TYPE_i },
    { "x", &P_GEND_TYPE_i }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS =
{
    0U,
    P_Init_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER[] = { &P_EVENT_Success };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS =
{
    1U,
    P_Init_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS =
{
    0U,
    P_Init_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS[] =
{
    { 0, &P_EVENT_Success, 1, &_P_NO_OP }
};

#define P_STATE_MotionPlanner_Init \
{ \
    "MotionPlanner.Init", \
    1U, \
    0U, \
    &P_EVENTSET_Init_DEFERS, \
    &P_EVENTSET_Init_TRANS, \
    &P_EVENTSET_Init_DOS, \
    P_TRANS, \
    NULL, \
    &P_FUNCTION_Anon, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_WaitRequest_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitRequest_DEFERS =
{
    0U,
    P_WaitRequest_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_WaitRequest_TRANS_INNER[] = { &P_EVENT_requestMotionPlan };
PRT_EVENTSETDECL P_EVENTSET_WaitRequest_TRANS =
{
    1U,
    P_WaitRequest_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_WaitRequest_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitRequest_DOS =
{
    0U,
    P_WaitRequest_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS_1[] =
{
    { 1, &P_EVENT_requestMotionPlan, 2, &_P_NO_OP }
};

#define P_STATE_MotionPlanner_WaitRequest \
{ \
    "MotionPlanner.WaitRequest", \
    1U, \
    0U, \
    &P_EVENTSET_WaitRequest_DEFERS, \
    &P_EVENTSET_WaitRequest_TRANS, \
    &P_EVENTSET_WaitRequest_DOS, \
    P_TRANS_1, \
    NULL, \
    &P_FUNCTION_Anon_1, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_requestMotionPlanState_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_requestMotionPlanState_DEFERS =
{
    0U,
    P_requestMotionPlanState_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_requestMotionPlanState_TRANS_INNER[] = { &P_EVENT_Success };
PRT_EVENTSETDECL P_EVENTSET_requestMotionPlanState_TRANS =
{
    1U,
    P_requestMotionPlanState_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_requestMotionPlanState_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_requestMotionPlanState_DOS =
{
    0U,
    P_requestMotionPlanState_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS_2[] =
{
    { 2, &P_EVENT_Success, 1, &_P_NO_OP }
};

#define P_STATE_MotionPlanner_requestMotionPlanState \
{ \
    "MotionPlanner.requestMotionPlanState", \
    1U, \
    0U, \
    &P_EVENTSET_requestMotionPlanState_DEFERS, \
    &P_EVENTSET_requestMotionPlanState_TRANS, \
    &P_EVENTSET_requestMotionPlanState_DOS, \
    P_TRANS_2, \
    NULL, \
    &P_FUNCTION_Anon_2, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_MotionPlanner_STATES[] = { P_STATE_MotionPlanner_Init, P_STATE_MotionPlanner_WaitRequest, P_STATE_MotionPlanner_requestMotionPlanState };

PRT_VALUE* P_Anon_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload = argRefs[0];
    PRT_VALUE* PTMP_tmp0 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE = &(p_this->varValues[0]);
    PrtFreeValue(*P_LVALUE);
    *P_LVALUE = PrtCloneValue(*P_VAR_payload);
    
    PRT_VALUE** P_LVALUE_1 = &(PTMP_tmp0);
    PrtFreeValue(*P_LVALUE_1);
    *P_LVALUE_1 = PrtCloneValue((&P_EVENT_Success.value));
    
    PrtRaise(p_this, PTMP_tmp0, 0);
    *(&(PTMP_tmp0)) = NULL;
    goto p_return;
    
p_return: ;
    PrtFreeValue(PTMP_tmp0); PTMP_tmp0 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon =
{
    NULL,
    &P_Anon_IMPL,
    &P_GEND_TYPE_m
};


PRT_VALUE* P_Anon_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
p_return_1: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_1 =
{
    NULL,
    &P_Anon_IMPL_1,
    NULL
};


PRT_VALUE* P_Anon_IMPL_2(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_1 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_1 = NULL;
    PRT_VALUE* PTMP_tmp1 = NULL;
    PRT_VALUE* PTMP_tmp2 = NULL;
    PRT_VALUE* PTMP_tmp3 = NULL;
    PRT_VALUE* PTMP_tmp4 = NULL;
    PRT_VALUE* PTMP_tmp5 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_2 = &(PTMP_tmp0_1);
    PrtFreeValue(*P_LVALUE_2);
    *P_LVALUE_2 = PrtCloneValue(*P_VAR_payload_1);
    
    PRT_VALUE** P_LVALUE_3 = &(PTMP_tmp1);
    PrtFreeValue(*P_LVALUE_3);
    *P_LVALUE_3 = ((_P_GEN_funargs[0] = &(PTMP_tmp0_1)), (_P_GEN_funval = P_omplMotionPlanExternal_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp0_1), PTMP_tmp0_1 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_2;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_2;
    }
    
    {
        PRT_VALUE** P_LVALUE_4 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_4);
        *P_LVALUE_4 = PTMP_tmp1;
        PTMP_tmp1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_5 = &(PTMP_tmp2);
    PrtFreeValue(*P_LVALUE_5);
    *P_LVALUE_5 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_6 = &(PTMP_tmp3);
    PrtFreeValue(*P_LVALUE_6);
    *P_LVALUE_6 = PrtCloneValue((&P_EVENT_receiveMotionPlan.value));
    
    PRT_VALUE** P_LVALUE_7 = &(PTMP_tmp4);
    PrtFreeValue(*P_LVALUE_7);
    *P_LVALUE_7 = PrtCloneValue(p_this->varValues[1]);
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp2), PTMP_tmp3, 1, &(PTMP_tmp4));
    *(&(PTMP_tmp3)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_2;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_2;
    }
    
    PRT_VALUE** P_LVALUE_8 = &(PTMP_tmp5);
    PrtFreeValue(*P_LVALUE_8);
    *P_LVALUE_8 = PrtCloneValue((&P_EVENT_Success.value));
    
    PrtRaise(p_this, PTMP_tmp5, 0);
    *(&(PTMP_tmp5)) = NULL;
    goto p_return_2;
    
p_return_2: ;
    PrtFreeValue(PTMP_tmp0_1); PTMP_tmp0_1 = NULL;
    PrtFreeValue(PTMP_tmp1); PTMP_tmp1 = NULL;
    PrtFreeValue(PTMP_tmp2); PTMP_tmp2 = NULL;
    PrtFreeValue(PTMP_tmp3); PTMP_tmp3 = NULL;
    PrtFreeValue(PTMP_tmp4); PTMP_tmp4 = NULL;
    PrtFreeValue(PTMP_tmp5); PTMP_tmp5 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_2 =
{
    NULL,
    &P_Anon_IMPL_2,
    &P_GEND_TYPE_ST3fff
};


PRT_FUNDECL* P_MotionPlanner_METHODS[] = { &P_FUNCTION_Anon, &P_FUNCTION_Anon_1, &P_FUNCTION_Anon_2 };

PRT_EVENTDECL* P_MotionPlanner_RECV_INNER_1[] = { &P_EVENT_Success, &P_EVENT_executePlan, &_P_EVENT_HALT_STRUCT, &P_EVENT_receiveMotionPlan, &P_EVENT_requestMotionPlan };
PRT_EVENTSETDECL P_EVENTSET_MotionPlanner_RECV_1 =
{
    5U,
    P_MotionPlanner_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_MotionPlanner_SEND_INNER[] = { &P_EVENT_Success, &P_EVENT_executePlan, &_P_EVENT_HALT_STRUCT, &P_EVENT_receiveMotionPlan, &P_EVENT_requestMotionPlan };
PRT_EVENTSETDECL P_EVENTSET_MotionPlanner_SEND =
{
    5U,
    P_MotionPlanner_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_MotionPlanner = 
{
    0U,
    "MotionPlanner",
    &P_EVENTSET_MotionPlanner_RECV_1,
    &P_EVENTSET_MotionPlanner_SEND,
    NULL,
    3U,
    3U,
    3U,
    4294967295U,
    0U,
    P_MotionPlanner_VARS,
    P_MotionPlanner_STATES,
    P_MotionPlanner_METHODS
};

PRT_VARDECL P_PlanExecutor_VARS[] = {
    { "myRobot", &P_GEND_TYPE_m },
    { "x", &P_GEND_TYPE_i }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_1[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_1 =
{
    0U,
    P_Init_DEFERS_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER_1[] = { &P_EVENT_Success };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS_1 =
{
    1U,
    P_Init_TRANS_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER_1[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS_1 =
{
    0U,
    P_Init_DOS_INNER_1,
    NULL
};

PRT_TRANSDECL P_TRANS_3[] =
{
    { 0, &P_EVENT_Success, 1, &_P_NO_OP }
};

#define P_STATE_PlanExecutor_Init \
{ \
    "PlanExecutor.Init", \
    1U, \
    0U, \
    &P_EVENTSET_Init_DEFERS_1, \
    &P_EVENTSET_Init_TRANS_1, \
    &P_EVENTSET_Init_DOS_1, \
    P_TRANS_3, \
    NULL, \
    &P_FUNCTION_Anon_3, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_WaitRequest_DEFERS_INNER_1[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitRequest_DEFERS_1 =
{
    0U,
    P_WaitRequest_DEFERS_INNER_1,
    NULL
};

PRT_EVENTDECL* P_WaitRequest_TRANS_INNER_1[] = { &P_EVENT_executePlan };
PRT_EVENTSETDECL P_EVENTSET_WaitRequest_TRANS_1 =
{
    1U,
    P_WaitRequest_TRANS_INNER_1,
    NULL
};

PRT_EVENTDECL* P_WaitRequest_DOS_INNER_1[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitRequest_DOS_1 =
{
    0U,
    P_WaitRequest_DOS_INNER_1,
    NULL
};

PRT_TRANSDECL P_TRANS_4[] =
{
    { 1, &P_EVENT_executePlan, 2, &_P_NO_OP }
};

#define P_STATE_PlanExecutor_WaitRequest \
{ \
    "PlanExecutor.WaitRequest", \
    1U, \
    0U, \
    &P_EVENTSET_WaitRequest_DEFERS_1, \
    &P_EVENTSET_WaitRequest_TRANS_1, \
    &P_EVENTSET_WaitRequest_DOS_1, \
    P_TRANS_4, \
    NULL, \
    &P_FUNCTION_Anon_4, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_executePlanState_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_executePlanState_DEFERS =
{
    0U,
    P_executePlanState_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_executePlanState_TRANS_INNER[] = { &P_EVENT_Success };
PRT_EVENTSETDECL P_EVENTSET_executePlanState_TRANS =
{
    1U,
    P_executePlanState_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_executePlanState_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_executePlanState_DOS =
{
    0U,
    P_executePlanState_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS_5[] =
{
    { 2, &P_EVENT_Success, 1, &_P_NO_OP }
};

#define P_STATE_PlanExecutor_executePlanState \
{ \
    "PlanExecutor.executePlanState", \
    1U, \
    0U, \
    &P_EVENTSET_executePlanState_DEFERS, \
    &P_EVENTSET_executePlanState_TRANS, \
    &P_EVENTSET_executePlanState_DOS, \
    P_TRANS_5, \
    NULL, \
    &P_FUNCTION_Anon_5, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_PlanExecutor_STATES[] = { P_STATE_PlanExecutor_Init, P_STATE_PlanExecutor_WaitRequest, P_STATE_PlanExecutor_executePlanState };

PRT_VALUE* P_Anon_IMPL_3(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_2 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_2 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_9 = &(p_this->varValues[0]);
    PrtFreeValue(*P_LVALUE_9);
    *P_LVALUE_9 = PrtCloneValue(*P_VAR_payload_2);
    
    PRT_VALUE** P_LVALUE_10 = &(PTMP_tmp0_2);
    PrtFreeValue(*P_LVALUE_10);
    *P_LVALUE_10 = PrtCloneValue((&P_EVENT_Success.value));
    
    PrtRaise(p_this, PTMP_tmp0_2, 0);
    *(&(PTMP_tmp0_2)) = NULL;
    goto p_return_3;
    
p_return_3: ;
    PrtFreeValue(PTMP_tmp0_2); PTMP_tmp0_2 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_3 =
{
    NULL,
    &P_Anon_IMPL_3,
    &P_GEND_TYPE_m
};


PRT_VALUE* P_Anon_IMPL_4(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
p_return_4: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_4 =
{
    NULL,
    &P_Anon_IMPL_4,
    NULL
};


PRT_VALUE* P_Anon_IMPL_5(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_3 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_3 = NULL;
    PRT_VALUE* PTMP_tmp1_1 = NULL;
    PRT_VALUE* PTMP_tmp2_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_11 = &(PTMP_tmp0_3);
    PrtFreeValue(*P_LVALUE_11);
    *P_LVALUE_11 = PrtCloneValue(*P_VAR_payload_3);
    
    PRT_VALUE** P_LVALUE_12 = &(PTMP_tmp1_1);
    PrtFreeValue(*P_LVALUE_12);
    *P_LVALUE_12 = ((_P_GEN_funargs[0] = &(PTMP_tmp0_3)), (_P_GEN_funval = P_testArray_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp0_3), PTMP_tmp0_3 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_5;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_5;
    }
    
    {
        PRT_VALUE** P_LVALUE_13 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_13);
        *P_LVALUE_13 = PTMP_tmp1_1;
        PTMP_tmp1_1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_14 = &(PTMP_tmp2_1);
    PrtFreeValue(*P_LVALUE_14);
    *P_LVALUE_14 = PrtCloneValue((&P_EVENT_Success.value));
    
    PrtRaise(p_this, PTMP_tmp2_1, 0);
    *(&(PTMP_tmp2_1)) = NULL;
    goto p_return_5;
    
p_return_5: ;
    PrtFreeValue(PTMP_tmp0_3); PTMP_tmp0_3 = NULL;
    PrtFreeValue(PTMP_tmp1_1); PTMP_tmp1_1 = NULL;
    PrtFreeValue(PTMP_tmp2_1); PTMP_tmp2_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_5 =
{
    NULL,
    &P_Anon_IMPL_5,
    &P_GEND_TYPE_i
};


PRT_FUNDECL* P_PlanExecutor_METHODS[] = { &P_FUNCTION_Anon_3, &P_FUNCTION_Anon_4, &P_FUNCTION_Anon_5 };

PRT_EVENTDECL* P_PlanExecutor_RECV_INNER_1[] = { &P_EVENT_Success, &P_EVENT_executePlan, &_P_EVENT_HALT_STRUCT, &P_EVENT_receiveMotionPlan, &P_EVENT_requestMotionPlan };
PRT_EVENTSETDECL P_EVENTSET_PlanExecutor_RECV_1 =
{
    5U,
    P_PlanExecutor_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_PlanExecutor_SEND_INNER[] = { &P_EVENT_Success, &P_EVENT_executePlan, &_P_EVENT_HALT_STRUCT, &P_EVENT_receiveMotionPlan, &P_EVENT_requestMotionPlan };
PRT_EVENTSETDECL P_EVENTSET_PlanExecutor_SEND =
{
    5U,
    P_PlanExecutor_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_PlanExecutor = 
{
    1U,
    "PlanExecutor",
    &P_EVENTSET_PlanExecutor_RECV_1,
    &P_EVENTSET_PlanExecutor_SEND,
    NULL,
    2U,
    3U,
    3U,
    4294967295U,
    0U,
    P_PlanExecutor_VARS,
    P_PlanExecutor_STATES,
    P_PlanExecutor_METHODS
};

PRT_VARDECL P_Robot_VARS[] = {
    { "my_project", &P_GEND_TYPE_m },
    { "motion_planner", &P_GEND_TYPE_m },
    { "plan_executor", &P_GEND_TYPE_m },
    { "ompl_motion_plan", &P_GEND_TYPE_i },
    { "motionplan", &P_GEND_TYPE_ST3fff }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_2[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_2 =
{
    0U,
    P_Init_DEFERS_INNER_2,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER_2[] = { &P_EVENT_Success };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS_2 =
{
    1U,
    P_Init_TRANS_INNER_2,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER_2[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS_2 =
{
    0U,
    P_Init_DOS_INNER_2,
    NULL
};

PRT_TRANSDECL P_TRANS_6[] =
{
    { 0, &P_EVENT_Success, 1, &_P_NO_OP }
};

#define P_STATE_Robot_Init \
{ \
    "Robot.Init", \
    1U, \
    0U, \
    &P_EVENTSET_Init_DEFERS_2, \
    &P_EVENTSET_Init_TRANS_2, \
    &P_EVENTSET_Init_DOS_2, \
    P_TRANS_6, \
    NULL, \
    &P_FUNCTION_Anon_6, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_WaitRequest_DEFERS_INNER_2[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitRequest_DEFERS_2 =
{
    0U,
    P_WaitRequest_DEFERS_INNER_2,
    NULL
};

PRT_EVENTDECL* P_WaitRequest_TRANS_INNER_2[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitRequest_TRANS_2 =
{
    0U,
    P_WaitRequest_TRANS_INNER_2,
    NULL
};

PRT_EVENTDECL* P_WaitRequest_DOS_INNER_2[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitRequest_DOS_2 =
{
    0U,
    P_WaitRequest_DOS_INNER_2,
    NULL
};

#define P_STATE_Robot_WaitRequest \
{ \
    "Robot.WaitRequest", \
    0U, \
    0U, \
    &P_EVENTSET_WaitRequest_DEFERS_2, \
    &P_EVENTSET_WaitRequest_TRANS_2, \
    &P_EVENTSET_WaitRequest_DOS_2, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_7, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_sendPlantoExecutorState_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_sendPlantoExecutorState_DEFERS =
{
    0U,
    P_sendPlantoExecutorState_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_sendPlantoExecutorState_TRANS_INNER[] = { &P_EVENT_Success };
PRT_EVENTSETDECL P_EVENTSET_sendPlantoExecutorState_TRANS =
{
    1U,
    P_sendPlantoExecutorState_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_sendPlantoExecutorState_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_sendPlantoExecutorState_DOS =
{
    0U,
    P_sendPlantoExecutorState_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS_7[] =
{
    { 1, &P_EVENT_Success, 2, &_P_NO_OP }
};

#define P_STATE_Robot_sendPlantoExecutorState \
{ \
    "Robot.sendPlantoExecutorState", \
    1U, \
    0U, \
    &P_EVENTSET_sendPlantoExecutorState_DEFERS, \
    &P_EVENTSET_sendPlantoExecutorState_TRANS, \
    &P_EVENTSET_sendPlantoExecutorState_DOS, \
    P_TRANS_7, \
    NULL, \
    &P_FUNCTION_Anon_8, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_Robot_STATES[] = { P_STATE_Robot_Init, P_STATE_Robot_sendPlantoExecutorState, P_STATE_Robot_WaitRequest };

PRT_VALUE* P_Anon_IMPL_6(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_4 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_4 = NULL;
    PRT_VALUE* PTMP_tmp1_2 = NULL;
    PRT_VALUE* PTMP_tmp2_2 = NULL;
    PRT_VALUE* PTMP_tmp3_1 = NULL;
    PRT_VALUE* PTMP_tmp4_1 = NULL;
    PRT_VALUE* PTMP_tmp5_1 = NULL;
    PRT_VALUE* PTMP_tmp6 = NULL;
    PRT_VALUE* PTMP_tmp7 = NULL;
    PRT_VALUE* P_VAR_P_payload = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_15 = &(PTMP_tmp0_4);
    PrtFreeValue(*P_LVALUE_15);
    *P_LVALUE_15 = PrtCloneValue((p_this->id));
    
    PRT_VALUE** P_LVALUE_16 = &(PTMP_tmp1_2);
    PrtFreeValue(*P_LVALUE_16);
    *P_LVALUE_16 = PrtCloneValue(PrtMkInterface(context, 0, 1, &(PTMP_tmp0_4))->id);
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_6;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_6;
    }
    
    {
        PRT_VALUE** P_LVALUE_17 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_17);
        *P_LVALUE_17 = PTMP_tmp1_2;
        PTMP_tmp1_2 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_18 = &(PTMP_tmp2_2);
    PrtFreeValue(*P_LVALUE_18);
    *P_LVALUE_18 = PrtCloneValue((p_this->id));
    
    PRT_VALUE** P_LVALUE_19 = &(PTMP_tmp3_1);
    PrtFreeValue(*P_LVALUE_19);
    *P_LVALUE_19 = PrtCloneValue(PrtMkInterface(context, 1, 1, &(PTMP_tmp2_2))->id);
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_6;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_6;
    }
    
    {
        PRT_VALUE** P_LVALUE_20 = &(p_this->varValues[2]);
        PrtFreeValue(*P_LVALUE_20);
        *P_LVALUE_20 = PTMP_tmp3_1;
        PTMP_tmp3_1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_21 = &(p_this->varValues[4]);
    PrtFreeValue(*P_LVALUE_21);
    *P_LVALUE_21 = PrtCloneValue(*P_VAR_payload_4);
    
    PRT_VALUE** P_LVALUE_22 = &(PTMP_tmp4_1);
    PrtFreeValue(*P_LVALUE_22);
    *P_LVALUE_22 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_23 = &(PTMP_tmp5_1);
    PrtFreeValue(*P_LVALUE_23);
    *P_LVALUE_23 = PrtCloneValue((&P_EVENT_requestMotionPlan.value));
    
    PRT_VALUE** P_LVALUE_24 = &(PTMP_tmp6);
    PrtFreeValue(*P_LVALUE_24);
    *P_LVALUE_24 = PrtCloneValue(*P_VAR_payload_4);
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp4_1), PTMP_tmp5_1, 1, &(PTMP_tmp6));
    *(&(PTMP_tmp5_1)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_6;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_6;
    }
    
    PRT_UINT32 P_allowedEventIds[] = { 2 };
    PrtFreeValue(P_VAR_P_payload); P_VAR_P_payload = NULL;
    PRT_UINT32 P_eventId = PrtReceiveAsync(1U, P_allowedEventIds, &P_VAR_P_payload);
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_6;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_6;
    }
    switch (P_eventId) {
        case 2: {
            PRT_VALUE** P_VAR_tmp = &P_VAR_P_payload;
                        PRT_VALUE** P_LVALUE_25 = &(p_this->varValues[3]);
            PrtFreeValue(*P_LVALUE_25);
            *P_LVALUE_25 = PrtCloneValue(*P_VAR_tmp);
            
            p_return_7: ;
} break;
        default: {
            PrtAssert(PRT_FALSE, "receive returned unhandled event");
        } break;
    }
    PrtFreeValue(P_VAR_P_payload); P_VAR_P_payload = NULL;
    
    PRT_VALUE** P_LVALUE_26 = &(PTMP_tmp7);
    PrtFreeValue(*P_LVALUE_26);
    *P_LVALUE_26 = PrtCloneValue((&P_EVENT_Success.value));
    
    PrtRaise(p_this, PTMP_tmp7, 0);
    *(&(PTMP_tmp7)) = NULL;
    goto p_return_6;
    
p_return_6: ;
    PrtFreeValue(PTMP_tmp0_4); PTMP_tmp0_4 = NULL;
    PrtFreeValue(PTMP_tmp1_2); PTMP_tmp1_2 = NULL;
    PrtFreeValue(PTMP_tmp2_2); PTMP_tmp2_2 = NULL;
    PrtFreeValue(PTMP_tmp3_1); PTMP_tmp3_1 = NULL;
    PrtFreeValue(PTMP_tmp4_1); PTMP_tmp4_1 = NULL;
    PrtFreeValue(PTMP_tmp5_1); PTMP_tmp5_1 = NULL;
    PrtFreeValue(PTMP_tmp6); PTMP_tmp6 = NULL;
    PrtFreeValue(PTMP_tmp7); PTMP_tmp7 = NULL;
    PrtFreeValue(P_VAR_P_payload); P_VAR_P_payload = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_6 =
{
    NULL,
    &P_Anon_IMPL_6,
    &P_GEND_TYPE_ST3fff
};


PRT_VALUE* P_Anon_IMPL_7(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
p_return_8: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_7 =
{
    NULL,
    &P_Anon_IMPL_7,
    NULL
};


PRT_VALUE* P_Anon_IMPL_8(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_5 = NULL;
    PRT_VALUE* PTMP_tmp1_3 = NULL;
    PRT_VALUE* PTMP_tmp2_3 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_27 = &(PTMP_tmp0_5);
    PrtFreeValue(*P_LVALUE_27);
    *P_LVALUE_27 = PrtCloneValue(p_this->varValues[2]);
    
    PRT_VALUE** P_LVALUE_28 = &(PTMP_tmp1_3);
    PrtFreeValue(*P_LVALUE_28);
    *P_LVALUE_28 = PrtCloneValue((&P_EVENT_executePlan.value));
    
    PRT_VALUE** P_LVALUE_29 = &(PTMP_tmp2_3);
    PrtFreeValue(*P_LVALUE_29);
    *P_LVALUE_29 = PrtCloneValue(p_this->varValues[3]);
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp0_5), PTMP_tmp1_3, 1, &(PTMP_tmp2_3));
    *(&(PTMP_tmp1_3)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_9;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_9;
    }
    
p_return_9: ;
    PrtFreeValue(PTMP_tmp0_5); PTMP_tmp0_5 = NULL;
    PrtFreeValue(PTMP_tmp1_3); PTMP_tmp1_3 = NULL;
    PrtFreeValue(PTMP_tmp2_3); PTMP_tmp2_3 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_8 =
{
    NULL,
    &P_Anon_IMPL_8,
    NULL
};


PRT_FUNDECL* P_Robot_METHODS[] = { &P_FUNCTION_Anon_6, &P_FUNCTION_Anon_7, &P_FUNCTION_Anon_8 };

PRT_EVENTDECL* P_Robot_RECV_INNER_1[] = { &P_EVENT_Success, &P_EVENT_executePlan, &_P_EVENT_HALT_STRUCT, &P_EVENT_receiveMotionPlan, &P_EVENT_requestMotionPlan };
PRT_EVENTSETDECL P_EVENTSET_Robot_RECV_1 =
{
    5U,
    P_Robot_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Robot_SEND_INNER[] = { &P_EVENT_Success, &P_EVENT_executePlan, &_P_EVENT_HALT_STRUCT, &P_EVENT_receiveMotionPlan, &P_EVENT_requestMotionPlan };
PRT_EVENTSETDECL P_EVENTSET_Robot_SEND =
{
    5U,
    P_Robot_SEND_INNER,
    NULL
};

PRT_UINT32 P_Robot_CREATES_ARR[] = { 0, 1 };
PRT_INTERFACESETDECL P_Robot_CREATES = { 2, P_Robot_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_Robot = 
{
    2U,
    "Robot",
    &P_EVENTSET_Robot_RECV_1,
    &P_EVENTSET_Robot_SEND,
    &P_Robot_CREATES,
    5U,
    3U,
    3U,
    4294967295U,
    0U,
    P_Robot_VARS,
    P_Robot_STATES,
    P_Robot_METHODS
};

PRT_VARDECL P_Project_VARS[] = {
    { "robot_target", &P_GEND_TYPE_m },
    { "s", &P_GEND_TYPE_ST3fff }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_3[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_3 =
{
    0U,
    P_Init_DEFERS_INNER_3,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER_3[] = { &P_EVENT_Success };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS_3 =
{
    1U,
    P_Init_TRANS_INNER_3,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER_3[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS_3 =
{
    0U,
    P_Init_DOS_INNER_3,
    NULL
};

PRT_TRANSDECL P_TRANS_8[] =
{
    { 0, &P_EVENT_Success, 1, &_P_NO_OP }
};

#define P_STATE_Project_Init \
{ \
    "Project.Init", \
    1U, \
    0U, \
    &P_EVENTSET_Init_DEFERS_3, \
    &P_EVENTSET_Init_TRANS_3, \
    &P_EVENTSET_Init_DOS_3, \
    P_TRANS_8, \
    NULL, \
    &P_FUNCTION_Anon_9, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_WaitRequest_DEFERS_INNER_3[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitRequest_DEFERS_3 =
{
    0U,
    P_WaitRequest_DEFERS_INNER_3,
    NULL
};

PRT_EVENTDECL* P_WaitRequest_TRANS_INNER_3[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitRequest_TRANS_3 =
{
    0U,
    P_WaitRequest_TRANS_INNER_3,
    NULL
};

PRT_EVENTDECL* P_WaitRequest_DOS_INNER_3[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitRequest_DOS_3 =
{
    0U,
    P_WaitRequest_DOS_INNER_3,
    NULL
};

#define P_STATE_Project_WaitRequest \
{ \
    "Project.WaitRequest", \
    0U, \
    0U, \
    &P_EVENTSET_WaitRequest_DEFERS_3, \
    &P_EVENTSET_WaitRequest_TRANS_3, \
    &P_EVENTSET_WaitRequest_DOS_3, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_10, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_Project_STATES[] = { P_STATE_Project_Init, P_STATE_Project_WaitRequest };

PRT_VALUE* P_Anon_IMPL_9(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_6 = NULL;
    PRT_VALUE* PTMP_tmp1_4 = NULL;
    PRT_VALUE* PTMP_tmp2_4 = NULL;
    PRT_VALUE* PTMP_tmp3_2 = NULL;
    PRT_VALUE* PTMP_tmp4_2 = NULL;
    PRT_VALUE* PTMP_tmp5_2 = NULL;
    PRT_VALUE* PTMP_tmp6_1 = NULL;
    PRT_VALUE* PTMP_tmp7_1 = NULL;
    PRT_VALUE* PTMP_tmp8 = NULL;
    PRT_VALUE* PTMP_tmp9 = NULL;
    PRT_VALUE* PTMP_tmp10 = NULL;
    PRT_VALUE* PTMP_tmp11 = NULL;
    PRT_VALUE* PTMP_tmp12 = NULL;
    PRT_VALUE* PTMP_tmp13 = NULL;
    PRT_VALUE* PTMP_tmp14 = NULL;
    PRT_VALUE* PTMP_tmp15 = NULL;
    PRT_VALUE* PTMP_tmp16 = NULL;
    PRT_VALUE* PTMP_tmp17 = NULL;
    PRT_VALUE* PTMP_tmp18 = NULL;
    PRT_VALUE* PTMP_tmp19 = NULL;
    PRT_VALUE* PTMP_tmp20 = NULL;
    PRT_VALUE* PTMP_tmp21 = NULL;
    PRT_VALUE* PTMP_tmp22 = NULL;
    PRT_VALUE* PTMP_tmp23 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_1 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_INT32_2 = { PRT_VALUE_KIND_INT, { .nt = 2 } };
    PRT_VALUE P_LIT_INT32_3 = { PRT_VALUE_KIND_INT, { .nt = 3 } };
    PRT_VALUE P_LIT_INT32_4 = { PRT_VALUE_KIND_INT, { .nt = 4 } };
    PRT_VALUE P_LIT_DOUBLE = { PRT_VALUE_KIND_FLOAT, { .ft = 0 } };
    PRT_VALUE P_LIT_DOUBLE_1 = { PRT_VALUE_KIND_FLOAT, { .ft = 2 } };
    PRT_VALUE** P_LVALUE_30 = &(PTMP_tmp0_6);
    PrtFreeValue(*P_LVALUE_30);
    *P_LVALUE_30 = PrtMkDefaultValue(&P_GEND_TYPE_ST3fff);
    
    {
        PRT_VALUE** P_LVALUE_31 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_31);
        *P_LVALUE_31 = PTMP_tmp0_6;
        PTMP_tmp0_6 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_32 = &(PTMP_tmp1_4);
    PrtFreeValue(*P_LVALUE_32);
    *P_LVALUE_32 = PrtCloneValue((&P_LIT_DOUBLE));
    
    PRT_VALUE** P_LVALUE_33 = &(PTMP_tmp2_4);
    PrtFreeValue(*P_LVALUE_33);
    *P_LVALUE_33 = PrtCloneValue((&P_LIT_DOUBLE));
    
    PRT_VALUE** P_LVALUE_34 = &(PTMP_tmp3_2);
    PrtFreeValue(*P_LVALUE_34);
    *P_LVALUE_34 = PrtCloneValue((&P_LIT_DOUBLE));
    
    PRT_VALUE** P_LVALUE_35 = &(PTMP_tmp4_2);
    PrtFreeValue(*P_LVALUE_35);
    *P_LVALUE_35 = (PrtMkTuple(&P_GEND_TYPE_T3fff, &(PTMP_tmp1_4), &(PTMP_tmp2_4), &(PTMP_tmp3_2)));
    
    PrtSeqInsertEx(p_this->varValues[1], (&P_LIT_INT32), PTMP_tmp4_2, PRT_FALSE);
    *(&(PTMP_tmp4_2)) = NULL;
    
    PRT_VALUE** P_LVALUE_36 = &(PTMP_tmp5_2);
    PrtFreeValue(*P_LVALUE_36);
    *P_LVALUE_36 = PrtCloneValue((&P_LIT_DOUBLE_1));
    
    PRT_VALUE** P_LVALUE_37 = &(PTMP_tmp6_1);
    PrtFreeValue(*P_LVALUE_37);
    *P_LVALUE_37 = PrtCloneValue((&P_LIT_DOUBLE));
    
    PRT_VALUE** P_LVALUE_38 = &(PTMP_tmp7_1);
    PrtFreeValue(*P_LVALUE_38);
    *P_LVALUE_38 = PrtCloneValue((&P_LIT_DOUBLE));
    
    PRT_VALUE** P_LVALUE_39 = &(PTMP_tmp8);
    PrtFreeValue(*P_LVALUE_39);
    *P_LVALUE_39 = (PrtMkTuple(&P_GEND_TYPE_T3fff, &(PTMP_tmp5_2), &(PTMP_tmp6_1), &(PTMP_tmp7_1)));
    
    PrtSeqInsertEx(p_this->varValues[1], (&P_LIT_INT32_1), PTMP_tmp8, PRT_FALSE);
    *(&(PTMP_tmp8)) = NULL;
    
    PRT_VALUE** P_LVALUE_40 = &(PTMP_tmp9);
    PrtFreeValue(*P_LVALUE_40);
    *P_LVALUE_40 = PrtCloneValue((&P_LIT_DOUBLE_1));
    
    PRT_VALUE** P_LVALUE_41 = &(PTMP_tmp10);
    PrtFreeValue(*P_LVALUE_41);
    *P_LVALUE_41 = PrtCloneValue((&P_LIT_DOUBLE_1));
    
    PRT_VALUE** P_LVALUE_42 = &(PTMP_tmp11);
    PrtFreeValue(*P_LVALUE_42);
    *P_LVALUE_42 = PrtCloneValue((&P_LIT_DOUBLE));
    
    PRT_VALUE** P_LVALUE_43 = &(PTMP_tmp12);
    PrtFreeValue(*P_LVALUE_43);
    *P_LVALUE_43 = (PrtMkTuple(&P_GEND_TYPE_T3fff, &(PTMP_tmp9), &(PTMP_tmp10), &(PTMP_tmp11)));
    
    PrtSeqInsertEx(p_this->varValues[1], (&P_LIT_INT32_2), PTMP_tmp12, PRT_FALSE);
    *(&(PTMP_tmp12)) = NULL;
    
    PRT_VALUE** P_LVALUE_44 = &(PTMP_tmp13);
    PrtFreeValue(*P_LVALUE_44);
    *P_LVALUE_44 = PrtCloneValue((&P_LIT_DOUBLE));
    
    PRT_VALUE** P_LVALUE_45 = &(PTMP_tmp14);
    PrtFreeValue(*P_LVALUE_45);
    *P_LVALUE_45 = PrtCloneValue((&P_LIT_DOUBLE_1));
    
    PRT_VALUE** P_LVALUE_46 = &(PTMP_tmp15);
    PrtFreeValue(*P_LVALUE_46);
    *P_LVALUE_46 = PrtCloneValue((&P_LIT_DOUBLE));
    
    PRT_VALUE** P_LVALUE_47 = &(PTMP_tmp16);
    PrtFreeValue(*P_LVALUE_47);
    *P_LVALUE_47 = (PrtMkTuple(&P_GEND_TYPE_T3fff, &(PTMP_tmp13), &(PTMP_tmp14), &(PTMP_tmp15)));
    
    PrtSeqInsertEx(p_this->varValues[1], (&P_LIT_INT32_3), PTMP_tmp16, PRT_FALSE);
    *(&(PTMP_tmp16)) = NULL;
    
    PRT_VALUE** P_LVALUE_48 = &(PTMP_tmp17);
    PrtFreeValue(*P_LVALUE_48);
    *P_LVALUE_48 = PrtCloneValue((&P_LIT_DOUBLE));
    
    PRT_VALUE** P_LVALUE_49 = &(PTMP_tmp18);
    PrtFreeValue(*P_LVALUE_49);
    *P_LVALUE_49 = PrtCloneValue((&P_LIT_DOUBLE));
    
    PRT_VALUE** P_LVALUE_50 = &(PTMP_tmp19);
    PrtFreeValue(*P_LVALUE_50);
    *P_LVALUE_50 = PrtCloneValue((&P_LIT_DOUBLE));
    
    PRT_VALUE** P_LVALUE_51 = &(PTMP_tmp20);
    PrtFreeValue(*P_LVALUE_51);
    *P_LVALUE_51 = (PrtMkTuple(&P_GEND_TYPE_T3fff, &(PTMP_tmp17), &(PTMP_tmp18), &(PTMP_tmp19)));
    
    PrtSeqInsertEx(p_this->varValues[1], (&P_LIT_INT32_4), PTMP_tmp20, PRT_FALSE);
    *(&(PTMP_tmp20)) = NULL;
    
    PRT_VALUE** P_LVALUE_52 = &(PTMP_tmp21);
    PrtFreeValue(*P_LVALUE_52);
    *P_LVALUE_52 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_53 = &(PTMP_tmp22);
    PrtFreeValue(*P_LVALUE_53);
    *P_LVALUE_53 = PrtCloneValue(PrtMkInterface(context, 2, 1, &(PTMP_tmp21))->id);
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_10;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_10;
    }
    
    {
        PRT_VALUE** P_LVALUE_54 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_54);
        *P_LVALUE_54 = PTMP_tmp22;
        PTMP_tmp22 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_55 = &(PTMP_tmp23);
    PrtFreeValue(*P_LVALUE_55);
    *P_LVALUE_55 = PrtCloneValue((&P_EVENT_Success.value));
    
    PrtRaise(p_this, PTMP_tmp23, 0);
    *(&(PTMP_tmp23)) = NULL;
    goto p_return_10;
    
p_return_10: ;
    PrtFreeValue(PTMP_tmp0_6); PTMP_tmp0_6 = NULL;
    PrtFreeValue(PTMP_tmp1_4); PTMP_tmp1_4 = NULL;
    PrtFreeValue(PTMP_tmp2_4); PTMP_tmp2_4 = NULL;
    PrtFreeValue(PTMP_tmp3_2); PTMP_tmp3_2 = NULL;
    PrtFreeValue(PTMP_tmp4_2); PTMP_tmp4_2 = NULL;
    PrtFreeValue(PTMP_tmp5_2); PTMP_tmp5_2 = NULL;
    PrtFreeValue(PTMP_tmp6_1); PTMP_tmp6_1 = NULL;
    PrtFreeValue(PTMP_tmp7_1); PTMP_tmp7_1 = NULL;
    PrtFreeValue(PTMP_tmp8); PTMP_tmp8 = NULL;
    PrtFreeValue(PTMP_tmp9); PTMP_tmp9 = NULL;
    PrtFreeValue(PTMP_tmp10); PTMP_tmp10 = NULL;
    PrtFreeValue(PTMP_tmp11); PTMP_tmp11 = NULL;
    PrtFreeValue(PTMP_tmp12); PTMP_tmp12 = NULL;
    PrtFreeValue(PTMP_tmp13); PTMP_tmp13 = NULL;
    PrtFreeValue(PTMP_tmp14); PTMP_tmp14 = NULL;
    PrtFreeValue(PTMP_tmp15); PTMP_tmp15 = NULL;
    PrtFreeValue(PTMP_tmp16); PTMP_tmp16 = NULL;
    PrtFreeValue(PTMP_tmp17); PTMP_tmp17 = NULL;
    PrtFreeValue(PTMP_tmp18); PTMP_tmp18 = NULL;
    PrtFreeValue(PTMP_tmp19); PTMP_tmp19 = NULL;
    PrtFreeValue(PTMP_tmp20); PTMP_tmp20 = NULL;
    PrtFreeValue(PTMP_tmp21); PTMP_tmp21 = NULL;
    PrtFreeValue(PTMP_tmp22); PTMP_tmp22 = NULL;
    PrtFreeValue(PTMP_tmp23); PTMP_tmp23 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_9 =
{
    NULL,
    &P_Anon_IMPL_9,
    NULL
};


PRT_VALUE* P_Anon_IMPL_10(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
p_return_11: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_10 =
{
    NULL,
    &P_Anon_IMPL_10,
    NULL
};


PRT_FUNDECL* P_Project_METHODS[] = { &P_FUNCTION_Anon_9, &P_FUNCTION_Anon_10 };

PRT_EVENTDECL* P_Project_RECV_INNER_1[] = { &P_EVENT_Success, &P_EVENT_executePlan, &_P_EVENT_HALT_STRUCT, &P_EVENT_receiveMotionPlan, &P_EVENT_requestMotionPlan };
PRT_EVENTSETDECL P_EVENTSET_Project_RECV_1 =
{
    5U,
    P_Project_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Project_SEND_INNER[] = { &P_EVENT_Success, &P_EVENT_executePlan, &_P_EVENT_HALT_STRUCT, &P_EVENT_receiveMotionPlan, &P_EVENT_requestMotionPlan };
PRT_EVENTSETDECL P_EVENTSET_Project_SEND =
{
    5U,
    P_Project_SEND_INNER,
    NULL
};

PRT_UINT32 P_Project_CREATES_ARR[] = { 2 };
PRT_INTERFACESETDECL P_Project_CREATES = { 1, P_Project_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_Project = 
{
    3U,
    "Project",
    &P_EVENTSET_Project_RECV_1,
    &P_EVENTSET_Project_SEND,
    &P_Project_CREATES,
    2U,
    2U,
    2U,
    4294967295U,
    0U,
    P_Project_VARS,
    P_Project_STATES,
    P_Project_METHODS
};

PRT_EVENTDECL* P_ALL_EVENTS[] = { &_P_EVENT_NULL_STRUCT, &_P_EVENT_HALT_STRUCT, &P_EVENT_receiveMotionPlan, &P_EVENT_Success, &P_EVENT_executePlan, &P_EVENT_requestMotionPlan };
PRT_MACHINEDECL* P_ALL_MACHINES[] = { &P_MACHINE_MotionPlanner, &P_MACHINE_PlanExecutor, &P_MACHINE_Robot, &P_MACHINE_Project };
PRT_INTERFACEDECL* P_ALL_INTERFACES[] = { &P_I_MotionPlanner, &P_I_PlanExecutor, &P_I_Robot, &P_I_Project };
PRT_FUNDECL* P_ALL_FUNCTIONS[] = { NULL };
PRT_FOREIGNTYPEDECL* P_ALL_FOREIGN_TYPES[] = { NULL };
int P_DefaultImpl_LME_0[] = { -1,-1,-1,-1 };
int P_DefaultImpl_LME_1[] = { -1,-1,-1,-1 };
int P_DefaultImpl_LME_2[] = { 0,1,-1,-1 };
int P_DefaultImpl_LME_3[] = { -1,-1,2,-1 };
int* P_DefaultImpl_LINKMAP[] = { P_DefaultImpl_LME_0, P_DefaultImpl_LME_1, P_DefaultImpl_LME_2, P_DefaultImpl_LME_3 };
int P_DefaultImpl_DEFMAP[] = { 0,1,2,3 };
PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl = {
    6U,
    4U,
    4U,
    0U,
    0U,
    P_ALL_EVENTS,
    P_ALL_MACHINES,
    P_ALL_INTERFACES,
    P_ALL_FUNCTIONS,
    P_ALL_FOREIGN_TYPES,
    P_DefaultImpl_LINKMAP,
    P_DefaultImpl_DEFMAP
};