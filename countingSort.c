#include <stdio.h>

void countingSort(int arr[], int n, int range);

int main() {
    int arr[] = {14, 54, 23, 13, -9, -3, 12, -17, 0};
    int n = 9;

    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    int range = max - min + 1;
    for (int i = 0; i < n; i++) {
        arr[i] -= min;
    }
    countingSort(arr, n, range);
    for (int i = 0; i < n; i++) {
        arr[i] += min;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void countingSort(int arr[], int n, int range) {
    int count[range];
    int output[n];

    for (int i = 0; i < range; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}