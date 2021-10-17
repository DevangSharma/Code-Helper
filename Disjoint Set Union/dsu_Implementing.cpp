#include<bits/stdc++.h>
#define ll long long
#define test while(t--)
#define mod 1e9
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define f(a,n) for(ll i=a;i<n;i++)
#define fj(a,n) for(ll j=a;j<n;j++) 
#define fe(a,n) for(ll i=a;i<=n;i++)
typedef std::vector<ll> vec;  
using namespace std;
//-------------------------Functions

void makeset(){
 for(int i=0;i<10000;i++) par[i]=i;
 memset(ranks,0,sizeof(ranks));
}

int findset(int a){
   if(a==par[a]) return a;
   return par[a]=findset(par[a]);
}

void unionset(int u,int v){
	u = findset(u);
	v = findset(v);
	if(ranks[u]==ranks[v]){
		ranks[u]++;
		par[v]=u;
	}
	else{
		if(ranks[u]>ranks[v]) par[v]=u;
		else{
			par[u]=v;
		}
	}
}

//-------------------------------------Functions

int par[10000];
int ranks[10000];
int main(){
int n,t;
cin>>n>>t;
makeset();
test{
    int type,u,v;
    cin>>type>>u>>v;
    if(type){
    	cout<<(findset(u)==findset(v))<<endl;
    	continue;
    }
    else{
      unionset(u,v);
    }
}
    return 0;
}
