// ปรับปรุงอัลกอริทึม Quick Sort จากสไลด์โดยใช้วิธีการค้นหา pivot แบบ median-of-three
// ข้อมูลนำเข้า
// บรรทัดที่ 1 จำนวนเต็ม n แทนจำนวนข้อมูลในอาร์เรย์ A โดยที่ 1 < n < 500
// บรรทัดที่ 2 รายการสมาชิกในอาร์เรย์ A คั่นด้วยช่องว่าง -10,000 <= A[i] <= 10,000
// ข้อมูลส่งออก
// บรรทัดที่ 1 รายการตำแหน่งของ pivot ในแต่ละรอบ คั่นด้วยช่องว่าง
// บรรทัดที่ 2 แสดงผลลัพธ์ของ Quick Sort หลังเรียงลำดับแล้ว
// ตัวอย่างข้อมูลนำเข้า 
// 8
// 16 25 2 54 36 9 12 66
// ตัวอย่างข้อมูลส่งออก
// 7 2 4 5
// 2 9 12 16 25 36 54 66


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int medianOfThree(vector<int> &A, int low, int high) {
    int mid = low + (high - low) / 2;
    if (A[low] > A[mid]) swap(A[low], A[mid]);
    if (A[low] > A[high]) swap(A[low], A[high]);
    if (A[mid] > A[high]) swap(A[mid], A[high]);
    return high - 1;
        return mid;
    } else if ((A[mid] < A[low] && A[low] < A[high]) || (A[high] < A[low] && A[low] < A[mid])) {
        return low;
    } else {
        return high;
    }
}

int partition(vector<int> &A, int low, int high) {
    int pivotIndex = medianOfThree(A, low, high);
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
// Function to perform Quick Sort on the array
// Parameters:
// A - the array to be sorted
// low - the starting index of the array segment to be sorted
// high - the ending index of the array segment to be sorted
void quickSort(vector<int> &A, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(A, low, high);
        quickSort(A, low, pivotIndex-1);
        quickSort(A, pivotIndex+1, high);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    quickSort(A, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
