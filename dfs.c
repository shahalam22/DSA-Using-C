#include <stdio.h>
#include <string.h>

#define max 10000;

int n;
int time = 0, size = 0;

int prev[100], d[100], f[100], val[100];
char color[100][10];

//always jeta niye kaj korte bolbe oitake 0 defined dhore kaj korte hobe

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
    
    //printing graph
    printf("Graph is [in matrix form] - \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    dfs(arr, 0);

//  printing final time
    printf("Finish time - ");
    for(int i=0; i<n; i++){
        printf("%d ", f[i]);
    }
    printf("\n");

//  printing dfs array
    printf("dfs-ed - ");
    for(int i=0; i<n; i++){
        printf("%d ", val[i]);
    }
    printf("\n");

    return 0;
}