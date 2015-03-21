#include <Pixy.h>
#include <PixyI2C.h>

#include <SPI.h>
#include <Wire.h>

Pixy pixy;

void setup()
{
  //Serial.begin(9600);
  pixy.init();
  Wire.begin(2);
}

void loop()
{
  //byte ar = findAspectRatio(pixy.blocks[0].width, pixy.blocks[0].height);
  Wire.write((byte) findAspectRatio(pixy.blocks[0].width, pixy.blocks[0].height));
  Wire.endTransmission();
  delay(100);
}

float findAspectRatio(int width, int height)
{
  return width/height;
}

