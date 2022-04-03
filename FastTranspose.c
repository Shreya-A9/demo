#include <stdio.h>
int r, c;

void accept(int a1[10][10])
{
    int i, j;
    printf("Enter the Rows and Columns = n");
    scanf("%d%d", &r, &c);
    printf("Enter the element\n");
    for(i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &a1[i][j]);
        }
    }
}

void display(int a1[10][10], int r,int c)
{
    int i, j;
    for(i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d\t", a1[i][j]);
        }
        printf("\n");
    }
}

void convert(int a[10][10], int b[10][10], int r, int c)
{
    int i, j, k = 1;
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
            {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
    }
    b[0][0] = r;
    b[0][1] = c;
    b[0][2] = k - 1;
}

void sparseTranspose(int b1[][3],int b2[][3])
{
    int i, j, k, n;
    b2[0][0] = b1[0][1];
    b2[0][1] = b1[0][0];
    b2[0][2] = b1[0][2];
    k = 1;
    n = b1[0][2];
    for(i = 0; i < b1[0][1]; i++)
        for(j = 1; j <= n; j++)
            if (i == b1[j][1])
            {
                b2[k][0] = i;
                b2[k][1] = b1[j][0];
                b2[k][2] = b1[j][2];
                k++;
            }

     for(i=0 ;i<n; i++)  
    {  
        for(j=0; j<3; j++)  
        {  
            printf("%d ", b2[i][j]);  
            printf("\t");  
        }  
        printf("\n");  
    } 

}

void fast(int B[10][10], int C[10][10])
{
    int i, j, m, n, pos[3] = {0, 0, 0}, count[3] = {0, 0, 0};
    for(i = 1; i <= B[0][2]; i++)
    {
        m = B[i][1];
        count[m]++;
    }
    pos[0] = 1;
    for(i = 1; i < B[0][1]; i++)
    {
        pos[i] = pos[i - 1] + count[i - 1];
    }
    for(i = 1; i <= B[0][2]; i++)
    {
        m = B[i][1];
        n = pos[m];
        pos[m]++;
        C[n][0] = B[i][1];
        C[n][1] = B[i][0];
        C[n][2] = B[i][2];
    }
    C[0][0] = B[0][0];
    C[0][1] = B[0][1];
    C[0][2] = B[0][2];
}

int main()
{
    int a[10][10], b[10][10], c[10][10], d[10][10], e[10][10];
    accept(a);
    printf("The MATRIX = \n");
    display(a, r, c);
    convert(a, b, r, c);
    // printf("The sparse matrix is \n");
    // display(b, b[0][2] + 1, 3);
    fast(b, c);
    printf("The transpose of sparse matrix is\n");
    display(c, c[0][2] + 1, 3);
}