#include "bits/stdc++.h"

using namespace std;

int static dp[100][100];
int max_profit(int arr[],int val[],int W,int n){
    
    if(n==0 || W==0) return 0; // Base Condition
    if(dp[n][W]!=-1) return dp[n][W];
    
    
    if(arr[n-1]<=W){
        return dp[n][W]=max(val[n-1]+max_profit(arr,val,W-arr[n-1],n-1), max_profit(arr,val,W,n-1));     //Choice Diagram implementation
    }
    else if(arr[n-1]>W){
        return dp[n][W]=max_profit(arr,val,W,n-1);
    }
}

int profit_top_down(int wt[],int val[],int W,int n){


    int t[n+1][W+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;i<W+1;j++){
            if(i==0 || j==0) t[i][j]=0;  // Base Condition

            if(wt[i-1]<=j){
                t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);

            }
            else if(wt[i-1>j]){
                t[i][j]=t[i-1][j];
            }


        }
    }
    return t[n][W];
}













int main(){

    int arr[] = {5,6,7,8,9};
    int val[] = {2,4,3,5,7};
    int x=14;
    memset(dp,-1,sizeof(dp));
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = max_profit(arr,val,x,n);
    int ans2 = profit_top_down(arr,val,x,n);
    cout << ans <<endl;
    cout << ans2 << endl;
    return 0;
}

//Maximum Profif == 9