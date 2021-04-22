#include "bits/stdc++.h"

using namespace std;

int max_profit(int arr[],int val[],int W,int n){
    
    
    if(n==0 || W==0) return 0; // Base Condition
    
    
    if(arr[n-1]<=W){
        return max(val[n-1]+max_profit(arr,val,W-arr[n-1],n-1), max_profit(arr,val,W,n-1));     //Choice Diagram implementation
    }
    else if(arr[n-1]>W){
        return max_profit(arr,val,W,n-1);
    }
}



int main(){

    int arr[] = {5,6,7,8,9};
    int val[] = {2,4,3,5,7};
    int x=14;
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = max_profit(arr,val,x,n);
    cout << ans;
    return 0;

}