// #define THR_ACTION4 1


NIL_WORKING_AREA(waThreadAction4, 0);
NIL_THREAD(ThreadAction4, arg) {

  // Initialisation bloc




  int action4Step = 0;

  while (TRUE) {



    action4Step++;

    setParameter(PARAM_ACTION4, action4Step);
  }
}






