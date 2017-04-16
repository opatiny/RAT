#define THR_ACTION2 1


NIL_WORKING_AREA(waThreadAction2, 100);
NIL_THREAD(ThreadAction2, arg) {


  SoftPWMBegin();
  int action2Step = 0;

  while (true) {

    SoftPWMSet(IO1, getParameter(PARAM_PUMP));

    nilThdSleepMilliseconds(40);

    action2Step++;
    setParameter(PARAM_ACTION2, action2Step);

  }
}














