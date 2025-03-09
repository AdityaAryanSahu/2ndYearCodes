#include<stdio.h>
#include<stdlib.h>

typedef struct{
int day;
int *month;
int year;
} DOB;

typedef struct{
int regno;
char *name;
char address[100];
} STU_INFO;

 typedef struct{
char *college_name;
char university_name[100];
} COLLEGE;

typedef struct{
DOB *d;
STU_INFO st;
COLLEGE c;
}STUDENT;

int main(){
STUDENT *s;
s=(STUDENT *)calloc(1,sizeof(STUDENT));
s->d=(DOB *)calloc(1,sizeof(DOB));
s->d->month=(int *)calloc(1,sizeof(int));
//DOB
printf("enter DOB:\n");
scanf("%d %d %d",&s->d->day,&s->d->month,&s->d->year);
//printf("\n");

//STUINFO
s->st.name=(char *)calloc(1,sizeof(char));
printf("Enter Stu_info\n");
scanf("%d %s %s",&s->st.regno,s->st.name,s->st.address);


//COLLEGE INFO
s->c.college_name=(char *)calloc(1,sizeof(char));
printf("enter College info:\n");
scanf("%s %s",s->c.college_name,s->c.university_name);

//printing
printf("\nthe details are:\n");

printf("the DOB is :\n");
printf("%d/%d/%d",s->d->day,s->d->month,s->d->year);
printf("\n");

printf("\nthe Stu_info is: \n");
printf("reg no: %d\nname: %s\naddress: %s\n",s->st.regno,s->st.name,s->st.address);
printf("\n");

printf("College info is :\n");
printf("college: %s\nuni: %s\n",s->c.college_name,s->c.university_name);
return 0;
}