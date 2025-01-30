#include <stdio.h>
#include <stdlib.h>

int countTarget(int *arr, int target, int left, int right) {
    if (left > right) return 0; 

    int mid = left + (right - left) / 2; 
    int count = 0;

    if (arr[mid] == target) {
        count = 1;
    }

    count += countTarget(arr, target, left, mid - 1);
    count += countTarget(arr, target, mid + 1, right);

    return count;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
 
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);

    int result = countTarget(arr, target, 0, n - 1);
    if (result == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", result);
    }

    free(arr);

    return 0;
}

