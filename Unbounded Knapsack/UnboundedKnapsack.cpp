#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int knapsack(int W,int w[],int v[],int n){
    for (size_t i = 0; i <= n; i++)
    {
        for (size_t j = 0; j<=n; j++)
        {
            if(i==0 || j==0) dp[i][j]=0;
            else if(w[i-1]<=W){
                // selecting choice
                dp[i][j] = max(v[i-1]+dp[i][j-w[i-1]],dp[i-1][j]);
            }
            else{
                // rejecting choice
                dp[i][j]=dp[i-1][j];
            }
        }
        
    }
    return dp[n][W];
    
}

int main(){
int W;
cin>>W;
int n;
cin>>n;
int w[n],v[n];
for (size_t i = 0; i < n; i++)
cin>>w[i]>>v[i];

int maxvalue=0;
cout<<knapsack(W,w,v,n);
    return 0;
}