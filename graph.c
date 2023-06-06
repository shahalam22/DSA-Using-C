#include <stdio.h>

int n;

//function to find indegree
int indegree(int arr[][n], int m){
    int count = 0;
    for(int i=0; i<n; i++){
        count += arr[m][i];
    }
    return count;
}

//function to find outdegree
int outdegree(int arr[][n], int m){
    int count = 0;
    for(int i=0; i<n; i++){
        count += arr[i][m];
    }
    return count;
}


int main(void){

    printf("Enter number of node - ");
    scanf("%d", &n);

    int arr[n][n];

    printf("Enter Graph [in matrix form] - \n");
    //creating graph
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    
    printf("Graph is [in matrix form] - \n");
    //printing graph
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    int inD = indegree(arr, 1);
    int outD = outdegree(arr, 1);
    printf("INDEGREE is - %d.\n", inD);
    printf("INDEGREE is - %d.\n", outD);

    return 0;
}