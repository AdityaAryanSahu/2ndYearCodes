#include<LPC17xx.h>

unsigned int i,j;
unsigned char look[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7A,0x39,0x5d,0x79,0x71};
int arr[4]={0,0,0,0};

int main(){
	LPC_PINCON->PINSEL0&=0XFF0000FF;
	LPC_GPIO0->FIODIR|=0XFF0;
	LPC_GPIO1->FIODIR|=0XF<<23;
	LPC_GPIO2->FIODIR&=~(1<<10);
	while(1){
	if(LPC_GPIO2->FIOPIN & (1<<10)){
		 for(arr[3]=0;arr[3]<=15;arr[3]++){
			  for(arr[2]=0;arr[2]<=15;arr[2]++){
					 for(arr[1]=0;arr[1]<=15;arr[1]++){
						  for(arr[0]=0;arr[0]<=15;arr[0]++){
								for(i=0;i<4;i++){
									LPC_GPIO1->FIOPIN=i<<23;
									LPC_GPIO0->FIOPIN=look[arr[i]]<<4;
									for(j=0;j<100000;j++);
								}
								LPC_GPIO0->FIOCLR|=0XFF0;
							}
						}
					}
				}
			}
	else{
		 for(arr[3]=15;arr[3]>=0;arr[3]--){
			  for(arr[2]=15;arr[2]>=0;arr[2]--){
					 for(arr[1]=15;arr[1]>=0;arr[1]--){
						  for(arr[0]=15;arr[0]>=0;arr[0]--){
								for(i=0;i<4;i++){
									LPC_GPIO1->FIOPIN=i<<23;
									LPC_GPIO0->FIOPIN=look[arr[i]]<<4;
									for(j=0;j<100000;j++);
								}
								LPC_GPIO0->FIOCLR|=0XFF0;
							}
						}
					}
				}
	}
		}
	}



