// O ( E l o g V ) 
#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);
#define precise fixed(cout);cout<<setprecision(16);
#define OUT(x) for(auto a:x) cout << a << " "; cout << endl;
#define OK cout << "@===================ok===================@" <<endl;
#define WTF cout <<"< "<<lo<<" | "<< hi <<" >" << endl;

using namespace std;


const int maxn=55;

int n;
int G[maxn][maxn];

int par[maxn];
int urank[maxn];

int find(int x)
{
	if( par[x] != x )	//path compression
		par[x] = find(par[x]) ;
	return par[x];
}

void create(ll x)
{
	par[x] = x ;
	urank[x] = 1 ; 		// rank = no. of nodes in its subtree
}

void merge(ll x, ll y)
{
	ll xroot = find(x);
	ll yroot = find(y);
    if(xroot==yroot) return;
	if( urank[xroot] <= urank[yroot] )	// Union by rank
	{
		par[xroot] = yroot ;
		urank[yroot] = urank[yroot] + urank[xroot] ;
	}
	else
	{
		par[yroot] = xroot;
		urank[xroot] = urank[xroot] + urank[yroot] ;
	}
}

inline ll kruskal(const vector<pair<int,pii> > &e){
    ll res=0;
    for(int i=0;i<e.size();i++){
        int u= e[i].s.f; int v= e[i].s.s;
        int w= e[i].f;
        if(find(u)!=find(v)){
            merge(u,v);
            res+=w;
        }
    }

    int last=-1;
    for(int i=1;i<=n;i++){
        if(last==-1) last=find(i);
        else if(last!=find(i)) return -1;    //unconnected.
    }

    return res;
}
int main()
{
    //freopen("in.txt","r",stdin);
    fast_cin
    int T;
    cin >> T;
    for(int tc=1;tc<=T;tc++)
    {
        vector<pair<int, pii> > edgelist;
        cin >> n;
        for(int i=0;i<=n;i++) create(i);
        ll total=0;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
            cin >> G[i][j];
            total += G[i][j];
            if(G[i][j]!=0) edgelist.pb({G[i][j], {i,j}});
        }
        sort(all(edgelist));
        auto ans=kruskal(edgelist);
        cout << "Case "<<tc<<": "<<(ans!=-1?total-ans:ans)<<endl;
    }
}
