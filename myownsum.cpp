#include "bits/stdc++.h"
using namespace std;

void sum(int arr[],int sum){

    int n=sizeof(arr)/sizeof(arr[0]);
    bool t[n+1][sum+1];

    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0) t[0][j]==false;
            else if(j==0) t[i][0]== true;

            else if(arr[i+1]<=j){
                t[i][j] = t[i][j-arr[i-1]];
            }
        }


    }
    cout<<t;


}

int main(){

    int set[] = { 3, 34, 4, 12, 5, 2 };
	int sum = 9;
    sum(set,sum);

    return 0;
    
}