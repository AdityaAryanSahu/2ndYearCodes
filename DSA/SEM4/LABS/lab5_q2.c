#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* createR(int e){
    int ch,d;
    if(e!=-1){
    struct TreeNode*newnode=(struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    newnode->val=e;
    printf("press # to stop\n");
    printf("enter data for lchild\n");
    scanf("%d",&d);
    newnode->left=createR(d);
    printf("enter data for rchild\n");
    scanf("%d",&d);
    newnode->right=createR(d);
    return newnode;
    }
    return 0;
}

struct TreeNode* findLCA(struct TreeNode* root, int n1, int n2) {

    if (root == NULL) {
        return NULL;
    }
    if (root->val == n1 || root->val == n2) {
        return root;
    }
    struct TreeNode* leftLCA = findLCA(root->left, n1, n2);
    struct TreeNode* rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA != NULL && rightLCA != NULL) {
        return root;
    }
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {
   
    struct TreeNode* root=NULL;
     int c;
   printf("enter data fir first node (press # to not create a tree)\n");
    scanf("%d",&c);
    root=createR(c);
    int n1,n2;
    printf("enter nodes\n");
    scanf("%d%d",&n1,&n2);
    struct TreeNode* lca=findLCA(root,n1,n2);
    if(lca)
    printf("lca of %d and %d is %d\n",n1,n2,lca->val);
    else printf("no lca"); 
    
    return 0;
}
