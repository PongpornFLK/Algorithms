#include <bits/stdc++.h>
using namespace std;

int v[4] = {12 , 5 , 4 ,2};
int w[4] = {8 , 7 , 4 ,2};
int max_w = 18;
int max_v = -99; // 11


void print_sol(int x[], int n) {
	int sum_w = 0;
	int sum_v = 0;
	
    for (int i = 1; i <= n; i++) {
        if(x[i] == 1){
        	sum_w = sum_w + w[i-1]; //13
        	sum_v = sum_v + v[i-1]; //11	
		}
    }
    
    if(sum_w <= max_w){ // 13 <= 18
    	max_v = max(sum_v , max_v); // 11 > -99	
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
	cout << max_v ;
    return 0;
}                                                                      