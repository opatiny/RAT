#define THR_ACTION2 1

NIL_WORKING_AREA(waThreadAction2, 200);
NIL_THREAD(ThreadAction2, arg) {

  SoftPWMBegin();
  int action2Step = 0;
  
  while (true) {
    if (bitRead(getParameter(PARAM_POWER),BIT_ENABLE_PUMP)==1) {
      SoftPWMSet(IO1, getParameter(PARAM_PUMP));
     // digitalWrite(IO1, HIGH);
    } else {
      SoftPWMSet(IO1, 0);
    }

    nilThdSleepMilliseconds(40);

    action2Step++;
    setParameter(PARAM_ACTION2, action2Step);
  }
}














