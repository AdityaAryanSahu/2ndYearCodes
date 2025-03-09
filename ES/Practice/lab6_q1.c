#include<LPC17xx.h>

unsigned int count=0;

unsigned int i;

int main(){

LPC_PINCON->PINSEL0&=0xFF0000FF;
LPC_GPIO0->FIODIR|=0XFF0;

while(1){
	   LPC_GPIO0->FIOCLR=0XFF0;
     LPC_GPIO0->FIOSET=count<<4;
	count++;
	 if(count==256) count=0;
	 
	 for(i=0;i<100000;i++);
}

}
