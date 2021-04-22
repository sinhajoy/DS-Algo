#include "bits/stdc++.h"
using namespace std;

bool subset(int arr[],int sum,int n){

    bool dp[n+1][sum+1];
    for (int i = 0; i <= n; i++)
		dp[i][0] = true;
	for (int i = 1; i <= sum; i++)
		dp[0][i] = false;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(arr[i-1]<=j){
                dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            }
            if(arr[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];

}

int main(){
    int arr[]={1,5,5,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum=11;
    if(subset(arr,sum,n)){
        cout<< "True";
    }
    else{
        cout << "Not Possible";
    }
    
    return 1;
}