
#include "PinChangeInterrupt.h"

// Choose a valid PinChangeInterrupt pin of your Arduino board
#define pinBlink 8

byte MONITORING = 13;
byte monitValue=LOW;

long unsigned timeLast = 0;
boolean highBit = true;
boolean raising = true;

int unsigned irCode = 0;
int unsigned newIrCode = 0;
int currentBit = 0;

void setup() {
  // set pin to input with a pullup, led to output
  pinMode(pinBlink, INPUT_PULLUP);

  Serial.begin(9600);


  // Attach the new PinChangeInterrupt and enable event function below
  attachPCINT(digitalPinToPCINT(pinBlink), irInterrupt, CHANGE);
}

void irInterrupt() {
  long unsigned timeCurrent = micros();

  monitValue = ! monitValue;
  digitalWrite(MONITORING, monitValue);



  if (timeCurrent - timeLast > 2000 || timeCurrent < timeLast) {
    timeLast = timeCurrent;
    currentBit = 0;
    newIrCode = 0;
    highBit = true;
    raising = true;
  }
  else {
    if (timeCurrent - timeLast < 1200) {
      highBit = !highBit;
    }
    raising = !raising;
    timeLast = timeCurrent;
    if (highBit) {
      if (raising) {
        bitSet(newIrCode, currentBit);
      }
      else {
        bitClear(newIrCode, currentBit);
      }
      currentBit++;
      if (currentBit == 13) {
        if (irCode != newIrCode) {
          irCode = newIrCode;
          eventIR(irCode);
        }
      }
    }
  }
};

void eventIR(int irCode) {
  Serial.print(irCode);
  irCode=irCode>>7;
Serial.print(" ");
Serial.println(irCode);
  
}

void loop() {
  // Nothing to do here
}
