#include <stdio.h>
#include <string.h>

#define max 10000;

char color[100][10];
int n, time = 0, size = 0;
int prev[100], d[100], f[100], val[100];

//  code for dfs
void dfs(int graph[][n], int k){

    strcpy(color[k], "Grey");
    time = time + 1;
    d[k] = time;
    
    //storing values in a array
    val[size] = k;
    size++;

    for(int j=0; j<n; j++){
        if((graph[k][j] == 1) && (!strcmp(color[j], "White"))){
            prev[j] = k;
            dfs(graph, j);
        }
    }

    strcpy(color[k], "Black");
    time = time + 1;
    f[k] = time;

}

//topological sort code
void topologicalSort(int f[], int ts[]){
    int min = max;
    int minIndx = 0, size = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(f[j]<min){
                min = f[j];
                minIndx = j;
            }
        }
        f[minIndx] = max;
        min = max;
        ts[size] = minIndx;
        size++;
    }

    printf("Topological sort - \n");
    for(int i=0; i<n; i++){
        printf("%d ", ts[i]);
    }
}

//  main function

int main(void){

    printf("Enter number of node - ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        strcpy(color[i], "White");
        prev[i] = max;
        f[i] = max;
        d[i] = max;
    }

    int arr[n][n];

    //creating graph
    printf("Enter Graph [in matrix form] - \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    dfs(arr, 0);

//  topological sort code
    int ts[n];
    topologicalSort(f, ts);

    return 0;
}