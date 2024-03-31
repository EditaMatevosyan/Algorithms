#include <stdio.h>

void insertionSort(int arr[], int n);

int main() {
    int arr[] = {14, 23, 9, 5, 10, 8};
    int n = 6;
    insertionSort(arr, n);
    
    for(int i = 0; i < n; i++) {
        printf("%d \n", arr[i]);
    }

    return 0;
}

void insertionSort(int arr[], int n){
    int i, key, j;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
