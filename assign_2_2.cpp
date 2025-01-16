#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = a[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = a[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k++] = L[i++];
        } else {
            a[k++] = R[j++];
        }
    }

    while (i < n1) {
        a[k++] = L[i++];
    }
    while (j < n2) {
        a[k++] = R[j++];
    }
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }
}

void cal(int a[], int n, int x) {
    int temp = INT_MAX;
    int l = 0, r = n - 1;

    while (l < r) {
        int sum = a[l] + a[r];
        if (sum == x) {
            int result = a[r] - a[l];
            if (result < temp) {
                temp = result;
            }
            l++;
            r--;
        } else if (sum < x) {
            l++;
        } else {
            r--;
        }
    }

    if (temp == INT_MAX) {
        cout << "No valid pair found." << endl;
    } else {
        cout << temp << endl;
    }
}

int main() {
    int n, x;
    cin >> n >> x;

    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    mergeSort(A, 0, n - 1);
    cal(A, n, x);

    return 0;
}


