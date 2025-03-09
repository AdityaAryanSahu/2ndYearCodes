#include<stdio.h>
#include<stdlib.h>

typedef struct{
int month;
int day;
int year;
} DOB;

typedef struct {
int houseno;
int zipcode;
char state[30];
} ADDRESS;

typedef struct{
char name[100];
DOB d;
ADDRESS ad;
} EMPLOYEE;

int main(){
EMPLOYEE *e;

int n;
printf("no of employee");
scanf("%d",&n);
e=(EMPLOYEE *)calloc(n,sizeof(EMPLOYEE));
int i;
for(i=0;i<n;i++){
printf("eter name of employee %d\n",i+1);
scanf("%s",(e+i)->name);
printf("Enter DOB of employee %d\n",i+1);
scanf("%d %d %d",&(e+i)->d.day,&(e+i)->d.month,&(e+i)->d.year);
printf("Enter Address of employee %d\n",i+1);
scanf("%d %d %s",&(e+i)->ad.houseno,&(e+i)->ad.zipcode,(e+i)->ad.state);}

for(i=0;i<n;i++){
printf("\nname of employee %d is:",i+1);
printf("%s\n",(e+i)->name);
printf("DOB of employee %d is: ",i+1);
printf("%d/%d/%d\n",(e+i)->d.day,(e+i)->d.month,(e+i)->d.year);
printf("Address of employee %d is: ",i+1);
printf("%d, %d, %s\n",(e+i)->ad.houseno,(e+i)->ad.zipcode,(e+i)->ad.state);
printf("\n");
}
}
