#include<LPC17xx.h>
#include<stdio.h>

unsigned int i,j,temp1,temp2,temp3,res1,res2;
int diff;
char res[10];

void delay(unsigned int r){
	for(i=0;i<r;i++);
}

void clear_ports(){
	LPC_GPIO0->FIOCLR|=0xf<<23|1<<27|1<<28;
	delay(1000);
}

void write(int temp,int type){
	clear_ports();
	LPC_GPIO0->FIOPIN=temp;
	if(type==0) LPC_GPIO0->FIOCLR=1<<27;
	else  LPC_GPIO0->FIOSET=1<<27;
	
	 LPC_GPIO0->FIOSET=1<<28;
	delay(25);
	 LPC_GPIO0->FIOCLR=1<<28;
}

void comdata(int temp,int type){
	temp2=(temp&0xf0)<<19;
	write(temp2,type);
	temp2=(temp&0x0f)<<23;
	write(temp2,type);
	delay(1000);
}
void lcd_init(){
	clear_ports();
	LPC_GPIO0->FIODIR|=0xf<<23|1<<27|1<<28;
	
	comdata(0x33,0);
	delay(30000);
	comdata(0x32,0);
delay(30000);
	comdata(0x28,0);
delay(30000);
	comdata(0x0c,0);
	delay(800);
	comdata(0x06,0);
	delay(800);
	comdata(0x01,0);
	delay(10000);
}
void put(char *buff){
	i=0;
	while(buff[i]!='\0'){
		temp3=buff[i];
		comdata(temp3,1);
		i++;
		if(i==16) comdata(0xc0,0);
}
	}

int main(){
	SystemInit();
	SystemCoreClockUpdate();
		lcd_init();
	delay(1000);
   LPC_SC->PCONP|=1<<12;
	LPC_PINCON->PINSEL3|=0xf0000000;
	
while(1){
	  LPC_ADC->ADCR=1<<4|1<<21|1<<24;
	  while(!(LPC_ADC->ADDR4 & 0x80000000));
	  res1=(LPC_ADC->ADDR4>>4)&0xfff;
	
	LPC_ADC->ADCR=1<<5|1<<21|1<<24;
	  while(!(LPC_ADC->ADDR5 & 0x80000000));
	  res2=(LPC_ADC->ADDR5>>4)&0xfff;
	 
	diff=(res1>res2)? res1-res2: res2-res1;
	sprintf(res,"%x",diff);
	
	comdata(0xc0,0);
	delay(1000);
	put(&res[0]);
   }
}
	  