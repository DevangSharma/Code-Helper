#include<bits/stdc++.h>
using namespace std;

int dp[101][101] {0};

int lcs(string x,string y,int n,int m){
    if(n==0 || m==0){
        return 0;
    }
    if(dp[n][m]!=0)return dp[n][m];

    if(x[n-1]==y[m-1]){
        return dp[n][m]=1+lcs(x,y,n-1,m-1);
              
    }

    else {
        return dp[n][m]=max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
    }
}

int main(){

string s1,s2;
cin>>s1>>s2;
cout<<lcs(s1,s2,s1.length(),s2.length());
    return 0;
}