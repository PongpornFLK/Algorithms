#include <iostream>

using namespace std;

int arry[100];

int main(){

	int n , k;
	cin >> n >> k;	
	
	// input array
	for(int i = 0 ; i < n ; i++ ){ 
		cin >> arry[i];	
	}	
	
	// find the subarray with the maximum sum
	int x,y;
	
	for(int i = 0 ; i < n ; i++ ){
		int sum = 0;
		for(int j = i+1 ; j < n ; j++){
			sum += arry[j];
			if( sum > k){
				k = sum;
				x = i;
				y = j;
			}
		}
	}

	// output	
	cout << "{ ";
	for(int i = 0; i < y ;i++){
		cout << arry[i] << " ";
	}
	cout<< "}" << endl;
	cout << k ;
	

	return 0;
}