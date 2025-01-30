#include <bits/stdc++.h>
using namespace std;
int N = 4;
int arr[5] = {-1 , 25 , 10 , 9 , 2 };
int k = 36; 

void print_sol(int x[], int n) {
	int _sum = 0;
    for (int i = 1; i <= n; i++) {
        if(x[i] == 1){
        	_sum = _sum + arr[i];
		}
    }

    
    if(_sum == k){
    	 for (int i = 1; i <= n; i++) {
    	 	if(x[i] == 1) cout << arr[i] << " ";
    }
    cout << endl;
    
	}
}

void subset1(int x[], int l, int r) {
    if (l == r) {
        print_sol(x, r);
    } else {
        x[l + 1] = 1;
        subset1(x, l + 1, r);
        x[l + 1] = 0;
        subset1(x, l + 1, r);
    }
}

int main() {
    int n = 4;            // Number of elements
    int x[n + 1];        // Array to store subset

    subset1(x, 0, n);

    return 0;
}