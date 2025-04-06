#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int graph[MAX][MAX];
 int visited[MAX]={0};


int count;int req_vertex;

int pop_order[MAX];

typedef struct Stack {
    int items[MAX];
    int top;
} Stack;
Stack stack;
void init_stack(Stack* stack) {
    stack->top = -1;
}

int is_empty(Stack* stack) {
    return stack->top == -1;
}


void push(Stack* stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack overflow!\n");
    } else {
        stack->items[++(stack->top)] = value;
        printf("Pushed: %d\n", value);
    }
}

int pop(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    } else {
        int value = stack->items[stack->top--];
        printf("Popped: %d\n", value);
        return value;
    }
}

void dfs(int node, int n) {
    // Mark the current node as visited
    visited[node] = 1;
    
    // Visit all adjacent nodes
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }

    // Push the node onto the stack after visiting all its neighbors
    push(&stack,node);
}

// Function to perform Topological Sort using DFS
void topologicalSort(int n) {
    // Initialize visited array to 0 (unvisited)
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Perform DFS for all unvisited nodes
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n);
        }
    }

    // Print the nodes in the topological order (stack from top to bottom)
    printf("Topological Sort: ");
    while (stack.top > 0) {
        printf("%d ", stack.items[(stack.top)--]);
    }
    printf("\n");
}

void srs(int n) {
    
    for(int i=0;i<n;i++){
        req_vertex=i;count=0;
        for(int j=0;j<n;j++){
            if(graph[j][i]==0&& visited[i]!=1)
                count++;

        }
        if(count==n) break;
    }
    printf("%d\t",req_vertex);
    visited[req_vertex]=1;
   for(int i=0;i<n;i++){
       graph[req_vertex][i]=0;
        }
   }
    


int main() {
    int n, start;
    //visited[MAX]={0};
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
int ch;
   // int graph[MAX][MAX];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }


   printf("enter which method: 1.dfs tp 2.srs tp\n");
   scanf("%d",&ch);
   switch(ch){
       case 1:{
        
         topologicalSort(n);
                    break;
                  }
               
           case 2:{
            int i=1;
            while(i<=n){
            srs(n);i++;
                 }
           }
   }

    return 0;
}
