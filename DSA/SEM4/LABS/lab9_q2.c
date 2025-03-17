    #include<stdio.h>
    #include <stdlib.h>
    #define max 10

     struct node{
    	int val;
        struct node* next;
    };
    struct node* arr[max];
   int flag=0;
   int count;
    void insert(int e, int idx, struct node **root){
    	struct node* temp=*root;
        struct node* newnode=calloc(1,sizeof(struct node));
        newnode->val=e;
      if(*root==NULL) *root=newnode;
        else{
    	for(temp=*root;temp->next!=NULL;temp=temp->next){}
         temp->next=newnode;
         newnode->next=NULL;
     }
 }

 void search(int v){
     for(int i=0;i<max;i++){
        count=0;
        for(struct node*temp=arr[i];temp!=NULL;temp=temp->next){
            count++;
            if(v==temp->val){
                flag=1;
                printf("found at index %d\n with count: %d\n",i,(count-1));
                break;
            }
        }
        if(flag) break;
     }
     if(!flag) printf("not fpund\n");
 }


    void display(){
    	for(int i=0;i<max;i++){
            struct node*temp1;
            printf("for index %d: ",i);
            if(arr[i]->next==NULL) printf("NULL\n");
    	   for(struct node *temp=arr[i]->next;temp!=NULL;temp=temp->next){
           printf("%d\t",temp->val);
    	   }
           printf("\n");
    	}
    }

    int main(){
        int n,x;

        scanf("%d",&n);
         *arr=calloc(max,sizeof(struct node*));
         for(int i=0;i<max;i++){
            arr[i]=calloc(1,sizeof(struct node));
         }
        for(int i=0;i<n;i++){
            printf("enter a value\n");
            scanf("%d",&x);
            int mod=x%max;
            insert(x,mod,&arr[mod]);
        }
        display();

        printf("enter elemrny to be searchd\n");
        scanf("%d",&x);
        search(x);
    	
    }