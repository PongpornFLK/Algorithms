#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int low, int high, int target) {
    if (low <= high && target >= arr[low] && target <= arr[high]) {

        int mid = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[mid] == target)
            return mid;

        if (arr[mid] > target)
            return interpolationSearch(arr, low, mid - 1, target);

        return interpolationSearch(arr, mid + 1, high, target);
    }
    return -1; // Target not found
}

int main() {
    int n, target;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements (sorted in ascending order): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target value: ";
    cin >> target;

    int result = interpolationSearch(arr, 0, n - 1, target);


    return 0;
}

