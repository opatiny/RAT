#define THR_ACTION3 1

NIL_WORKING_AREA(waThreadAction3, 100);
NIL_THREAD(ThreadAction3, arg) {

  pinMode(RED1, OUTPUT);
  pinMode(GREEN1, OUTPUT);
  pinMode(BLUE1, OUTPUT);

  int action3Step = 0;

  while (TRUE) {

    if (getParameter(PARAM_POWER) & 1 << BIT_ENABLE_LIGHT) {
      switch (getParameter(PARAM_FIXED_COLOR)) {
        case 0:
          analogWrite(RED1, getParameter(PARAM_RED));
          analogWrite(GREEN1, getParameter(PARAM_GREEN));
          analogWrite(BLUE1, getParameter(PARAM_BLUE));
          break;
        case 1:
          break;
        case 2:
          analogWrite(RED1, 255);
          analogWrite(GREEN1, 0);
          analogWrite(BLUE1, 0);
          break;
        case 3:
          analogWrite(RED1, 0);
          analogWrite(GREEN1, 255);
          analogWrite(BLUE1, 0);
          break;
        case 4:
          analogWrite(RED1, 0);
          analogWrite(GREEN1, 0);
          analogWrite(BLUE1, 255);
          break;
        case 5:
          analogWrite(RED1, 255);
          analogWrite(GREEN1, 0);
          analogWrite(BLUE1, 255);
          break;
        case 6:
          analogWrite(RED1, 0);
          analogWrite(GREEN1, 0);
          analogWrite(BLUE1, 0);
          break;
      }
    } else {
      analogWrite(RED1, 0);
      analogWrite(GREEN1, 0);
      analogWrite(BLUE1, 0);
    }

    action3Step++;
    setParameter(PARAM_ACTION3, action3Step);

    nilThdSleepMilliseconds(10);
  }

}

