#include<stdio.h>
#include<stdlib.h>

struct bt{
    char data;
    struct bt*rchild,*lchild;
};
struct bt* stack[50];
int top=-1;
int isEmpty(){
    if(top==-1) return 1;
    else return 0;
}

void push(struct bt*node){
    stack[++top]=node;
}

struct bt* pop(){
    return stack[top--];
}

void inorder(struct bt*root){
struct bt*curr=root;
while(curr!=NULL || isEmpty()==0){
    while(curr!=NULL){
        push(curr);
        curr=curr->lchild;
    }
    curr=pop();
    printf("%c\t",curr->data);
    curr=curr->rchild;
  }
}

void preorder(struct bt*root){
struct bt*curr=root;

while(curr!=NULL || isEmpty()==0){
    while(curr!=NULL){
        push(curr);
         printf("%c\t",curr->data);
        curr=curr->lchild;
    }
    curr=pop();
    curr=curr->rchild;
  }
}

void postorder(struct bt*root){
struct bt*curr=root,*lastvisit=NULL;
while(curr!=NULL || isEmpty()==0){
    while(curr!=NULL){
        push(curr);
        curr=curr->lchild;
    }
    struct bt*peek=stack[top];
    if(peek->rchild!=NULL && peek->rchild!=lastvisit){
        curr=peek->rchild;
    }
    else{
        lastvisit=pop();
        printf("%c\t",peek->data);
    }
 }
}
void insert(struct bt**root){
   struct bt*newnode=(struct bt*)calloc(1,sizeof(struct bt));
    newnode->lchild=newnode->rchild=NULL;
    newnode->data='A';
    *root=newnode;
    struct bt*temp;
    char x;
    char dir[30];
    int s;
    do{ 
        int i=0;
        temp=*root;
        printf("enter direction lrft(l) or right(r)\n");
        gets(dir);
        printf("enter data fir a node\n");
        scanf("%c",&x);
        getchar();
        while(dir[i]!='\0'){
            if(dir[i]=='r'){
                if(temp->rchild!=NULL)
                temp=temp->rchild;
                else break;
            }
            if(dir[i]=='l'){
                if(temp->lchild!=NULL)
                temp=temp->lchild;
                else break;
            }
            i++;
        }
   struct bt*newnode2=(struct bt*)calloc(1,sizeof(struct bt));
   newnode2->data=x;
   if(dir[i]=='r') temp->rchild=newnode2;
   else temp->lchild=newnode2;
    printf("enter -1 to stop\n");
    scanf("%d",&s);
    getchar();

    }while(s!=-1);
}

int main(){
    struct bt *root=NULL;
    insert(&root);
    printf("tree in inorder:\n");
   inorder(root);
   printf("\n");
   printf("tree in preorder:\n");
   preorder(root);
   printf("\n");
   printf("tree in postorder:\n");
   postorder(root);
   printf("\n");
}