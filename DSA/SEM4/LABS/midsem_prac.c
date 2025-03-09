

//partition problem

int subset_size,subset[],array[],index,subset_sum,array_size,total_sum;

int partiton(int subset_size,int index,int subset_sum){
    if(subset_sum==total_sum/2){
        printf("yayyy\n");
        for(int i=0;i<subset_size;i++) printf("%d ",subset[i]);
        return 1;
    }
    if(subset_sum>total_sum/2|| index>=array_size) return 0;

    subset[subset_size]=array[index];
    if(partiton(subset_size+1,index+1,subset_sum+array[index]))
    return 1;
    return partiton(subset_size,index+1,subset_sum);

}
partiton(0,0,0);

//assignment problem
int array[][],n,min_cost=INT_MAX;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int cost_calc(int perm[]){
    int cost=0;
    for(int i=0;i<n;i++){
       cost+=array[i][perm[i]];
    }
    return cost;
}

void permutat(int perm[],int start,int end){
    if(start==end){
        int cost=cost_calc(perm);
        if(cost<min_cost){
            min_cost=cost; 
        }
        return;
    }
    for(int i=0;i<end;i++){
        swap(&perm[i],&perm[start]);
        permutat(perm,start+1,end);
        swap(&perm[start],&perm[i]);
    }

}
for(int i=0;i<n;i++) perm[i]=i;
permutat(perm,0,0);


//dfs

typedef struct{
    int data[];
    int top;
}STACK;
STACK s;
void push(int e){
    s.data[++s.top]=e;
}

int pop(){
    return s.data[s.top--];
}
int graph[][],visited[]={0},n;

void dfs(int start){
    push(start);
    visited[start]=1;
    while(s.top!=-1){
        int current_node=pop();
        printf("%d ",current_node);
        for(int i=0;i<n;i++){
            if(visited[i]!=1&& graph[current_node][i]==1){
                push(i);
                visited[i]=1;
            }
        }
    }
}

//bfs
int graph[][],q[],visited[]={0},n;

void bfs(int start){
    int r=0,f=0;
     visited[start]=1;
     q[r++]=start;
     while(f!=r){
        int current_node=q[f++];
        for(int i=0;i<n;i++){
            if(graph[current_node][i]==1 && visited[i]!=1)
            {
                q[r++]=i;
                visited[i]=1;
            }
        }
     }
}

//insertion sort
int array[],n;
void insert_sort(){
    for(int i=1;i<n;i++){
        int j=i-1;
        int p=array[i];
        while(j>=0&& array[j]>p){
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=p;
    }
}

//merge dort

int n;
int count=0;
void merge(int array[],int s,int m,int l){
    int n1=m-s+1;
    int n2=l-m;
   int a1[n1],a2[n2];
    for(int i=0;i<n1;i++) a1[i]=array[s+i];
    for(int i=0;i<n2;i++) a2[i]=array[m+1+i];

    int i=0,j=0;
    int k=s;
    while(i<n1&&j<n2){
        if(a1[i]<=a2[j]) array[k++]=a1[i++];
        else {
            array[k++]=a2[j];
            count=count+(n1-i);
            j++;
        }
    }
    while(i<n1){
        array[k++]=a1[i++];
    }
    while(j<n2){
        array[k++]=a2[j++];
    }
}

void mergesort(int array[],int s,int l){
    if(s>=l) return;
    int mid=s+(l-s)/2;
    mergesort(array,s,mid);
    mergesort(array,mid+1,l);
    merge(array,s,mid,l);
}
mergesort(array,0,n-1);

//quick sort
int partiton(int array[],int s,int l){
    int p=array[l];
    int i=s-1;

    for(int j=s;j<l;j++){
        if(array[j]<=p){
            i++;
            int temp=array[j];
            array[j]=array[i];
            array[i]=temp;
        }

    }
    int temp=array[i+1];
    array[i+1]=p;
    array[l]=temp;
    return (i+1);
}

void quicksort(int array[],int s,int l){
    if (s >= l) return;
    int p=partiton(array,s,l);
    quicksort(array,s,p-1);
    quicksort(array,p+1,l);
}