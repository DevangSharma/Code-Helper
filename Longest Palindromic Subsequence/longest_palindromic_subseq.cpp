#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int lcs(string a,string b,int n,int m){
    for (size_t i = 0; i <= n; i++)
    {
        for (size_t j = 0; j<=m; j++)
        {
            if(i==0 || j==0) dp[i][j]=0;
            else if(a[i-1]==b[j-1])dp[i][j]=1+dp[i-1][j-1];
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
    }

    return dp[n][m];
    
}

int main(){

string a,b;
cin>>b;
a=b;
reverse(b.begin(),b.end());
cout<<lcs(a,b,a.length(),b.length());
    return 0;
}