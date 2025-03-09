#include<stdio.h>
#include<stdlib.h>
struct poly{
    int co;
    int exo;
    struct poly*next;
};
void insert(struct poly**head,int c,int e){
    struct poly*newnode=(struct poly*)calloc(1,sizeof(struct poly));
    struct poly*temp;
    if((*head)->next==*head){
        newnode->next=*head;
        newnode->co=c;
        newnode->exo=e;
        (*head)->next=newnode;
    }
    else{
        for(temp=(*head)->next;temp->next!=*head;temp=temp->next){}
        newnode->next=*head;
        newnode->co=c;
        newnode->exo=e;
        temp->next=newnode;
    }
}
struct poly** attach(struct poly**exp3,int c,int e){
    struct poly*newnode=(struct poly*)calloc(1,sizeof(struct poly));
    struct poly*temp;
    if((*exp3)->next==*exp3){
        newnode->next=*exp3;
        newnode->co=c;
        newnode->exo=e;
        (*exp3)->next=newnode;
    }
    else{
        for(temp=(*exp3)->next;temp->next!=*exp3 && temp->exo>e;temp=temp->next){}
        newnode->next=*exp3;
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
void polyasub(struct poly*e1,struct poly*e2,struct poly**e3){
    int sum;
    struct poly *a,*b;
    a=e1->next;
    b=e2->next;
    int flag=1;
    while(flag){
        switch(compare(a->exo,b->exo)){
            case 1:e3=attach(e3,a->co,a->exo);
            a=a->next;
            if(a==e1)
            flag=0;
            break;
            case -1:e3=attach(e3,b->co,b->exo);
            b=b->next;
             if(b==e2)
            flag=0;
            break;
            case 0:sum=a->co-b->co;
            e3=attach(e3,sum,a->exo);
            a=a->next;
             b=b->next;
              if(a==e1||b==e2)
            flag=0;
            break;
        }
    }
    while(a!=e1){
        e3=attach(e3,a->co,a->exo);
            a=a->next;
    }
    while(b!=e2){
        e3=attach(e3,b->co,b->exo);
            b=b->next;
    }
}

void polyamult(struct poly*e1,struct poly*e2,struct poly**e4){
     int sum;
    struct poly *a,*b;
   
    b=e2->next;
   
     for( a=e1->next;a!=e1;a=a->next){
        for( b=e2->next;b!=e2;b=b->next){
            attach(e4,a->co * b->co,a->exo+b->exo);
        }
     }
struct poly*temp;
     for(temp=(*e4)->next;temp!=*e4;temp=temp->next){
        if(temp->exo==temp->next->exo){
            temp->co=temp->co+temp->next->co;
            temp->next=temp->next->next;
        }
     }
}


void display(struct poly * exp){
    struct poly * temp;
    for(temp=exp->next;temp!=exp;temp=temp->next){
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
    
    struct poly* e1=( struct poly*)calloc(1,sizeof(struct poly));
    struct poly* e2=( struct poly*)calloc(1,sizeof(struct poly));
    struct poly* e3=( struct poly*)calloc(1,sizeof(struct poly));
    struct poly* e4=( struct poly*)calloc(1,sizeof(struct poly));
    e1->next=e1;
      e2->next=e2;
        e3->next=e3;
        e4->next=e4;
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
    polyasub(e1,e2,&e3);

     printf("after subtravtion exp:\t");
     if(e3->next==e3)
     printf("zero poly\n");
     else
    display(e3);
    printf("\n");

     polyamult(e1,e2,&e4);
     
     printf("after multi exp:\t");
     if(e4->next==e4)
     printf("zero poly\n");
     else
    display(e4);
}