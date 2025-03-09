#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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


struct BT*postfix_build(char postfix[]){
struct BT*temp,b;
int i=0;
while(postfix[i]!='\0'){
	temp=(struct BT*)calloc(1,sizeof(b));
	temp->lchild=temp->rchild=NULL;
	if(postfix[i]>='0'&& postfix[i]<='9'){
		temp->data=postfix[i];
		push(temp);
	}
	else{
		temp->data=postfix[i];
		temp->rchild=pop();
		temp->lchild=pop();
		push(temp);
	}
	i++;
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
	char postfix[50];
	printf("enter postfix exp\n");
	gets(postfix);
	struct BT*root=NULL;
	root=postfix_build(postfix);
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