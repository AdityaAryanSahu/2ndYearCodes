#include<stdio.h>
#include<stdlib.h>
struct btree
{
    struct btree *lchild;
    struct btree *rchild;
    char data;
};
typedef enum{lparen,rparen,plus,minus,times,divide,mod,eos,operand}precedence;
precedence getToken(char symbol)
{
    
    switch(symbol)
    {
        case '(':return lparen;
        case ')':return rparen;
        case '+':return plus;
        case '-':return minus;
        case '*':return times;
        case '/':return divide;
        case '%':return mod;
        case '\0': return eos;
        default:return operand;
    }
}

struct btree *pstack[50];
char stack[50];
int topt=-1;
int topc=-1;
void pusht(struct btree *node)
{
    if(topt==49)
    printf("cant push\n");
    else
    pstack[++topt]=node;
}
void push(char c)
{
 if(topc==49)
    printf("cant push\n");
    else
    stack[++topc]=c;   
}

char pop()
{
return stack[topc--];
}

struct btree * popn()
{
    return pstack[topt--];
}

void inorder(struct btree *root)
{
	if (root)
	{
		inorder(root->lchild);
		printf("%c ", root->data);
		inorder(root->rchild);
 	}
}

void preorder(struct btree *root)
{
    	if (root)
	{
	    	printf("%c ", root->data);
		preorder(root->lchild);
			preorder(root->rchild);
 	}
}
void postorder(struct btree *root)
{
    	if (root)
	{
	    
		postorder(root->lchild);
			postorder(root->rchild);
				printf("%c ", root->data);
 	}
}

int main()
{
    struct btree *root,*temp,*n1,*n2;
    char infix[50],dummy,d;
    scanf("%s",infix);
    scanf("%c",&dummy);
    int i=0;
    while(infix[i]!='\0')
    {
         temp=(struct btree*)malloc(1*sizeof(struct btree) ); 
          temp->lchild=NULL;
         temp->rchild=NULL;
        if((infix[i]>='A' && infix[i]<='Z') || (infix[i]>='a' && infix[i]<='z')|| (infix[i]>=48 && infix[i]<=57))
        {
         temp->data=infix[i];
         pusht(temp);
        }
        else if(infix[i]=='(')
           push(infix[i]);
           
        else if(infix[i]==')')
            {
                while( 1 && topc!=-1 && topt!=-1)
                {
                    char k=pop();
                    if(k=='(')
                    break;
                    n1=popn();
                    n2=popn();
                  
                temp->data=k;
                temp->lchild=n2;
                temp->rchild=n1;
               pusht(temp);
                }
            }
                
        else{   
               if(getToken(stack[topc])> getToken(infix[i]) && topc!=-1 &&topt!=-1)
             {
               char op=pop();
               n1=popn();
               n2=popn(); 
                temp->data=op;
                temp->lchild=n2;
                temp->rchild=n1;
               pusht(temp);
             }
                push(infix[i]);  
           
         } 
   i++;    
}
//this while loop skipped in the word doc(very imp)
while (topc != -1) {
        char op = pop();
        n1 = popn();
        n2 = popn();
        temp = (struct btree*)malloc(sizeof(struct btree));
        temp->data = op;
        temp->lchild = n2;
        temp->rchild = n1;
        pusht(temp);
    }
/////
root=popn();
printf("the display of the infix expression tree\n");
inorder(root);
printf("\n");
 preorder(root);
 printf("\n");
 postorder(root);
    return 0;
}
