#include <stdio.h>
void main()
{ 
    int array[10],i, j, n, temp, keynum, low, mid, high;
    printf("Enter the size of array = ");
    scanf("%d", &n);
    printf("Enter %d elements of array = \n",n);
    for (i=0; i<n; i++)
    {
        scanf("%d", &array[i]);
    }
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < (n - i - 1); j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    printf("\n --- Bubble sort --- \n");
    printf(" Sorted array = \n");
    for (i = 0; i < n; i++)
    {
        printf(" %d ", array[i]);
    }

    printf("\n");
    printf("\n --- Binary Search --- \n");
    printf("Enter the element which is to be searched = ");
    scanf("%d", &keynum);
        low = 1;
    high = n;
    do
    {
        mid = (low + high) / 2;
        if (keynum < array[mid])
            high = mid - 1;
        else if (keynum > array[mid])
            low = mid + 1;
    } while (keynum != array[mid] && low <= high);
    if (keynum == array[mid])
    {
        printf("%d found at index %d", keynum, mid+2);
    }
    else
    {
        printf("\nThe element which you are trying to search is not found!\n%d is not present in the array\n", keynum);
    }

// low = 0;
// high = n - 1;
// mid = (low+high)/2;
// while (low <= high) 
//   {
//     if(array[mid]<keynum)
//     {
//         low = mid+1;
//     }
//     else if (array[mid] == keynum)
//     {
//         printf("%d found at index %d", keynum, mid+1);
//         break;
//     }
//     else
//     {
//         high = mid - 1;
//         mid = (low + high)/2;
//     }
//     if(low > high)
//     {
//         printf("\nThe element which you are trying to search is not found!\n%d is not present in the array\n", keynum);
//     }
//   }
    
    printf("\n");
    printf("\n --- Linear Search --- \n");
    printf(" Enter the element which is to be searched = ");
    scanf("%d",&keynum);
     
    for(i=0;i<n;i++)
    {
        if(array[i]==keynum)
            break;
    }
        
    if(i<n)
    {
        printf("%d found at index %d",keynum,i);
    }
        
    else
    {
        printf("The element which you are trying to search is not found!\n%d is not present in the array", keynum);
    }
}


