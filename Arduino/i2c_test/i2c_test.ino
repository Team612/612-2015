#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Wire.begin(2);
  Wire.onRequest(requestEvent);
  Serial.begin(9600);
}

void loop() {
  int input = Serial.read();
  Serial.println(input);
  delay(100);
}

void requestEvent() {
  /*char* message[5]; //Hello
  message[0] = "H";
  message[1] = "E";
  message[2] = "L";
  message[3] = "L";
  message[4] = "0";
  for(int x; x<5; x){
    Wire.write(message[x]);
  }*/
  Wire.write("hello");
}

