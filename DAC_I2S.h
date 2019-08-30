/*
Filename: DAC_I2S.h
Project: for digital-to-analog converters
Interface: I2S
This firmware operates with any digital-to-analog converters
I2S input format: time multiplexed, two's complement, TTL.
DAC_I2S_DATA - transmission of data input from microcontroller to digital-to-analog converter at velocity of frequency at 9,2Mb/sec
DAC_I2S_WS -  transmission of word-select input from microcontroller to digital-to-analog at frequency at 1kHz-192kHz
DAC_I2S_BCK -  transmission of  bit-clock frequency input from microcontroller to digital-to-analog at bit-clock frequency at 9,2MHz
Notes to the characteristics:
1. Measured at IAOL = 0 mA and IAOR = 0 mA (code 8000H) and Ibias = 0 mA.
2. Vripple = 1% of supply voltage and fripple = 100 Hz.
3. Measured with 1 kHz sinewave generated at a sampling rate of 192 kHz.
4. Measured with 1 kHz full scale sinewave generated at a sampling rate of 192 kHz.
5. At code 0000H.
6. At this point tHD; DAT = 0 ns, this value has been fixed on 2 ns due to tolerances.
 */

#ifndef DAC_I2S_H //
#define DAC_I2S_H //

#include<Arduino.h> //

/*It operates with the left canal*/
#define LEFT_OUTPUT_LATCH //
#define LEFT_BIT_SWITCHES //
#define LEFT_INPUT_LATCH //
#define LEFT_5_BIT_PASSIVE_DIVIDER //
#define LEFT_11_BIT_PASSIVE_DIVIDER //
#define LEFT_CURRENT_SOURCE //

//It operates with the right canal
#define RIGHT_OUTPUT_LATCH //
#define RIGHT_BIT_SWITCHES //
#define RIGHT_INPUT_LATCH //
#define RIGHT_5_BIT_PASSIVE_DIVIDER //
#define RIGHT_11_BIT_PASSIVE_DIVIDER //
#define RIGHT_CURRENT_SOURCE //

#define ADDRESS_POINTER //

#define DAC_I2S_BEGIN 0x01
#define DAC_I2S_END 0xFF
#define DAC_I2S_TRANSACTION 0x01
#define DAC_I2S_INITIALIZE 0x02
#define DAC_I2S_CONVERT 0x04
#define DAC_I2S_MAX_VOLUME 0x11
#define DAC_I2S_MIN_VOLUME 0x12
#define DAC_I2S_LEFT_CHANNEL 0x13
#define DAC_I2S_RIGHT_CHANNEL 0x14
#define DAC_I2S_SET_DATA_INPUT 0x18
#define DAC_I2S_SET_FREQUENCY_MAX_WORD_SELLECT_INPUT 0x30
#define DAC_I2S_SET_FREQUENCY_MIN_WORD_SELLECT_INPUT 0x31
#define DAC_I2S_SET_NORMAL_FREQUENCY_BIT_CLOCK_INPUT 0x32


/*Digital input pins of the digital-to-analog converter*/
#define IO_MCU_BCK OUTPUT
#define IO_MCU_WS OUTPUT
#define IO_MCU_DATA OUTPUT

uint16_t PROCESS_DAC_I2S_BCK;
uint16_t PROCESS_DAC_I2S_WS;
uint16_t PROCESS_DAC_I2S_DATA;




class TDA1543A{

static TDA1543A *SYS_Instance;

int _Busy;
int _CycleState;
int _StepState;
int LeftChannelValue;
int RightChannelValue;

int PerformSetup(){
  switch(_StepState){
    case 0:
    digitalWrite(PROCESS_DAC_I2S_DATA, LeftChannelValue & bit(16)?HIGH:LOW); //
    break;

    case 1:
    digitalWrite(PROCESS_DAC_I2S_DATA, LeftChannelValue & bit(15)?HIGH:LOW); //
    break;

    case 2:
    digitalWrite(PROCESS_DAC_I2S_DATA, LeftChannelValue & bit(14)?HIGH:LOW); //
    break;

    case 3:
    digitalWrite(PROCESS_DAC_I2S_DATA, LeftChannelValue & bit(13)?HIGH:LOW); //
    break;

    case 4:
    digitalWrite(PROCESS_DAC_I2S_DATA, LeftChannelValue & bit(12)?HIGH:LOW); //
    break;

    case 5:
    digitalWrite(PROCESS_DAC_I2S_DATA, LeftChannelValue & bit(11)?HIGH:LOW); //
    break;

    case 6:
    digitalWrite(PROCESS_DAC_I2S_DATA, LeftChannelValue & bit(10)?HIGH:LOW); //
    break;

    case 7:
    digitalWrite(PROCESS_DAC_I2S_DATA, LeftChannelValue & bit(9)?HIGH:LOW); //
    break;

    case 8:
    digitalWrite(PROCESS_DAC_I2S_DATA, LeftChannelValue & bit(8)?HIGH:LOW); //
    break;

    case 9:
    digitalWrite(PROCESS_DAC_I2S_DATA, LeftChannelValue & bit(7)?HIGH:LOW); //
    break;

    case 10:
    digitalWrite(PROCESS_DAC_I2S_DATA, LeftChannelValue & bit(6)?HIGH:LOW); //
    break;

    case 11:
    digitalWrite(PROCESS_DAC_I2S_DATA, LeftChannelValue & bit(5)?HIGH:LOW); //
    break;

    case 12:
    digitalWrite(PROCESS_DAC_I2S_DATA, LeftChannelValue & bit(4)?HIGH:LOW); //
    break;

    case 13:
    digitalWrite(PROCESS_DAC_I2S_DATA, LeftChannelValue & bit(3)?HIGH:LOW); //
    break;

    case 14:
    digitalWrite(PROCESS_DAC_I2S_DATA, LeftChannelValue & bit(2)?HIGH:LOW); //
    break;

    case 15:
    digitalWrite(PROCESS_DAC_I2S_DATA, LeftChannelValue & bit(1)?HIGH:LOW); //
    break;
    digitalWrite(PROCESS_DAC_I2S_WS, HIGH); //

    case 16:
    digitalWrite(PROCESS_DAC_I2S_DATA, RightChannelValue & bit(16)?HIGH:LOW); //
    break;

    case 17:
    digitalWrite(PROCESS_DAC_I2S_DATA, RightChannelValue & bit(15)?HIGH:LOW); //
    break;

    case 18:
    digitalWrite(PROCESS_DAC_I2S_DATA, RightChannelValue & bit(14)?HIGH:LOW); //
    break;

    case 19:
    digitalWrite(PROCESS_DAC_I2S_DATA, RightChannelValue & bit(13)?HIGH:LOW); //
    break;

    case 20:
    digitalWrite(PROCESS_DAC_I2S_DATA, RightChannelValue & bit(12)?HIGH:LOW); //
    break;

    case 21:
    digitalWrite(PROCESS_DAC_I2S_DATA, RightChannelValue & bit(11)?HIGH:LOW); //
    break;

    case 22:
    digitalWrite(PROCESS_DAC_I2S_DATA, RightChannelValue & bit(10)?HIGH:LOW); //
    break;

    case 23:
    digitalWrite(PROCESS_DAC_I2S_DATA, RightChannelValue & bit(9)?HIGH:LOW); //
    break;

    case 24:
    digitalWrite(PROCESS_DAC_I2S_DATA, RightChannelValue & bit(8)?HIGH:LOW); //
    break;

    case 25:
    digitalWrite(PROCESS_DAC_I2S_DATA, RightChannelValue & bit(7)?HIGH:LOW); //
    break;

    case 26:
    digitalWrite(PROCESS_DAC_I2S_DATA, RightChannelValue & bit(6)?HIGH:LOW); //
    break;

    case 27:
    digitalWrite(PROCESS_DAC_I2S_DATA, RightChannelValue & bit(5)?HIGH:LOW); //
    break;

    case 28:
    digitalWrite(PROCESS_DAC_I2S_DATA, RightChannelValue & bit(4)?HIGH:LOW); //
    break;

    case 29:
    digitalWrite(PROCESS_DAC_I2S_DATA, RightChannelValue & bit(3)?HIGH:LOW); //
    break;

    case 30:
    digitalWrite(PROCESS_DAC_I2S_DATA, RightChannelValue & bit(2)?HIGH:LOW); //
    break;

    case 31:
    digitalWrite(PROCESS_DAC_I2S_DATA, RightChannelValue & bit(1)?HIGH:LOW); //
    break;
    digitalWrite(PROCESS_DAC_I2S_WS, LOW); //

  };
  _StepState ++;
  return 1;
}

int PerformCycle(){
switch(_CycleState){
  case 0:
  digitalWrite(PROCESS_DAC_I2S_BCK, LOW); //
  _CycleState = PerformSetup();
  break;
  case 1:
  digitalWrite(PROCESS_DAC_I2S_BCK, HIGH); //
  _CycleState = 0; //
  break;
  default:
  return 0;
  break;
};
return 1;
};

 public:
TDA1543A(uint16_t BCK, uint16_t WS, uint16_t DATA){
PROCESS_DAC_I2S_BCK = BCK;
PROCESS_DAC_I2S_WS = WS;
PROCESS_DAC_I2S_DATA = DATA;
 pinMode(PROCESS_DAC_I2S_BCK, IO_MCU_BCK); //
 pinMode(PROCESS_DAC_I2S_WS, IO_MCU_WS); //
 pinMode(PROCESS_DAC_I2S_DATA, IO_MCU_DATA); //
 digitalWrite(_DAC_I2S_BCK, LOW); //
 digitalWrite(_DAC_I2S_WS, LOW); //
 digitalWrite(_DAC_I2S_DATA, LOW); //
}; //
void begin(){
}; //
void end(){
}; //
void init(){
}; //This function initializes signals of the digital-to-analog converter
void convert(void){
}; //
void maxVolume(){
}; //
void minVolume(){
}; //
void leftChannel(int L){
}; //
void rightChannel(int R){
}; //
void setDataMode(){
}; //
void setFrequMax(){
}; //
void setFrequMin(){
}; //
void normalFrequ(){
}; //
int CommunicationLoop(){
  
}
void StartAnalogWrite(int LeftChannelValueEnable, int RightChannelValueEnable){
  _Busy = 1; //
  LeftChannelValue = LeftChannelValueEnable; //
  RightChannelValue = RightChannelValueEnable; //
  _CycleState = 0; //
  _StepState = 0; //
}
int IsBusy(){
  return _Busy; //
}

 private:
uint16_t _DAC_I2S_BCK; //
uint16_t _DAC_I2S_WS; //
uint16_t _DAC_I2S_DATA; //

 protected:

};

 #endif //
