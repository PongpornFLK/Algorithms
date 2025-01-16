#include<iostream>
using namespace std;

void interpo(int arr[], int l, int r, int v){

		if(l > r){
			return ;
		}

		int m = l + ((v - arr[l])*(r - l)) / (arr[r] - arr[l]);
		cout << m << " ";
		
		if(arr[m] == v){
			return;
		}
		else if(arr[m] < v){
			return interpo(arr, m +1, r, v);
		}
		else{
			return interpo(arr, l, m-1, v);
		}
				
	}

int main(){
	int n, k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	interpo(arr,0,n-1,k);
	
	return 0;
}
