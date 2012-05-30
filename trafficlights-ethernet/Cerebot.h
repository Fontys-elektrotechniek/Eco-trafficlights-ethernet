#ifndef _CEREBOT_H
#define _CEREBOT_H

/* ------------------------------------------------------------ */
/*					     Pin Definitions   		    			*/
/* ------------------------------------------------------------ */

/*	Onboard LEDs
*/
#define	trisLed1			TRISB
#define	trisLed1Set			TRISBSET
#define	trisLed1Clr			TRISBCLR
#define	prtLed1				PORTB
#define	prtLed1Set			PORTBSET
#define	prtLed1Clr			PORTBCLR
#define	prtLed1Inv			PORTBINV
#define	bnLed1				10

#define	trisLed2			TRISB
#define	trisLed2Set			TRISBSET
#define	trisLed2Clr			TRISBCLR
#define	prtLed2				PORTB
#define	prtLed2Set			PORTBSET
#define	prtLed2Clr			PORTBCLR
#define	prtLed2Inv			PORTBINV
#define	bnLed2				11

#define	trisLed3			TRISB
#define	trisLed3Set			TRISBSET
#define	trisLed3Clr			TRISBCLR
#define	prtLed3				PORTB
#define	prtLed3Set			PORTBSET
#define	prtLed3Clr			PORTBCLR
#define	prtLed3Inv			PORTBINV
#define	bnLed3				12

#define	trisLed4			TRISB
#define	trisLed4Set			TRISBSET
#define	trisLed4Clr			TRISBCLR
#define	prtLed4				PORTB
#define	prtLed4Set			PORTBSET
#define	prtLed4Clr			PORTBCLR
#define	prtLed4Inv			PORTBINV
#define	bnLed4				13

/*	Onboard Buttons
*/

#define	trisBtn1			TRISA
#define	trisBtn1Set			TRISASET
#define	trisBtn1Clr			TRISACLR
#define	prtBtn1				PORTA
#define	prtBtn1Set			PORTASET
#define	prtBtn1Clr			PORTACLR
#define	bnBtn1				6

#define	trisBtn2			TRISA
#define	trisBtn2Set			TRISASET
#define	trisBtn2Clr			TRISACLR
#define	prtBtn2				PORTA
#define	prtBtn2Set			PORTASET
#define	prtBtn2Clr			PORTACLR
#define	bnBtn2				7

/*	Site
*/
#define TRAFFICLIGHTS_VERSION           "v1.0"


void InitializeUART(void);
void InitalizeCrossroadIO(void);
void WriteString(const char *string);
void PutCharacter(const char character);
void ProcessIO(void);
void InitializeBoard(void);
void InitAppConfig(void);
void DisplayIPValue();
void CheckIfIPChanged(void);
void BlinkLed1(void);
void CheckForButtonPressed(void);

#endif // _CEREBOT_H
