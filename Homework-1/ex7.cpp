#include <iostream>

using namespace std;

int arry[1000];
int main(){
	
	int n, k;
	cin >> n >> k;	
	
	for(int i = 0 ; i < n ; i++ ){
		cin >> arry[i];	
	}	
	
	int sum=0;
	for(int i = 0 ; i <= n ; i++ ){
		for(int j = i+1 ; j < n ; j++){
			if((arry[i] + arry[j]) == k){
				cout << arry[i] << " " << arry[j] << endl;
				sum++;
			}
		}
	}
	
	if( sum == 0){
		cout << "-1";
	}
	
}

