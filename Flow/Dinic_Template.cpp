//problem: https://vjudge.net/problem/LightOJ-1153
#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define inf 0x3f3f3f3f
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
int n,s,t,c;

const int maxn=105;
struct Edge {
    int u, v, flow, cap;
    Edge(){}
    Edge(int a, int b, int c, int d):u(a), v(b), cap(c), flow(d){}
};

struct Dinic{
    int n;
    vi G[maxn];
    vector<Edge> edges;
    int cur[maxn], vis[maxn], d[maxn];

	void init(int n) {
        this->n = n;
        for(int i=0;i<=n;i++) G[i].clear();
        edges.clear();
    }

    void add_edge(int u, int v, int cap){
        edges.push_back(Edge(u, v, cap, 0));
        edges.push_back(Edge(v, u,   0, 0));
        int m = edges.size();
        G[u].push_back(m-2);
        G[v].push_back(m-1);
    }

    bool BFS(int s, int t) {
        queue<int> Q;
        Q.push(s);
        memset(vis, 0, sizeof(vis));
        d[s] = 0;
        vis[s] = 1;
        while(!Q.empty()) {
            int u = Q.front(); Q.pop();
            for(int i = 0; i < (int)G[u].size(); i++) {
                Edge &e = edges[G[u][i]];
                int v = e.v;
                if(vis[v]) continue;
                if(e.cap > e.flow) {
                    vis[v] = 1;
                    d[v] = d[u] + 1;
                    Q.push(v);
                }
            }
        }
        return vis[t];
    }

    int DFS(int x, int a, int t) {
        if(x == t || a == 0) return a;
        int f, flow = 0;
        for(int &i = cur[x]; i < G[x].size(); i++){
            Edge &e = edges[G[x][i]];
            int v = e.v;
            if(d[v] == d[x] + 1 && (f = DFS(v, min(e.cap-e.flow, a), t)) > 0){
                e.flow += f;
                edges[G[x][i]^1].flow -= f;
                flow += f;
                a -= f;
                if(a <= 0) break;
            }
        }
        return flow;
    }

    int mcmf(int s, int t){
        int flow = 0;
        while(BFS(s, t)){
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, inf, t);
        }
        return flow;
    }
};

int main(){
	  fast_cin;
    int T;
    cin >> T;
    for(int tc=1;tc<=T;tc++){
		cin >> n;
		cin >> s >> t >> c;
		
		Dinic d;
		d.init(n);

		for(int i=0;i<c;i++){
			int a,b,w;
			cin >> a >> b >> w;
			d.add_edge(a,b,w);
			d.add_edge(b,a,w);
		}
		auto ans=d.mcmf(s,t);

		cout << "Case "<<tc<<": "<<ans<<"\n";

    }
}
