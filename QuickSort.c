#include<stdio.h>
void quicksort(int array[25],int start,int end){
   int i, j, pivot, temp;

   if(start<end){
      pivot=start;
      i=start;
      j=end;

      while(i<j){
         while(array[i]<=array[pivot]&&i<end)
            i++;
         while(array[j]>array[pivot])
            j--;
         if(i<j){
            temp = array[i];
            array[i] = array[j];
            array[j]=temp;
         }
      }

      temp = array[pivot];
      array[pivot] = array[j];
      array[j]=temp;
      quicksort(array,start,j-1);
      quicksort(array,j+1,end);

   }
}

int main()
{
   int i, c, array[25];

   printf("\n --- Quick Sort --- \n");
   printf("Enter the size of array = ");
   scanf("%d",&c);

   printf("Enter %d elements = \n", c);
   for(i=0;i<c;i++)
   {
       scanf("%d",&array[i]);
   }
   quicksort(array,0,c-1);

   printf("The Sorted array = ");
   for(i=0;i<c;i++)
   {
       printf(" %d",array[i]);
   }
}