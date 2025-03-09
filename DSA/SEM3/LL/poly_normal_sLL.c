#include<stdio.h>
#include<stdlib.h>
struct poly{
    int co;
    int exo;
    struct poly*next;
};
void insert(struct poly**start,int c,int e){
    struct poly*newnode=(struct poly*)calloc(1,sizeof(struct poly));
    struct poly*temp;
    if(*start==NULL){
        newnode->next=NULL;
        newnode->co=c;
        newnode->exo=e;
        *start=newnode;
    }
    else{
        for(temp=*start;temp->next!=NULL;temp=temp->next){}
        newnode->next=NULL;
        newnode->co=c;
        newnode->exo=e;
        temp->next=newnode;
    }
}
struct poly** attach(struct poly**exp3,int c,int e){
    struct poly*newnode=(struct poly*)calloc(1,sizeof(struct poly));
    struct poly*temp;
    if(*exp3==NULL){
        newnode->next=NULL;
        newnode->co=c;
        newnode->exo=e;
        *exp3=newnode;
    }
    else{
        for(temp=*exp3;temp->next!=NULL;temp=temp->next){}
        newnode->next=NULL;
        newnode->co=c;
        newnode->exo=e;
        temp->next=newnode;
    }
    return exp3;
}
int compare(int e1,int e2){
    if(e1>e2)
    return 1;
    else if(e1<e2)
    return -1;
    else return 0;
    
}
void polyadd(struct poly*e1,struct poly*e2,struct poly**e3){
    int sum;
    while(e1&&e2){
        switch(compare(e1->exo,e2->exo)){
            case 1:e3=attach(e3,e1->co,e1->exo);
            e1=e1->next;
            break;
            case -1:e3=attach(e3,e2->co,e2->exo);
            e2=e2->next;
            break;
            case 0:sum=e1->co+e2->co;
            e3=attach(e3,sum,e1->exo);
            e1=e1->next;
             e2=e2->next;
            break;
        }
    }
    while(e1){
        e3=attach(e3,e1->co,e1->exo);
            e1=e1->next;
    }
    while(e2){
        e3=attach(e3,e2->co,e2->exo);
            e2=e2->next;
    }
}
void display(struct poly * exp){
    struct poly * temp;
    for(temp=exp;temp!=NULL;temp=temp->next){
        if(temp->co>=0)
    printf("+%d",temp->co);
    if(temp->co<0)
    printf("%d",temp->co);
    if(temp->exo>0)
    printf("x^%d",temp->exo);
    if(temp->exo<0)
    printf("x^(%d)",temp->exo);
    }
}
int main(){
    struct poly*e1,*e2,*e3;
    e1=e2=e3=NULL;
    int ch,i,coeff,exp;
    do{
        printf("1.exp1 2.exp2 3exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:scanf("%d %d",&coeff,&exp);
            insert(&e1,coeff,exp);
            break;
            case 2:scanf("%d %d",&coeff,&exp);
            insert(&e2,coeff,exp);
            break;
        } 
    }while(ch!=3);
    printf("exp1:\t");
    display(e1);
    printf("\n");
     printf("exp2:\t");
    display(e2);
    printf("\n");
    polyadd(e1,e2,&e3);
     printf("final exp:\t");
    display(e3);
}