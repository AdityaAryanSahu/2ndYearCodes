#include<stdio.h>
#define max 10


int visited[max]={0};
int graph[max][max];
int q[max];
int n;

void bfs(int start){
      int f=0,r=0;
      visited[start]=1;
      q[r++]=start;
      while(f<r){
        int vertex=q[f++];
        printf("%d\t",vertex);
        for(int i=0;i<n;i++)
         if(graph[vertex][i]==1&& !visited[i]){
            visited[i]=1;
            q[r++]=i;
         }
      }
}
int main(){
    printf("enter number of node\n");
    scanf("%d",&n);
    printf("enter adjency matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("visited order\n");
    for(int i=0;i<n;i++){
    if(visited[i]==0)
    bfs(i);}
}