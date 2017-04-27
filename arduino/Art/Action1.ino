#define THR_ACTION1 1

#include <SoftPWM.h>

NIL_WORKING_AREA(waThreadAction1, 100);
NIL_THREAD(ThreadAction1, arg) {


  int counter = 0;

  // Number of colors used for animating, higher = smoother and slower animation)



  unsigned int action1Step = 0;

  while (true) {
    int numColors = getParameter(PARAM_NB_COLORS);;

    if (numColors > 1) {

      float colorNumber = counter > numColors ? counter - numColors : counter;
      float saturation = float(getParameter(PARAM_COLOR_SATURATION)) / 1000; // Between 0 and 1 (0 = gray, 1 = full color)
      float brightness = float(getParameter(PARAM_COLOR_BRIGHTNESS)) / 1000; // Between 0 and 1 (0 = dark, 1 is full brightness)
      float hue = (colorNumber / float(numColors)) * 360; // Number between 0 and 360
      long color = HSBtoRGB(hue, saturation, brightness);

      // Get the red, blue and green parts from generated color
      int red = color >> 16 & 255;
      int green = color >> 8 & 255;
      int blue = color & 255;

      counter = (counter + 1) % (numColors * 2);

      setParameter(PARAM_RED, red);
      setParameter(PARAM_GREEN, green);
      setParameter(PARAM_BLUE, blue);
    }

    action1Step++;
    if (action1Step == 256) action1Step = 0;
    setParameter(PARAM_ACTION1, action1Step);
    nilThdSleepMilliseconds(40);
  }
}





long HSBtoRGB(float _hue, float _sat, float _brightness) {
  float red = 0.0;
  float green = 0.0;
  float blue = 0.0;

  if (_sat == 0.0) {
    red = _brightness;
    green = _brightness;
    blue = _brightness;
  } else {
    if (_hue == 360.0) {
      _hue = 0;
    }

    int slice = _hue / 60.0;
    float hue_frac = (_hue / 60.0) - slice;

    float aa = _brightness * (1.0 - _sat);
    float bb = _brightness * (1.0 - _sat * hue_frac);
    float cc = _brightness * (1.0 - _sat * (1.0 - hue_frac));

    switch (slice) {
      case 0:
        red = _brightness;
        green = cc;
        blue = aa;
        break;
      case 1:
        red = bb;
        green = _brightness;
        blue = aa;
        break;
      case 2:
        red = aa;
        green = _brightness;
        blue = cc;
        break;
      case 3:
        red = aa;
        green = bb;
        blue = _brightness;
        break;
      case 4:
        red = cc;
        green = aa;
        blue = _brightness;
        break;
      case 5:
        red = _brightness;
        green = aa;
        blue = bb;
        break;
      default:
        red = 0.0;
        green = 0.0;
        blue = 0.0;
        break;
    }
  }

  long ired = red * 255.0;
  long igreen = green * 255.0;
  long iblue = blue * 255.0;

  return long((ired << 16) | (igreen << 8) | (iblue));
}

