#include<stdio.h>
#define MAX 20

int main()
{
    int m1[MAX][3],m2[MAX][3],r,c,b[MAX][3],b1[MAX][3],b2[MAX][3],a[MAX][3],i,j,k,p,x,m,y,n;
    printf("Enter the size of matrix (rows,columns):");
    scanf("%d%d",&r,&c);
    m1[0][0]=r;
    m2[0][1]=c;
    

printf("\nEnter no. of non-zero elements:");
scanf("%d",&m);
a[0][2]=m;
for(x=1;x<=m;x++)
{
printf("\nEnter the next triple(row,column,value):");
scanf("%d%d%d",&a[x][0],&a[x][1],&a[x][2]);
}


n=a[0][2]; //no of 3-triples
printf("\nAfter Transpose:\n");
printf("\nrow\t\tcolumn\t\tvalue\n");
for(y=0;y<=n;y++)
printf("%d\t\t%d\t\t%d\n",a[y][0],a[y][1],a[y][2]);

b2[0][0]=b1[0][1];
b2[0][1]=b1[0][0];
b2[0][2]=b1[0][2];
k=1;
p=b1[0][2];
for(i=0;i<b1[0][1];i++)
for(j=1;j<=p;j++)
//if a column number of current triple==i then insert the current triple in b2
if(i==b1[j][1])
{
b2[k][0]=i;
b2[k][1]=b1[j][0];
b2[k][2]=b1[j][2];
k++;
}

}
 