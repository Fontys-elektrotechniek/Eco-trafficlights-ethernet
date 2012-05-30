#ifndef _CROSSING3_H
#define _CROSSING3_H

#define AllOff			0x00
  /* cars green  pedestrians red */ 
#define CarsGreen		0x0C
/* cars orange pedestrians red   */
#define CarsOrange		0x14 
/* cars red    pedestrians green */
#define CarsRed			0x22 
#define BothRed			0x24
#define Camera			0x40  
#define Buzzer			0x01
// ... Blink wordt ge "exord" met CrossingLights 
#define PedBlink		0x03 
#define OrangeBlink		0x10

// the states    
#define BothRed1      		0x25  
#define BothRed2       		0x26 
#define Hurry	      		0x27
// i2c keys and Leds 
#define OnOff	       		0x7F
#define BlinkLed		0x40
#define BothLeds		0x3F
#define Blink			0xBF
// input switches from the crossing		       
#define S1		P5 & 0x01
#define S2		P5 & 0x02
#define S3		P5 & 0x04
#define S4		P5 & 0x08
//#define S5		P5 & 0x10
#define S9		P5 & 0x10 // S5 Temporarly switched with s9
#define S6		P5 & 0x20
#define S7		P5 & 0x40
#define S8		P5 & 0x80
// #define S9		P4 & 0x80    

#define CrossingLights	P4


#endif