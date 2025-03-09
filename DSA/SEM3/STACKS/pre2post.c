#include<stdio.h>
#include<string.h>
#define max 20
char stack[50][50];
int top = -1;

void clear_stack() {
    top = -1 ;
}

void push(char *s)
{
    strcpy(stack[++top], s) ;
}

char* pop()
{
    return stack[top--];
}


int is_operator(char x)
{
    if(x == '+' ||x == '-'||x == '*'||x == '/'){
        return 1;
    }
    else{
        return 0;
    }
}


//function to Convert prefix to Postfix
void convert(char *exp)
{
    clear_stack() ;

    int i,l;
    char op1[50],op2[50],temp[100];

    l = strlen(exp);

    //scanning from right to left
    for(i = l - 1; i >= 0; i--)
    {
        //checking if the symbol is an operator
        if (is_operator(exp[i]))
        {
            //popping two operands from stack
            strcpy(op1, pop()) ;
            strcpy(op2, pop()) ;
            //concating the operands and operator
           sprintf(temp,"%s%s%c",op1,op2,exp[i]);
            //Pushing the temporary string to stack
            push(temp);
        }
        //if it is an operand
        else
        {
            //push the operand to the stack
            sprintf(temp,"%c",exp[i]);
            push(temp);
        }
    }
    printf("%s\n",stack[top]);
}


int main()
{
    char prefix[max];
    printf("enter exp\n");
    gets(prefix);
    convert(prefix);
   
    return 0;
}