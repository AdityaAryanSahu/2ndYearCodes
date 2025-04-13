#include<LPC17xx.h>

unsigned int i,j,k;

unsigned int only[4]={0x36,0x38,0x37,0x3f};
unsigned int test[4]={0x78,0x6d,0x79,0x78};

void init_tim(){
   LPC_TIM0->CTCR=0;
	LPC_TIM0->TCR=0x2;
	LPC_TIM0->PC=2999;
	LPC_TIM0->MR0=1000;
	LPC_TIM0->MCR=0x2;
	LPC_TIM0->EMR=0x20;
	LPC_TIM0->TCR=1;
}
void delay(){
	init_tim();
	while(!(LPC_TIM0->EMR&(1<<5)));
}

int main(){
	LPC_GPIO0->FIODIR|=0xff0;
	LPC_GPIO0->FIODIR|=0xf<<23;
	
	while(1){
		for(i=0;i<4;i++){
			LPC_GPIO0->FIOPIN=i<<23;
			LPC_GPIO0->FIOPIN=only[i]<<4;
			for(j=0;j<10000;j++);
		}
		delay();
		for(i=0;i<4;i++){
			LPC_GPIO0->FIOPIN=i<<23;
			LPC_GPIO0->FIOPIN=test[i]<<4;
			for(j=0;j<10000;j++);
		}
		delay();
	}
}
	

