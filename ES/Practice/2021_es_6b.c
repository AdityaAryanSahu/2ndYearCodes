#include<LPC17xx.h>

unsigned int i;
unsigned char look[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
int count=0;

int main(){
LPC_GPIO0->FIODIR|=0XFF0;
	LPC_GPIO0->FIODIR|= 0X7800;
	
	while(1){
	if(count%2==0){
	    LPC_GPIO0->FIOPIN=1<<17;
		  LPC_GPIO0->FIOPIN=look[count]<<4;
		for(i=0;i<1000000;i++);
	}
	else{
	LPC_GPIO0->FIOPIN=1<<18;
		  LPC_GPIO0->FIOPIN=look[count]<<4;
		for(i=0;i<1000000;i++);
	
	}
	count++;
	if(count==10) count=0;
	}
	
	
}
