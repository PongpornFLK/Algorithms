// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

int seq(int arr[],int k,int n){
    int i = 0;
    
    while((arr[i] != k) && ( i < n)){
        i++;
    }
    if(i < n){
        return i;
    }
    else{
        return -1;
    }
    
}

int main() {
    
    int arr[100];
    int n;
    cin >> n;
    
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    
    int tar = 10;
    int result = seq(arr,tar,n);
    
    if( result != -1){
        cout << result;
    }else{
        cout << "Not Found";
    }

    return 0;
}
