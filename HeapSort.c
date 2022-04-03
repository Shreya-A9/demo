#include <stdio.h>
int main()
{
  int arr[10], n, i, j, c, heap_root, temp;
  printf("\n --- Heap Sort --- \n");
  printf("Enter the size of array = ");
  scanf("%d", &n);

  printf("\n");
  printf("Enter the elements = \n");
  for (i=0; i<n; i++)
  {
    scanf("%d", &arr[i]);
  }
  
  for (i = 1; i <  n; i++)
  {
    c = i;
  do
  {
    heap_root  = (c - 1) / 2;
  if  (arr[heap_root] < arr[c])
  {
  temp =  arr[heap_root];
  arr[heap_root] = arr[c];
  arr[c]  = temp;
  }
  c =  heap_root;
  } while (c != 0);
  }
  
  printf("The Heap  array = ");
  for (i=0; i<n; i++)
  printf(" %d ", arr[i]);
  for (j=n-1; j>=0; j--)
  {
  temp = arr[0];
  arr[0] = arr[j];
  arr[j] = temp;
  heap_root = 0;
  do
  {
  c = 2 * heap_root + 1;
  if  ((arr[c] < arr[c + 1]) && c < j-1)
  c++;
  if  (arr[heap_root]<arr[c] && c<j)
  {
  temp =  arr[heap_root];
  arr[heap_root] = arr[c];
  arr[c]  = temp;
  }
  heap_root  = c;
  } 
  while (c  < j);
  } 
  printf("\n");
  printf("The Sorted  array = ");
  for (i = 0; i <  n; i++)
  printf(" %d ", arr[i]);
  }