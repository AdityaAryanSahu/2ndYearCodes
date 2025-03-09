
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
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
struct node* cpy(struct node*root){
    
	if(root){
    	struct node*newnode=(struct node*)calloc(1,sizeof(struct node));
    	newnode->data=root->data;
    	newnode->rchild=newnode->lchild=NULL;
    	newnode->lchild=cpy(root->lchild);
    	newnode->rchild=cpy(root->rchild);
    	return newnode;
	}
	else return NULL;                   	 

}


int equal(struct node*root1,struct node*root2){
return ((!root1&&!root2)||(root1&&root2&&(root1->data==root2->data)&&equal(root1->lchild,root2->lchild)&&equal(root1->rchild,root2->rchild)));
}

int main(){
struct node*root1=(struct node*)calloc(1,sizeof(struct node));
struct node*root2=(struct node*)calloc(1,sizeof(struct node));
struct node*root3=(struct node*)calloc(1,sizeof(struct node));

//tree1 
createI(&root1);
printf("the inorder of tree1 is:\n");
inorder(root1);
printf("\n");
printf("the preorder of tree1is:\n");
preorder(root1);
printf("\n");
printf("the postorder of tree1 is:\n");
postorder(root1);
printf("\n\n");

//tree2 
root2=cpy(root1);  //cpy tree1 to tree2

printf("the inorder of tree2 is:\n");
inorder(root2);
printf("\n");
printf("the preorder of tree2is:\n");
preorder(root2);
printf("\n");
printf("the postorder of tree2 is:\n");
postorder(root2);
printf("\n\n");

//tree3 
printf("enter tree 3\n");
createI(&root3);
printf("the inorder of tree3 is:\n");
inorder(root3);
printf("\n");
printf("the preorder of tree3 is:\n");
preorder(root3);
printf("\n");
printf("the postorder of tree3 is:\n");
postorder(root3);
printf("\n\n");

//equality check
int flag=equal(root3,root2);
if(flag)
printf("Both trees Equal\n");
else printf("not equal");
free(root1);
free(root2);
free(root3);
}
