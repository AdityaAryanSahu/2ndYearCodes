#include <stdio.h>
#define max 10

typedef struct {
    int top;
    int data[max];
} stack;

stack s;

int graph[max][max];
int lastvisited[max] = {0};  
int n;
int pop_order[max];
int k=0;

void push(int n) {
    s.top += 1;
    s.data[s.top] = n;
}

int pop() {
    return s.data[s.top--];
}

void dfs(int start) {
    push(start); 
    lastvisited[start] = 1;  
  
    while (s.top != -1) {
        int currentNode = pop();  
          printf("%d\t", currentNode); 
        for (int i = 0; i < n; i++) {
            if (graph[currentNode][i] == 1 && lastvisited[i] == 0) {
                push(i); 
                lastvisited[i] = 1;  
               
            }
        }
        pop_order[k++]=currentNode;

    }
}

int main() {
    s.top = -1;  

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("DFS Traversal:\n");
    for (int i = 0; i < n; i++) {
        if (lastvisited[i] == 0) {  
            dfs(i);
        }
    }
   printf("\n");
    for(int i=k-1;i>=0;i--)
    printf("%d ",pop_order[i]);

    return 0;
}
