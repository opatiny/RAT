#define THR_ACTION2 1


NIL_WORKING_AREA(waThreadAction2, 100);
NIL_THREAD(ThreadAction2, arg) {


  SoftPWMBegin();
  int action2Step = 0;

  while (true) {

    if (getParameter(PARAM_POWER) & 1<<BIT_ENABLE_PUMP) {
      SoftPWMSet(IO1, getParameter(PARAM_PUMP));
    } else {
      SoftPWMSet(IO1, 0);
    }
    
    nilThdSleepMilliseconds(40);

    action2Step++;
    setParameter(PARAM_ACTION2, action2Step);

  }
}














