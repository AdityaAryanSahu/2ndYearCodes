#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct BT{
	char data;
	struct BT*lchild;
	struct BT*rchild;
};

struct BT*stack[20];
int top=-1;

void push(struct BT*node){
	stack[++top]=node;
}

struct BT* pop(){
	return stack[top--];
}
 
void inorder(struct BT*root){
	if(root){
	inorder(root->lchild);
	printf("%c\t",root->data);
	inorder(root->rchild);
	}
}
void preorder(struct BT*root){
	if(root){
	printf("%c\t",root->data);
	preorder(root->lchild);
	preorder(root->rchild);
	}
}
void postorder(struct BT*root){
	if(root){
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%c\t",root->data);
	}
}


struct BT*prefix_build(char prefix[]){
struct BT*temp,b;
int i=0;
int n=strlen(prefix);
for(i=n-1;i>=0;i--){
	temp=(struct BT*)calloc(1,sizeof(b));
	temp->lchild=temp->rchild=NULL;
	if(prefix[i]>='0'&& prefix[i]<='9'){
		temp->data=prefix[i];
		push(temp);
	}
	else{
		temp->data=prefix[i];
		temp->lchild=pop();
		temp->rchild=pop();
		push(temp);
	}
}
return (pop());
}
int eval(struct BT*root){
	int n;
	switch(root->data){
	case '+':return(eval(root->rchild)+eval(root->lchild));break;
    case '-':return(eval(root->lchild)-eval(root->rchild));break;
	case '*':return(eval(root->rchild)*eval(root->lchild));break;
	case '/':return(eval(root->lchild)/eval(root->rchild));break;
	case '^':return(pow(eval(root->lchild),eval(root->rchild)));break;
	default:return(root->data-'0');
	}
}
int main(){
	char prefix[50];
	printf("enter prefix exp\n");
	gets(prefix);
	struct BT*root=NULL;
	root=prefix_build(prefix);
	printf("the inorder is:\n");
inorder(root);
printf("\n");
printf("the preorder is:\n");
preorder(root);
printf("\n");
printf("the postorder is:\n");
postorder(root);
printf("\n");

int result=eval(root);
printf("result: %d\n",result);
}