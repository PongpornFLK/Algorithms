#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a); 
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    double sum = 0;
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }

    printf("%.2f", sum / k);

    return 0;
}


