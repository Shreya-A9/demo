#include <stdio.h>
int main() {

    int i,j,n,a[100][100],min_r,col,k,max_c;

    printf("Enter the number of Rows and Columns = ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Enter the elements of the matrix a[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    printf("The Entered Matrix = \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("  %d  ",a[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<n;i++)
    {
        min_r =a[i][0];
        col = 0;
        for(j=0;j<n;j++)
        {
            if(a[i][j]<min_r)
            {
                min_r = a[i][j];
                col = j;
            }
        }

        max_c = 0;
        for(k=0;k<n;k++)
        {
            if(a[k][col]>max_c)
            {
                max_c = a[k][col];
            }
        }

        if(min_r == max_c)
        {
            printf("The Saddle point in matrix is %d\n",min_r);
        }
    }
       if(min_r != max_c)
        {
            printf("The matrix has no saddle point");
        }
}    