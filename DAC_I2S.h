/*
Filename: DAC_I2S.h
Project: for digital-to-analog converters
Interface: I2S
This firmware operates with any digital-to-analog converters
I2S input format: time multiplexed, two's complement, TTL.
 */
 
 #define DAC_I2S_H
 #ifndef DAC_I2S_H

 #include"Arduino.h"
 #include"DAC_I2S.h"
 
  #endif


//Digital input port of the digital-to-analog converter
#define DAC_I2S_INPUT

//Digital input pins of the digital-to-analog converter
#define DAC_I2S_DATA // The structure defines the data input
#define DAC_I2S_WS // The structure defines the word select input
#define DAC_I2S_BCK // The structure defines the bit clock input
 
 
 public: I2S


//It operates with the left canal
#define LEFT_OUTPUT_LATCH
#define LEFT_BIT_SWITCHES
#define LEFT_INPUT_LATCH
#define LEFT_5_BIT_PASSIVE_DIVIDER
#define LEFT_11_BIT_PASSIVE_DIVIDER
#define LEFT_CURRENT_SOURCE

//It operates with the right canal
#define RIGHT_OUTPUT_LATCH
#define RIGHT_BIT_SWITCHES
#define RIGHT_INPUT_LATCH
#define RIGHT_5_BIT_PASSIVE_DIVIDER
#define RIGHT_11_BIT_PASSIVE_DIVIDER
#define RIGHT_CURRENT_SOURCE

#define ADDRESS_POINTER
 
 #endif
