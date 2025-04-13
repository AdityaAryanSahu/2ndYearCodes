#include<LPC17xx.h>
///for lcd 0.23 to 0.28
///for kb 1.23 to 1.26 col    2.10 to 2.13 row
unsigned int i,j;
unsigned int temp,var,temp2,temp3,key,flag,op,eq,num1,num2;
int result;
unsigned char dis[3];
unsigned char ascii[16]={'0','1','2','3','4','5','6','7','8','9','=','+','-','D','E','F'};
unsigned int sc_code[16]={0x11,0x21,0x41,0x81,
						 0x12,0x22,0x42,0x82,
						0x14,0x24,0x44,0x84,
						0x18,0x28,0x48,0x88};

void delay(unsigned int r){
	for(i=0;i<r;i++);
}

void clear_ports(){
	LPC_GPIO0->FIOCLR=0xf<<23;
	LPC_GPIO0->FIOCLR=1<<28;
	LPC_GPIO0->FIOCLR=1<<27;
	delay(1000);
}
void write(unsigned int temp1,unsigned int type){
	clear_ports();
	LPC_GPIO0->FIOPIN=temp1;
	
	if(type==0) LPC_GPIO0->FIOCLR=1<<27;
	else LPC_GPIO0->FIOSET=1<<27;
	
	LPC_GPIO0->FIOSET=1<<28;
	delay(25);
	LPC_GPIO0->FIOCLR=1<<28;
	
}
void comdata(unsigned int temp1,unsigned int type){
	temp2=(temp1&0xf0)<<19;
	write(temp2,type);
	temp2=(temp1&0xf)<<23;
		write(temp2,type);
	delay(1000);
	
}

void put(unsigned char* buff ){
	unsigned int k=0;
	while(buff[k]!='\0'){
		temp3=buff[k];
		comdata(temp3,1);
		k++;
		if(k==16)
			comdata(0xc0,0);
	}
}
void lcd_init(){
	clear_ports();
	delay(3000);
	LPC_GPIO0->FIODIR|=0xf<<23|1<<27|1<<28;
	delay(1000);
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

	void scan(){
		temp3=LPC_GPIO1->FIOPIN;
		temp3&=(0xf<<23);
		if(temp3!=0x0){
			flag=1;
			temp3>>=19;
			var>>=10;
			key=temp3|var;
			delay(1000);
	}
}
	int main(){
		SystemCoreClockUpdate();
		SystemInit();
		
		lcd_init();
		delay(1000);
		LPC_GPIO1->FIODIR&=~(0xf<<23); //col
		LPC_GPIO2->FIODIR|=0xf<<10;  //rows
		
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
			for(j=0;j<16;j++){
				if(key==sc_code[j]){
					key=ascii[j];
				if(key=='='){
					eq=1;
				}
				else if(key=='+') op=1;
				else if(key=='-') op=2;
				
				if(!op){
					num1=(int)key-'0';
				}
					else if(op && !eq){
						num2=(int)key-'0';
					}
					break;
				}
			}
			comdata(0xc0,0);
			delay(800);
			if(eq==1){
				if(op==1){
					result=num1+num2;
				}
				else result=num1-num2;
			}
			
			if(result>9){
				dis[1]=result%10+'0';
				result/=10;
				dis[0]=result+'0';
				dis[2]='\0';
			}
			else if(result<0){
				dis[0]='-';
				dis[1]=(-1*result)+'0';
				dis[2]='\0';
			}
			else{
				dis[0]=result+'0';
				dis[1]='\0';
			}
			
			put(dis);
			delay(800);
			num1=0;
			num2=0;
			op=0;
			eq=0;
			
		}
	}
				
			
						
		
		
		
						
						
