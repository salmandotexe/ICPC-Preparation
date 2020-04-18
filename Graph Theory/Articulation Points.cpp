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



/***
 *
 * finds articulation points in simple graphs in O(N + M)
 * an articulation point or cut vertex is defined as a vertex which, when removed along with associated edges, makes the graph disconnected
 * or more precisely, increases the number of connected components in the graph
 * nodes are numbered from 0 to N-1
 *
***/



using namespace std;

const int MAX =10010;

vector <int> adj[MAX];
bool visited[MAX], is_cut[MAX];
int n, disc_t, discover[MAX], low[MAX];

void clr(){
	n=0;
	for (int i = 0; i < MAX; i++) adj[i].clear();
	mem(visited,0);
	mem(is_cut,0);
	mem(discover,0);
	mem(low,0);
	disc_t=0;
}

void dfs(int u, int p){
    visited[u] = true;
    discover[u] = low[u] = ++disc_t;

    int children = 0;
    for (auto v: adj[u]){
        if (!visited[v]){
            children++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if ((low[v] >= discover[u]) && !(p == -1 && children < 2)) {
                is_cut[u] = true;
            }
        }
        else if (v != p) low[u] = min(low[u], discover[v]);
    }
}

    /// adds undirected edge from u to v
void add_edge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

vector <int> get_cuts(){
    memset(is_cut, 0, sizeof(is_cut));
    memset(visited, 0, sizeof(visited));

    vector <int> cuts;
    for (int i = 0; i < n; i++){
        if (!visited[i]){
            disc_t = 0;
            dfs(i, -1);
        }
        if (is_cut[i]) cuts.push_back(i);
    }

    return cuts;
}

//LOJ 1063 http://lightoj.com/volume_showproblem.php?problem=1063
int main()
{
	int T;
	scanf("%d", &T);
	for(int tc=1;tc<=T;tc++)
	{
	  	clr();
		int m;
		cin >> n >>m;
		while(m--){
			int a,b;
			scanf("%d%d", &a,&b);
			a--,b--;
			add_edge(a,b);
		}
		auto cuts = get_cuts();
		printf("Case %d: %d\n",tc,(int)cuts.size());
	}


}
