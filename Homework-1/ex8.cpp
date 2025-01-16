#include <iostream>

using namespace std;

int arry[100];

int main(){

	int n ;
	cin >> n ;	
	
	for(int i = 0 ; i < n ; i++ ){ 
		cin >> arry[i];	
	}	
	
	int x,y;
	int k = 0;
	
	for(int i = 0 ; i < n ; i++ ){
		int sum = 0;
		for(int j = i ; j < n ; j++){
			sum += arry[j];
			if( sum > k){
				k = sum;
				x = i;
				y = j;
			}
		}
	}
	
	cout << k;

	return 0;
}
