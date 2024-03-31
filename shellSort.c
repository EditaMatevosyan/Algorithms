#include <stdio.h>

void shellsort(int arr[], int n);

int main() {
    int arr[] = {14, 54, 23, 13, -9, -3, 12, -17, 0};
    int n = 9;
    shellsort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void shellsort(int arr[], int n){
   int gap, j, k;
   for(gap = n/2; gap > 0; gap = gap / 2) { 
      for(j = gap; j<n; j++) {
         for(k = j-gap; k>=0; k -= gap) {
            if(arr[k+gap] >= arr[k])
               break;
            else {
               int temp;
               temp = arr[k+gap];
               arr[k+gap] = arr[k];
               arr[k] = temp;
            }
         }
      }
   }
}