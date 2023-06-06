#include <stdio.h>
#include <string.h>

#define max 10000

int n, size = 0, size2 = 0;
char color [100][10]; 
int q[100],  prev[100], val[100];

void bfs(int graph[][n], int s){
    for(int i=0; i<n; i++){
        strcpy(color[i], "White");
        prev[i] = max;
    }

    strcpy(color[s], "Grey");
    q[size] = s;
    size++;

    while(size!=0){
        int a = q[0];
        for(int i=1; i<size; i++){
            q[i-1] = q[i];
        }
        size--;

        for(int i=0; i<n; i++){
            if((graph[a][i] == 1) && (!strcmp(color[i], "White"))){
                strcpy(color[i], "Grey");
                prev[i] = a;
                q[size] = i;
                size++;
            }

        }
        strcpy(color[a], "Black");
        val[size2] = a;
        size2++;
    }

    printf("Printing bfs array - ");
    for(int p=0; p<n; p++){
        printf("%d ", val[p]);
    }
}

// //path printing code
void printPath(int prev[], int a, int b){
    if(a==b){
        printf("%d\t", a);
    }
    else if(prev[b]==max){
        printf("");
    }
    else {
        printPath(prev, a, prev[b]);
        printf("%d\t", b);
    }
}

int main(void){

    printf("Enter number of node - ");
    scanf("%d", &n);

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

    //bfs run
    bfs(arr, 0);
    
    return 0;
}