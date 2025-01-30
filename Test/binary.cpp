#include <iostream>

using namespace std;

int binary(int arr[],int n,int k){
	int l = 0 , r = n-1;
	while(l <= r){
		int mid = ( l+r ) / 2;
		if(arr[mid] == k){
			return mid;
		}
		if(arr[mid] < k){
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	return -1;
	
}

int main(){
	
	int arr[100];
	int n;
	int target;
	cin >> n;
	cin >> target;
	
	for(int i = 0 ; i < n ; i++){
		cin >> arr[i];
	}
	
	int result = binary(arr,n,target);
	
	if( result == -1){
		cout << "Not Found";
	}else{
		cout << "Found position : " <<result;
	}
	
	return 0;
}
