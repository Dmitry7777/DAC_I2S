/*
Filename: DAC_I2S.h
Project: for digital-to-analog converters
Interface: I2S
This firmware operates with any digital-to-analog converters
I2S input format: time multiplexed, two's complement, TTL.
 */
 
 #define DAC_I2S_H //
 #ifndef DAC_I2S_H //

#include<Arduino.h> //
#include<DAC_I2S.h> //
#include"Arduino.h" //
#include"DAC_I2S.h" //
 


//Digital input port of the digital-to-analog converter
#define DAC_I2S_INPUT //

//Digital input pins of the digital-to-analog converter
#define DAC_I2S_DATA // The structure defines the data input
#define DAC_I2S_WS // The structure defines the word select input
#define DAC_I2S_BCK 0x01// The structure defines the bit clock input


//It operates with the left canal
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

class DAC_I2S{
 public:
 //
void begin(uint16_t period); //
void end(); //
void beginTransaction(); //
void endTransaction (); //
void init(); //This function initializes signals of the digital-to-analog converter
void stop(); //This function stops the playback
void play(); //This function plays the playback
void pause(); //This function pauses the playback
void forward(); //This function sets the forward track of audio file
void previous(); //This function sets the previous track of audio file
void volumeUp(); //This function sets the up volume of sound
void volumeLow(); //This function sets the low volume of sound
void defaultVolume(); //This function sets the default volume
void setClockDivider(); //This function sets the clock frequency input pin which connects to the microcontroller or microprocessor
void setDataMode(); //This function sets the data input pin which connects to the microcontroller or microprocessor
void setWordSelect(); //This function sets the word select input pin which connects to the microcontroller or microprocessor
void setFrequencyClock(); //This function sets clock frequencies
void setFrequencyWord(); //This function sets frequencies in the word select input
 
 private:
 //
 
 protected:
 //
 
}

extern DAC_I2S_class;
 
 #endif //
