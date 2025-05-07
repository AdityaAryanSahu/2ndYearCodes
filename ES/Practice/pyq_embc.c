#include<LPC17xx.h>
-----------------------------------------------------------------------------------------------------------------
/*
Develop an ISR (EINT3_IRQHandler) to toggle all the LEDs in the LED unit using external interrupt 
3. Connect port pins 0.4 to 0.11 in the LED unit.

void EINT3_IRQHandler(){

if(LPC_SC->EXTINT && (1<<3)){  //if not necessary can skip
      LPC_GPIO0->FIOPIN ^=0xff0;
	  LPC_SC->EXTINT=1<<3;  
}

}

void extint_intit(){

 LPC_PINCON->PINSEL4|=1<<26;
 LPC_GPIO0->FIODIR|=0xff0;
 LPC_SC->EXTMODE=1<<3;
 LPC_SC->EXTPOLAR=1<<3;
 NVIC_EnableIRQ(EINT3_IRQn);
}
*/
-------------------------------------------------------------------------------------------------------------------
/*

Construct an ISR (ADC_IRQHandler) to store the analog value of the signal provided at ADC 
channels 5 and 6 along with the channel number in two different strings. The analog signal ranges
from 0 to +5 Volts. Use A/D data registers to extract the results.

char ch5[100],ch6[100];
int ch;
   int val;
void ADC_IRQHandler(){
    ch= (LPC_ADC->ADGDR>>24) & 0x7;
    val= (LPC_ADC->ADGDR>>4) & 0xfff;
	float ana=(float)val*3.3/1023;
	if(ch==5){
	    sprintf(ch5,"%d%.2f",ch,ana);
	}
	else sprintf(ch6,"%d%.2f",ch,ana);
}

void adc_init(){
LPC_SC->PCONP|=1<<12|1<<15
LPC_PINCON->PINSEL|=2<<30 | 1<<4; //prob wrong dont remember the pins
LPC_ADC->ADCR|= (1<<5)|(1<<6)|(1<<16)|(1<<21);
LPC_ADC->ADINTEN=1<<5|1<<6;
NVIC_EnableIRQ(ADC_IRQn);

}

*/
-------------------------------------------------------------------------------------------------------------------------


/*
Develop an embedded C program to toggle LED connected to P2.11 upon an external interrupt
EINT0. Set the EINT0 as rising edge sensitive. Note: EINT0 is 1st alternate function of P2.10.


void EINT0_IRQHandler(){
     LPC_GPIO2->FIOPIN^=1<<11;
	LPC_SC->EXTINT=1<<0;
}

void ectint_init(){

LPC_GPIO2->FIODIR|=1<<11;
LPC_PINCON->PINSEL4|=1<<20;
LPC_SC->EXTMODE=1;
LPC_SC->EXTPOLAR=1;
NVIC_EnableIRQ(EINT0_IRQn);
}

//just call above funtion in main done
*/
---------------------------------------------------------------------------------------------------------------------------------
/*

Develop an embedded C program to turn on LED1 and LED2 connected to MAT2.0 and MAT2.1
output of Timer2 after 100ms and 200ms
, respectively. Note: MAT2.0 and MAT2.1 are 3rd alternate
functions of P0.6 and P0.7.


void tim2_init(){
LPc_PINCON->PINSEL0|=3<<12|3<<14;
LPC_TIM2->CTCR=0;
LPC_TIM2->TCR=2;
LPC_TIM2->PR=0;
LPC_TIM2->MR0=100*25000;
LPC_TIM2->MR1=200*25000;
LPC_TIM2->EMR=2<<4 | 2<<6;
LPC_TIM2->TCR=1;
}
//just call in main done
*/
--------------------------------------------------------------------------------------------------------------------------------------

/*

Write an embedded C program using UART to
transfer the message "Hello World" serially on TXD0 (P0.2, Function 2) at a 9600 baud rate.
Assume parity disabled, 1 stop bit, 8bit word length, and PCLK=3MHz.

int val;
char str[20]="Hello World";
void uart_init(){
    LPC_SC->PCONP|=1<<3;
	LPC_PINCON->PINSEL0|=2<<4; //txd0
	val=300000/(16*9600);
	LPC_UART0->LCR=0x83;  //enable dlab
	LPC_UART0->DLL=val&0xff;
	LPC_UART0->DLM=val&0xff00;
	LPc_UART0->FCR=(1<<0)|(1<<1)|(1<<2);
	LPC_UART0->LCR=0x03;  //disable dlab
}
void transf(char c){
   while(!(LPC_UART0->LSR&(1<<5)));
   LPC_UART0->THR=c;
}
void send(){
   int i=0;
   while(str[i]!='\0'){
     transf(str[i]);
	 i++;
   }
}
//call uart_init() and send(string) in main done
*/
---------------------------------------------------------------------------------------------------------------------------------------
