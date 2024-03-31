#include <stdio.h>

int main()
{
    int arr1[] = {12, 54, 23, 87, 38, 25, 15, -43};
    int n = 8;
    
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        if (arr1[j] > arr1[min]) 
            min = j;
        
        if (min != i)
        {
        int temp = arr1[i];
        arr1[i] = arr1[min];
        arr1[min] = temp;
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", arr1[i]);
    
    return 0;
}