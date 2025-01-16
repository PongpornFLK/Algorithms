#include <bits/stdc++.h>
using namespace std;

int medianOfThree(int arr[], int left, int right) {
    int mid = left + (right - left) / 2;

    if (arr[left] > arr[mid]) swap(arr[left], arr[mid]);
    if (arr[left] > arr[right]) swap(arr[left], arr[right]);
    if (arr[mid] > arr[right]) swap(arr[mid], arr[right]);

    return arr[mid]; // คืนค่าค่า median
}

int partition(int arr[], int left, int right) {
    int pivotValue = medianOfThree(arr, left, right); 
    cout << pivotValue << " "; 
    int l = left, r = right;

    while (l <= r) {
        while (arr[l] < pivotValue) l++;
        while (arr[r] > pivotValue) r--;

        if (l <= r) {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }
    return l; 
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int partitionIndex = partition(arr, left, right); 
        quickSort(arr, left, partitionIndex - 1);         
        quickSort(arr, partitionIndex, right);          
    }
}

int main() {
    int n;
    cin >> n; 
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }

    quickSort(arr, 0, n - 1);
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

