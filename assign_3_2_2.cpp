#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int> &A, int low, int high, vector<int> &pivot) {
    int pivotIndex = pivot[pivot.size()-1];
    pivot.pop_back();
    int pivotValue = A[pivotIndex];
    swap(A[pivotIndex], A[high]);
    int i = low;
    for (int j = low; j < high; j++) {
        if (A[j] < pivotValue) {
            swap(A[i], A[j]);
            i++;
        }
    }
    swap(A[i], A[high]);
    return i;
}

void quickSort(vector<int> &A, int low, int high, vector<int> &pivot) {
    if (low < high) {
        int pivotIndex = partition(A, low, high, pivot);
        quickSort(A, low, pivotIndex-1, pivot);
        quickSort(A, pivotIndex+1, high, pivot);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    vector<int> pivot;
    pivot.push_back(0);
    pivot.push_back(n/2);
    pivot.push_back(n-1);
    quickSort(A, 0, n-1, pivot);
    for (int i = 0; i < pivot.size(); i++) {
        cout << pivot[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}

