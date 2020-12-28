//https://codeforces.com/contest/1328/problem/E.
#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define inf 1000000000000000001
#define mod 1000000007
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);
#define precise fixed(cout);cout<<setprecision(16);
#define Set(N,p) N=((N)|((1LL)<<(p)))
#define Reset(N,p) N=((N)&(~((1LL)<<(p))))
#define Check(N,p) (!(((N)&((1LL)<<(p)))==(0)))
#define POPCOUNT __builtin_popcountll
#define RIGHTMOST __builtin_ctzll
#define LEFTMOST(x) (63-__builtin_clzll((x)))
#define NUMDIGIT(x,y) (((vlong)(log10((x))/log10((y))))+1)
#define OUT(x) for(auto a:x) cout << a << " "; cout << endl;
#define OK cout << "@===================ok===================@" <<endl;
#define WTF cout <<"< "<<lo<<" | "<< hi <<" >" << endl;

using namespace std;
int n,q;
const int maxn=2e5+5;
vi G[maxn];
int t_out[maxn];
int t_in[maxn];
int h[maxn];
int par[maxn];

int T=0;

void dfs(int src, int p=-1, int dep=0){
	t_in[src]=T++;
	h[src]=dep;
	par[src]=p;
	for(auto v:G[src]){
		if(v==p) continue;
		dfs(v,src,dep+1);
	}
	t_out[src]=T++;
}

/*
	Edit: better version of dfs is this:
	void dfs(int src, int p=-1, int dep=0){
		t_in[src]=++T;
		h[src]=dep;
		par[src]=p;
		for(auto v:G[src]){
			if(v==p) continue;
			dfs(v,src,dep+1);
		}
		t_out[src]=T;
	}
	t_out[src]-t_in[src] + 1 gives us the size of subtree src directly in this variation. 
	and the ancestor theorem also holds (u is an ancestor of v iff t_in[v]<=t_in[u]<=t_out[u]<=t_in[v] )
*/
bool ancestor(int v, int u){
	return t_in[v] <= t_in[u] && t_out[u] <= t_out[v];
}
int main()
{
	fast_cin;
	cin >> n >> q;
	for(int i=0;i<n-1;i++){
	    int _a,_b;
	    cin >> _a >> _b;
	    G[_a].pb(_b);
	    G[_b].pb(_a);
	}
	dfs(1);
	for(int x=0;x<q;x++){
		int k;
		cin >> k;
		vi v(k); for(int i=0;i<k;i++) cin >> v[i];
		int fv=-1,d=-1;
		for(auto a:v) if(h[a]>d) fv=a,d=h[a];

		bool can=1;
		for(auto a:v){
			if(a==fv || a==1) continue;
			can&=(ancestor(a,fv)||ancestor(par[a],fv));
		}
		if(can) cout <<"YES\n";
		else cout <<"NO\n";
	}
}
