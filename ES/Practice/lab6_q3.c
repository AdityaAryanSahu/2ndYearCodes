#include<LPC17xx.h>

unsigned int i,j;
int count=1;

int main(){
LPC_PINCON->PINSEL0&=0XFF0000FF;
	LPC_GPIO0->FIODIR|=0XFF0;
	LPC_GPIO2->FIODIR&=~(1<<10);
	
	while(1){
		if(!LPC_GPIO2->FIOPIN & (1<<10)){
	LPC_GPIO0->FIOCLR=0XFF0;
		LPC_GPIO0->FIOSET=count<<4;
		count<<=1;
		if(count==256) count=1;
		for(i=0;i<10000;i++);
	}
}


}
