#include<stdio.h>
#include<stdlib.h>

struct bt{
    int data;
    struct bt*lchild;
struct bt*rchild;
};

int count1,count2,count3,count4;

void inorder(struct bt*root){
 if(root){
    if(root->lchild==NULL && root->rchild==NULL)
    count4++;
    inorder(root->lchild);
    printf("%d\t",root->data);
    count1++;
    inorder(root->rchild);
 }
}

void preorder(struct bt*root){
 if(root){
    printf("%d\t",root->data);
    preorder(root->lchild);
    count2++;
    preorder(root->rchild);
 }
}

void postorder(struct bt*root){
 if(root){
    postorder(root->lchild);
    postorder(root->rchild);
    count3++;
    printf("%d\t",root->data);
 }
}


int search(struct bt*root,int d){
    static int flag=0;
    if(root){
        if(root->data==d){
         flag=1;
        }
       if(flag==0)  search(root->lchild,d);
         if(flag==0) search(root->rchild,d);
    }
    return flag;

}
int max(int a,int b){
    if(a>b) return a;
    else return b;
}

int height(struct bt*root){
if(root){
    return (1+max(height(root->lchild),height(root->rchild)));
}
return 0;
}
int max_ele(struct bt*root){
    static int max=-1;
   
  if(root){
     if(root->data>max)
    max=root->data;
    max_ele(root->lchild);
    max_ele(root->rchild);
  }
  return max;
}
int ances(struct bt*root,int t){
   if(root==NULL) return 0;
   if(root->data==t)return 1;
   if(ances(root->lchild,t)||ances(root->rchild,t)){
      printf("%d\t",root->data); return 1;
   }
}

void descen_pre(struct bt*root,int t){
   static int flag=0;
   if(root){
      if(root->data==t) flag=1;
      if(flag==1) printf("%d\t",root->data);
      descen_pre(root->lchild,t);
      descen_pre(root->rchild,t);
   }
}

void descen_in(struct bt*root,int t){
   static int flag=0;
   if(root){
      descen_in(root->lchild,t);
      if(root->data==t) flag=1;
      if(flag==1) printf("%d\t",root->data);
      descen_in(root->rchild,t);
   }
}

void descen_post(struct bt*root,int t){
   static int flag=0;
   if(root){
      descen_post(root->lchild,t);
      descen_post(root->rchild,t);
      if(root->data==t) flag=1;
      if(flag==1) printf("%d\t",root->data);
   }
}
struct bt* insert(int d){
    struct bt*newnode=(struct bt*)calloc(1,sizeof(struct bt));
    newnode->data=d;
    int x;
    newnode->lchild=newnode->rchild=NULL;
     if(d!=-1){
     printf("enter -1 to stop\n");
     printf("enter data for lchild\n");
     scanf("%d",&x);
     getchar();
     newnode->lchild=insert(x);
     printf("enter data for rchild\n");
     scanf("%d",&x);
     getchar();
     newnode->rchild=insert(x);
     return newnode;
     }
     return NULL;
}

struct bt*cpy(struct bt*root){
 if(root){
    struct bt*newnode=(struct bt*)calloc(1,sizeof(struct bt));
    newnode->data=root->data;
     newnode->lchild=newnode->rchild=NULL;
     newnode->lchild=cpy(root->lchild);
     newnode->rchild=cpy(root->rchild);
     return newnode;
 }
 return NULL;
}
struct bt*mirror(struct bt*root){
 if(root){
    struct bt*newnode=(struct bt*)calloc(1,sizeof(struct bt));
    newnode->data=root->data;
     newnode->lchild=newnode->rchild=NULL;
     newnode->lchild=mirror(root->rchild);
     newnode->rchild=mirror(root->lchild);
     return newnode;
 }
 return NULL;
}
int equal(struct bt* root1,struct bt*root2){
   return((!root1&&!root2)||(root1&&root2&&(root1->data==root2->data)&&
   equal(root1->lchild,root2->lchild)&&equal(root1->rchild,root2->rchild)));
}

int main(){
    struct bt*root=NULL;
   root=insert(2);

   printf("tree in inorder:\n");
   inorder(root);
   printf("\nno of nodes: %d\n",count1);
   printf("\nno of leaf nodes: %d\n",count4);
   printf("\n");

//    printf("tree in postorder:\n");
//    postorder(root);
//    printf("\nno of nodes: %d\n",count1);
//    printf("\n");

//    printf("tree in preorder:\n");
//    preorder(root);
//    printf("\nno of nodes: %d\n",count1);
   printf("\n");
char x;
//    printf("enter a elemrt to be searched\n");
//    scanf("%c",&x);
//   if(search(root,x))
//   printf("%c found\n",x);
 // else printf("not found\n");

  printf("the height of tree is: %d",height(root));

  printf("\nmax is: %d\n",max_ele(root));

  struct bt*root2=NULL,*root3=NULL;
      root2=cpy(root);
      printf("tree2 in inorder:\n");
   inorder(root2);
   printf("\n");

      root3=mirror(root);
      printf("tree3 in inorder:\n");
   inorder(root3);
   printf("\n");
   
      if(equal(root2,root3)){
        printf("t2 &t3 equal\n");
      }
      else printf("t2&t3 not equal\n");

      if(equal(root2,root)){
        printf("t2 &t1 equal\n");
      }
      else printf("t2&t1 not equal\n");

      int f=ances(root,50);
}