#include <stdio.h>

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int main() {
    int arr[] = {29, 25, 35, 30, 16, 20, 40, 10};
    int n = 8;

    for (int i = n / 2 - 1; i >= 0; i--) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;
        if (largest != i) {
            swap(arr, i, largest);
            i = largest;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr, 0, i);
        int largest = 0;
        int left = 2 * largest + 1;
        int right = 2 * largest + 2;
        while (left < i) {
            largest = left;
            if (right < i && arr[right] > arr[largest])
                largest = right;
            if (arr[largest] > arr[0]) {
                swap(arr, 0, largest);
                left = 2 * largest + 1;
                right = 2 * largest + 2;
            } else {
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
