#include<LPC17xx.h>

unsigned int i,j,key,temp3,var,flag,temp;
unsigned int hex[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7A,0x39,0x5d,0x79,0x71};
unsigned int sc_code[16]={0x11,0x21,0x41,0x81,
						 0x12,0x22,0x42,0x82,
						0x14,0x24,0x44,0x84,
						0x18,0x28,0x48,0x88};

void delay_1s(){
	
	LPC_TIM0->CTCR=0;
	LPC_TIM0->TCR=0x2;
	LPC_TIM0->MR0=3000000-1;
	LPC_TIM0->MCR=0X2;
	LPC_TIM0->EMR=0X20;
	LPC_TIM0->TCR=0X1;
	while(!(LPC_TIM0->EMR&(1<<5)));
	
}
	
void scan(){
		temp3=LPC_GPIO1->FIOPIN;
		temp3&=(0xf<<23);
		if(temp3!=0x0){
			flag=1;
			temp3>>=19;
			var>>=10;
			key=temp3|var;
			delay_1s();
	}
}
int main(){
	SystemInit();
	SystemCoreClockUpdate();
  LPC_GPIO1->FIODIR&=~(0xf<<23);  //col input
  LPC_GPIO2->FIODIR|=0xf<<10; //rows output
  
  LPC_GPIO0->FIODIR|=0xff0; //ssd data
  LPC_GPIO0->FIODIR|=0xf<<23;  //select lines
  
  while(1){
    while(1){
			for(j=0;j<4;j++){
					if(j==0) var=1<<10;
					else if(j==1) var=1<<11;
					else if(j==2) var=1<<12;
					else var=1<<13;
				LPC_GPIO2->FIOCLR = 0xF << 10;
					LPC_GPIO2->FIOPIN=var;
					scan();
					if(flag==1) break;
				}
				if(flag==1) break;
			}
		for(i=0;i<16;i++){
			if(key==sc_code[i]){
				key=hex[i];
				break;
			}
		}
		LPC_GPIO0->FIOSET=1<<23;
		LPC_GPIO0->FIOSET=key<<4;
		delay_1s();
		LPC_GPIO0->FIOCLR=1<<23;
		LPC_GPIO0->FIOCLR=0xff<<4;
		delay_1s();
		flag=0;
		
	}
}
			

  
  
  