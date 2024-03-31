#include <stdio.h>

void bucketSort(int arr[], int n, int numBuckets);

int main() {
    int arr[] = {29, 25, 35, 30, 16, 20, 40, 10};
    int n = 8;
    int numBuckets = 5; 

    bucketSort(arr, n, numBuckets);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void bucketSort(int arr[], int n, int numBuckets) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int range = (max + 1) / numBuckets + 1;
    
    int buckets[numBuckets][n];
    int bucketCount[numBuckets];
    for (int i = 0; i < numBuckets; i++) {
        bucketCount[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / range;
        int row = bucketIndex;
        int col = bucketCount[bucketIndex];
        buckets[row][col] = arr[i];
        bucketCount[bucketIndex]++;

    }

    for (int i = 0; i < numBuckets; i++) {
        for (int j = 1; j < bucketCount[i]; j++) {
            int key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}
