/*
 * Note, in order to get this to work, you need to change all of the
 * Serial1 referenced in PixyUART.h to Serial references. Pixy wanted
 * us to still have the ability to print, unfortunately, we have but
 * dos Unos.
 */
  
//Woot woot
#include <SPI.h>  
#include <Pixy.h>
#include <Wire.h>
#include "PixyUART.h" //Because pointed brackets are overrated

//#define DEBUG

// This is the main Pixy object 
Pixy pixy;
uint16_t cam1Buffer[3]; //The buffers hold the info in the order: width, height, x

/*
 * So debug is weird. Essentially when we are using the serial for pixy,
 * we can't use it for the printing of things, so debug pretty much completely
 * gets rid of the other camera anywhere in the code. 
 */
#ifndef DEBUG
PixyUART pixyuart;
uint16_t cam2Buffer[3];
#endif

uint8_t currentSendingCam = 0; //0: left, 1: right
boolean detected = false; //whether or not we found a crate

uint8_t CRATE_SIGNATURE = 1; //Pretty much always gonna be one unless some idiot (most likely me) sets it to something else

void process (Block* blocks, uint32_t, uint16_t*); //Processes the information from one of the cams, taking an array of detected blocks


void setup()
{
  Wire.begin(2);                // join i2c bus with address #2 <-- what that said
  Wire.onRequest(requestEvent); 
#ifdef DEBUG
  Serial.begin(9600); //only start serial on 9600 baud if we are using it to print
  Serial.print("Starting...\n");
#endif
  
//Pixy is too cool for constructors
#ifndef DEBUG
  pixyuart.init();
#endif  
  
  pixy.init();
}

//Processes output from both cams
void loop()
{ 
  unsigned long beginTime = millis();
  
  process(pixy.blocks, pixy.getBlocks(), cam1Buffer);
  
#ifndef DEBUG
  process(pixyuart.blocks, pixyuart.getBlocks(), cam2Buffer);
#endif
  
  //Times it out so we get a somewhat-constant time in-between refreshes
  unsigned long endTime = millis();
  unsigned long diff = beginTime - endTime; //How much time it took to process
  
  //Mmmm... delicious ternary operators, yum yum
  delay(diff > 33? 0: 33 - diff);
}

//As mentioned before, processes stuff. Nuff' said.
void process(Block* blocks, uint32_t amount, uint16_t* buffer) 
{
  int j; //j is so cool that he doesn't get initialized inside his for loop
  
#ifdef DEBUG
  char buf[32]; //only create buffer if we need it to print
#endif
  
  boolean tempDetected = false; //things only get changed at the end in case the roborio calls in the middle of the loop exec
  
  // If there are detected blocks, do stuff!
  if (amount > 0)
  { 
    //Same as with detected
    uint16_t tempWidth = 0;
    uint16_t tempHeight = 0;
    uint16_t tempX = 0;
    for (j=0; j<amount; j++)
    {
      //Yo bro, I heard you liked if statements, so I put an if statement inside your if statement
      if (blocks[j].signature == CRATE_SIGNATURE) 
      {
        //Essentially, we grab the largest one we can find, and hope it's the crate, if it's not then we're S.O.L.
        if ((blocks[j].width * blocks[j].height) > (tempWidth * tempHeight)) 
        {
          tempWidth = blocks[j].width;
          tempHeight = blocks[j].height;
          tempX = blocks[j].x;
          tempDetected = true;
        }
      }  
    }
    
    //More stuff
    if (!detected) 
    {
#ifdef DEBUG
      //Debugging stuff
      sprintf(buf, "Error: no blocks found of signature %u!\n", CRATE_SIGNATURE );
      Serial.print(buf);
      Serial.print("Check to see if the signature is set correctly.\n");
#endif
    } 
    else 
    {
      //Setting stuff
      buffer[0] = tempWidth;
      buffer[1] = tempHeight;
      buffer[2] = tempX;
    }
    
  } 
  else 
  {
#ifdef DEBUG
    //Bad error-y stuff
    Serial.print("Error: No blocks detected!");
#endif
  }
 
  //More setting stuff
  detected = tempDetected;
}

//Happens when the roborio asks for data
void requestEvent()
{
  //data and buffer, yup
  uint8_t data[7]; //data to send
  uint16_t buffer[3]; //buffer (either cam1 or cam2) being processed
  
  data[0] = currentSendingCam; //Sends over the current camera being sent in first byte
  
  if (!detected) 
  {
    //If there's no crate, we switch to the currentcam + 2 (i.e. 2 for c0 not working, 3 for c1 not working)
    data[0] = currentSendingCam + 2; 
  }
  
  if (currentSendingCam == 0) 
  {
    memcpy(buffer, cam1Buffer, sizeof(cam1Buffer)); //holy crap, this copy thingy actually came in handy
  } 
  
#ifndef DEBUG
  else if (currentSendingCam == 1)
  {
    memcpy(buffer, cam2Buffer, sizeof(cam2Buffer));
  }
#endif
  
  
  for (int i = 0; i < 3; i++) 
  {
    int di = i * 2; //di = double i, see what I did there?
    //Uses bitshift to translate 16 bits into 2 sets of 8 bits
    data[di + 1] = data[di + 1] | buffer[i] >> 8; 
    data[di + 2] = data[di + 2] | buffer[i];
  }
  
  //finally we write to the f***ing wire
  Wire.write(data, 7);
}

//TODO: Erase all comments and add helpful ones that weren't made at 11:00
