#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int a[], int length)
{
  bool swapped = false;
  int i = 0;
  
  do 
  {
    swapped = false;

    for (int j = 0; j < (length - 1 - i); j++)
    {
      if (a[j] < a[j + 1])
      {
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
        swapped = true;
      } 
    }
    i++;
  } while (swapped);
}

int main()
{
    int arr[] = {14, 54, 23, 13, -9, -3, 12, -17, 0};
    int n = 9;
    bubblesort(arr, n);
    for(int i = 0; i < n; i++){
        printf("%d \n", arr[i]);
    }
    
    return 0;
}

