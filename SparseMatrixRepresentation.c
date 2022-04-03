#include<stdio.h>   
int main() 
{ 
    int i,j,r,c,a[10][10],n=0,k=0;

    printf("Enter the number of Rows = ");
    scanf("%d", &r);

    printf("Enter the number of Columns = ");
    scanf("%d", &c);
    
    printf("Enter the elements of sparse matrix = \n");

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("Enter element a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("The Entered Matrix = \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("  %d  ",a[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if (a[i][j] != 0) 
            {
                n++;
            }
        }
        printf("\n");
    }

    int b[3][n];
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if (a[i][j] != 0) 
            { 
                b[0][k] = i; 
                b[1][k] = j; 
                b[2][k] = a[i][j]; 
                k++; 
            }
        }
    }
    
    printf("The Sparse Matrix Representation = \n");
    for(i=0; i<3; i++) 
    { 
        for(j=0; j<n; j++) 
        {
            printf(" %d ", b[i][j]); 
        }
            printf("\n"); 
    } 
} 