#include<stdio.h>
#include<stdlib.h>

struct node{
	char data;
	struct node*lchild;
	struct node*rchild;
};

void inorder(struct node*root){
	if(root){
	inorder(root->lchild);
	printf("%c\t",root->data);
	inorder(root->rchild);
	}
}
void preorder(struct node*root){
	if(root){
	printf("%c\t",root->data);
	preorder(root->lchild);
	preorder(root->rchild);
	}
}
void postorder(struct node*root){
	if(root){
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%c\t",root->data);
	}
}
void createI(struct node**root){
	int ch,i;
	char dir[100];
	char data;
	struct node*newnode=(struct node*)calloc(1,sizeof(struct node));
	struct node*temp;
	newnode->data='A';
	newnode->lchild=newnode->rchild=NULL;
	*root=newnode;
	do{
	temp=*root;
	printf("enter direction to trvaerse (r (RIGHT) or l (LEFT)):\n");
	gets(dir);
	printf("enter data for next node\n");
	scanf("%c",&data);
	getchar();
       i=0;
	while(dir[i]!='\0'){
       if(dir[i]=='r'){
       if(temp->rchild!=NULL)
       temp=temp->rchild;
       else
       break;
       }

       if(dir[i]=='l'){
       if(temp->lchild!=NULL)
       temp=temp->lchild;
       else
       break;
       }
       i++;
	}
	struct node*newnode2=(struct node*)calloc(1,sizeof(struct node));
      newnode2->data=data;
      newnode2->lchild=newnode2->rchild=NULL;
      if(dir[i]=='r')
      temp->rchild=newnode2;
      else
      temp->lchild=newnode2;
  printf("Enter -1 to stop\n");
  scanf("%d",&ch);
  getchar();

	}while(ch!=-1);
}
int main(){
struct node*root=(struct node*)calloc(1,sizeof(struct node));
createI(&root);
printf("the inorder is:\n");
inorder(root);
printf("\n");
printf("the preorder is:\n");
preorder(root);
printf("\n");
printf("the postorder is:\n");
postorder(root);
printf("\n");
free(root);
	}
