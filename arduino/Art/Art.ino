#include <NilRTOS.h>
#include <avr/wdt.h>
#include <Time.h>


#define OUT1    6
#define OUT2    10   // there was a bug in first version and was set to 8 like IO5
#define OUT3    12
#define OUT4    14
#define OUT5    15
#define IO1     21
#define IO2     20
#define IO3     19
#define IO4     22
#define IO5     8
#define RED1    9
#define GREEN1  5
#define BLUE1   11
#define RED2    16
#define GREEN2  18
#define BLUE2   23
byte IO[]={IO1, IO2, IO3, IO4, IO5};
byte OUT[]={OUT1, OUT2, OUT3, OUT4, OUT5};


#define THR_MONITORING     13  // will also take care of the watch dog


void setup() {
  Serial.begin(9600);
  setupParameters();

  nilSysBegin();
}


void loop() {
}











