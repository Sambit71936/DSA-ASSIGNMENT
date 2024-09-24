#include<stdio.h>
#include<stdlib.h>

int main()
{

    int r,c,i,j,k;
    printf("enter no of rows:");
    scanf("%d",&r);
    printf("enter no of colomns:");
    scanf("%d",&c);

    int **a=(int**)malloc(r* sizeof(int*));
    for(i=0;i<r;i++){
        a[i]=(int*)malloc(c*sizeof(int));
    }

    int **b=(int**)malloc(r*sizeof(int*));
    for(i=0;i<r;i++){
        b[i]=(int*)malloc(c*sizeof(int));
    }

    int **mul =(int**)malloc(r*sizeof(int*));
    for(i=0;i<r;i++){
        mul[i]=(int*)malloc(c*sizeof(int));
    }

    printf("enter matrix 1 values:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("enter matrix 2 value:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&b[i][j]);
        }
    }

    printf("matrix multiplication:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            mul[i][j]=0;
            for(k=0;k<c;k++){
                mul[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d\t",mul[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<r;i++){
        free(a[i]);
        free(b[i]);
    }
    free(a);
    free(b);
    free(mul);
    return 0;  
}
