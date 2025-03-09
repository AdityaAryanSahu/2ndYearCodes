#include<stdio.h>
#include<stdlib.h>
struct node{
    char data;
    int rthread,lthread;
    struct node* lchild;
        struct node* rchild;
};

struct node* succ(struct node* n){
  struct node*temp=n->rchild;
  if(n->rthread==0){
  while(temp->lthread==0)
        {temp=temp->lchild;}
  }
        return temp;
}

void inorder(struct node*head){
    struct node*temp=head;
    while(1){
        temp=succ(temp);
        if(temp==head) break;
        printf("%c\t",temp->data);
    }
}
void createI(struct node**root,struct node*head){
    char d;
    int ch;
    char dir[100];
    struct node* newnode=(struct node*)calloc(1,sizeof(struct node));
    newnode->data='A';
    newnode->rchild=newnode->lchild=head;
    newnode->rthread=newnode->lthread=1;
    *root=newnode;
    struct node*temp;
    do{
        int i=0;
        temp=*root;
    printf("enter direction right(r) or left(l)\n ");
    gets(dir);
   // getchar();
     printf("enter data fr a node\n");
    scanf("%c",&d);
    getchar();
    while(dir[i]!='\0'){
        if(dir[i]=='r'){
            if(temp->rthread!=1)
            temp=temp->rchild;
            else break;
        }
        else if(dir[i]=='l'){
            if(temp->lthread!=1)
            temp=temp->lchild;
            else break;
        }
        i++;
    }
    struct node* newnode2=(struct node*)calloc(1,sizeof(struct node));
    newnode2->data=d;
    newnode2->rthread=newnode2->lthread=1;
    if (dir[i] == 'r') {
            newnode2->rchild = temp->rchild;
            newnode2->lchild = temp;
            temp->rthread = 0;
            temp->rchild = newnode2;
        } else if (dir[i] == 'l') {
            newnode2->lchild = temp->lchild;
            newnode2->rchild = temp;
            temp->lthread = 0;
         temp->lchild = newnode2;
        }
    printf("enter -1 to stop\n");
    scanf("%d",&ch);
    getchar();
   
    }while(ch!=-1);
}

int main(){
struct node* root;
struct node*head=(struct node*)calloc(1,sizeof(struct node));
head->rchild=head;
createI(&root,head);
head->lchild=root;
printf("inorder traversal:\n");
inorder(head);
printf("\n");

free(root);

return 0;
}