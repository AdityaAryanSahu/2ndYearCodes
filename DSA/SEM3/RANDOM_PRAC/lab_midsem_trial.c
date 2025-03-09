#include <stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char **str;
    int size;
}STRING;

void findlongestword(STRING *st,int index,char** longest){
if(index>=st->size)
return;
if(index==0){
strcpy(*longest,st->str[index]);
}
else if(strlen(st->str[index])>strlen(*longest)){
    strcpy(*longest,st->str[index]);
}
  findlongestword(st,index+1,longest);

}
void display(char *longest){
    printf("longest word is:\n");
    printf("%s",longest);
}
int main(){
    STRING s;
    char si[50];
    scanf("%d",&s.size);
     getchar();
    int i;
   
        s.str=(char**)calloc(s.size,sizeof(char*));
        for(i=0;i<s.size;i++){
            printf("enter word %d\n",(i+1));
            fgets(si,50,stdin);
            s.str[i]=(char*)calloc(strlen(si)+1,sizeof(char));
            strcpy(s.str[i],si);
        }
        char *longest=NULL;
        longest=(char*)calloc(50,sizeof(char));
        findlongestword(&s,0,&longest);
        display(longest);
        for(i=0;i<s.size;i++)
        free(s.str[i]);

        free(s.str);
    
}