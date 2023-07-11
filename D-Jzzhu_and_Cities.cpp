#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
#define inf 100000000000
#define pb  push_back
//--------------- {@ author Ahmed_Hussieny } -------------------------
void fast(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}


// int arr[30];
// ll n,m,k,t;
// int arr[100005];
// vector<char> G[100005];
vector<ll> G[100003];


int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
string s1,s2;
int n,m,k,z,a,b,ans;
// vector<vector<pair<int,int>>>g;

bool vis[100001];
ll cost[100001];
struct edge
{
	int x;
	ll cst;
	bool f;
	edge(int a,ll b,bool c){
		x=a;cst=b;f=c;
	}
	bool operator <(const edge &a)const{
		if(cst==a.cst)
			return f>a.f;
		return cst>a.cst;
	}
	
};

vector<pair<int,int>>v[100001];
priority_queue<edge>q;
void dijkstra(){
	q.push(edge(1,0,0));
	for (int i = 1; i <=n; ++i)cost[i]=1e18;
	cost[1]=0;
while(!q.empty()){
	edge a=q.top();
	q.pop();
	if(vis[a.x]){
		ans+=a.f;
		continue;
	}
	vis[a.x]=true;
	for (int i = 0; i < v[a.x].size(); ++i)
	{
		int newnode=v[a.x][i].first;
		int edgecost=v[a.x][i].second;
		if(edgecost+a.cst<cost[newnode]){
			cost[newnode]=edgecost+a.cst;
			q.push(edge(newnode,cost[newnode],0));
		}
	}
}
	 
	}
int solve(){
	cin>>n>>m>>k;
	for (int i = 0; i < m; ++i)
	{
		int x,y,z;
		cin>>x>>y>>z;
		v[x].pb(make_pair(y,z));
		swap(x,y);
		v[x].pb(make_pair(y,z));
	}
	for (int i = 0; i < k; ++i)
	{
		cin>>a>>b;
		q.push(edge(a,b,1));
	}
	
	dijkstra();
        
      cout<<ans;


    return 0;
}


int main() { 
fast();
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
  // ll t;

  //  cin>>t;
  //  while (t--) {
    solve();
   // }
    return 0;
}
