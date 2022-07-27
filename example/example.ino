#include <hello.h>

#define BAUD_RATE  9600

void setup() {
   Serial.begin(BAUD_RATE);
  
}

void loop() {
  // put your main code here, to run repeatedly:
   int result = add(1, 1);
   Serial.println(result);
   delay(1000);
}
