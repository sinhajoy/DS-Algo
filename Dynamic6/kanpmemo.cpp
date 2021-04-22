#include "bits/stdc++.h"

using namespace std;

int profit_top_down(int wt[],int val[],int W,int n){
    int t[n+1][W+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;i<W+1;j++){
            if(i==0 || j==0) t[i][j]=0;  // Base Condition

            if(wt[i-1]<=j){
                t[i][j]=max(val[i-1]+
                            t[i-1][j-wt[i-1]],
                            t[i-1][j]);

            }
            else{
                t[i][j]=t[i-1][j];
            }


        }
    }
    return t[n][W];
}

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                                K[i - 1][w - wt[i - 1]],
                                K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}



int main(){

    int arr[] = {5,6,7,8,9};
    int val[] = {2,4,3,5,7};
    int x=14;
    //memset(dp,-1,sizeof(dp));
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = knapSack(x,arr,val,n);
    //int ans2 = profit_top_down(arr,val,x,n);
    cout << ans <<endl;
    //cout << ans2 << endl;
    return 0;
}

//Maximum Profif == 9