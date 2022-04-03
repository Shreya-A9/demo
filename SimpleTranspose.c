#include<stdio.h>
 
#define MAX 20
 
void printsparse(int[][3]);
void readsparse(int[][3]);
void transpose(int[][3],int[][3]);
 
int main()
{
    int a[MAX][3],b[MAX][3],m,n;
    
    printf("Enter the number of rows = ");
    scanf("%d",&m);
    printf("Enter the number of columns = ");
    scanf("%d",&n);

    a[0][0]=m;
    a[0][1]=n;

    readsparse(a);
    transpose(a,b);
    printsparse(b);
}
 
void readsparse(int c[MAX][3])
{
    int i,n;
    printf("Enter number of non-zero elements = ");
    scanf("%d",&n);
    c[0][2]=n;
    for(i=1;i<=n;i++)
    {
        printf("Enter the next triple row,column,value = ");
        scanf("%d%d%d",&c[i][0],&c[i][1],&c[i][2]);
    }
}
 
void printsparse(int c[MAX][3])
{
    int i,n;
    n=c[0][2]; 
    printf("\nThe matrix after Transpose =\n");
    printf("\nrow\t|\tcolumn\t |\tvalue\n");
    for(i=0;i<=n;i++)
    {
        printf(" %d \t|\t %d \t |\t %d \n",c[i][0],c[i][1],c[i][2]);
    }
}
 
void transpose(int a[][3],int b[][3])
{
    int i,j,k,n;
    b[0][0]=a[0][1];
    b[0][1]=a[0][0];
    b[0][2]=a[0][2];
    k=1;
    n=a[0][2];
    for(i=0;i<a[0][1];i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==a[j][1])
            {
                b[k][0]=i;
                b[k][1]=a[j][0];
                b[k][2]=a[j][2];
                k++;
            }
        }
    }
}