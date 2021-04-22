#include "bits/stdc++.h"
using namespace std;

int profit(int arr[],int val[],int W,int n){

    int i=0,j=0;
    int dp[n+1][W+1];

    for(i=0;i<=n;i++){
        for(j=0;j<=W;j++){
            if(i==0 || j==0) dp[i][j]= 0;
            
            else if(arr[i-1]<=j){
                dp[i][j]=max(val[i-1]+
                                dp[i-1][j-arr[i-1]],
                                dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];

}



int main(){

    int arr[] = {5,6,7,8,9};
    int val[] = {2,4,3,5,7};
    int x=14;
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = profit(arr,val,x,n);
    cout<< ans;

    return 0;

}