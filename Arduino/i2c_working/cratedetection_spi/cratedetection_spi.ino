/*
 * So this is code to get 2 pixies running over just SPI.
 * The code uses SS to select each pixy as needed,
 * and to grab information from the selected pixy. I am not
 * entirely sure that this works and, since it requires quite
 * a bit of wiring to get working, was unable to test it.
 * Using the pixy over UART rather than SPI will provide a
 * very large decrease in speed  and it's important that this 
 * code works. If need be, we can fall back to UART, but
 * with it we lose the ability to print to the serial monitor.
 * The huge issue with this method is the wiring since we cannot
 * use the wire that came with the pixy, as it is not compatible
 * with slave-select and blocks the slave select port. Currently
 * the setup is extremely jank, with wires (that are all pretty
 * much the same colors due to limited resources) going in all
 * directions and of varying lengths. In order to get this working
 * for competition, we need to actually organize the wiring , 
 * something that requires actually having the correct wires.
 */
  
//Woot woot
#include <SPI.h>  
#include <Pixy.h>
#include <Wire.h>

//BEGIN VARIABLES -----------------------------------------------

// This is the main Pixy object 
Pixy pixy; //Need to do testing to check if I need multiple objects 

uint16_t cam0Buffer[3]; //The buffers hold the info in the order: width, height, x
uint16_t cam1Buffer[3];

uint8_t currentSendingCam = 0; //0: left, 1: right
boolean detected = false; //whether or not we found a crate

//END VARIABLES --------------------------------------------------
//BEGIN CONSTANTS ------------------------------------------------

//Slave select channels
const uint32_t SS0 = 7; //Left camera
const uint32_t SS1 = 8; //Right camera

const uint8_t CRATE_SIGNATURE = 1; //Pretty much always gonna be one unless some idiot (most likely me) sets it to something else
const unsigned long WAIT_TIME = 33; //How long we wait in-between pinging the arduino (in millis)

//END CONSTANTS --------------------------------------------------
//BEGIN PROTYPES -------------------------------------------------

void process(Block* blocks, uint32_t, uint16_t*); //Processes the information from one of the cams, taking an array of detected blocks
void select(uint8_t camera); //Used to select the slave device over SS
//To talk to a slave, it's signal needs to be LOW while the others are HIGH

//END PROTOTYPES -------------------------------------------------

void setup()
{
  Wire.begin(2);                // join i2c bus with address #2 
  Wire.onRequest(requestEvent); 
  
  //Setup slaveselects to output
  pinMode(SS0, OUTPUT);
  pinMode(SS0, OUTPUT);
  
  Serial.begin(9600);
  Serial.print("Starting...\n");
  
  pixy.init();
}

//Processes output from both cams
void loop()
{ 
  unsigned long beginTime = millis();
  
  select(0);
  process(pixy.blocks, pixy.getBlocks(), cam0Buffer);
  select(1);
  process(pixy.blocks, pixy.getBlocks(), cam1Buffer);
  
  //Times it out so we get a somewhat-constant time in-between refreshes
  unsigned long endTime = millis();
  unsigned long diff = endTime - beginTime; //How much time it took to process
  
  //Mmmm... delicious ternary operators, yum yum
  delay(diff > WAIT_TIME? 0: WAIT_TIME - diff);
}

//As mentioned before, processes stuff. Nuff' said.
void process(Block* blocks, uint32_t amount, uint16_t* buffer) 
{
  char buf[32]; //only create buffer if we need it to print
  
  boolean tempDetected = false; //things only get changed at the end in case the roborio calls in the middle of the loop exec
  
  // If there are detected blocks, do stuff!
  if (amount > 0)
  { 
    //Same as with detected, only temps until the end
    uint16_t tempWidth = 0;
    uint16_t tempHeight = 0;
    uint16_t tempX = 0;
    
    for (int j=0; j<amount; j++)
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
    if (!tempDetected) 
    {
      //Debugging stuff
      sprintf(buf, "Error: no blocks found of signature %u!\n", CRATE_SIGNATURE );
      Serial.print(buf);
      Serial.print("Check to see if the signature is set correctly.\n");
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
    //Bad error-y stuff
    Serial.print("Error: No blocks detected!");
  }
 
  //More setting stuff
  detected = tempDetected;
}

void select(uint8_t camera) 
{
  if (camera == 0) 
  {
    digitalWrite(SS1, HIGH);
    digitalWrite(SS0, LOW);
  }
  else if (camera == 1)
  {
    digitalWrite(SS0, HIGH);
    digitalWrite(SS1, LOW);
  }
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
    memcpy(buffer, cam0Buffer, sizeof(cam1Buffer)); //holy crap, this copy thingy actually came in handy
  } 
  else if (currentSendingCam == 1)
  {
    memcpy(buffer, cam1Buffer, sizeof(cam1Buffer));
  }
  
  
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
