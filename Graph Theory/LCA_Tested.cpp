//https://vjudge.net/contest/406396#problem/K
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
const int maxn=1e5+5;
const int szz=320;
const int LN = 19;
int dp[LN][maxn];
int n,q;

int D[szz+10][szz+10];
int S[szz+10];			//S[i] holds count of how many values are set in D[i][0..szz-1]
int valid[maxn];	//stores 1 if <2 present.


vector<pii> G[maxn];
int l[maxn];
int r[maxn];
int ID[2*maxn];
int col[maxn];
int lvl[maxn];

struct Query{
    int l,r,idx,ty;
};
bool cmp(const Query &a, const Query &b){
    return mp(a.l/szz, a.r) < mp(b.l/szz, b.r);
}

int timer=0;

void dfs(int u, int p=-1){
	l[u]=++timer;
	ID[timer]=u;
	for(auto [v,colv]:G[u]){
		if(v==p) continue;
		lvl[v] = lvl[u] + 1;
		col[v]=colv;
		dp[0][v] = u;
		dfs(v,u);
	}
	r[u]=++timer;
	ID[timer]=u;
}

inline int lca(int u, int v){
	if (lvl[u] > lvl[v]) swap(u, v);
	for (int i = LN - 1; i >= 0; i--)
		if (lvl[v] - (1 << i) >= lvl[u]) v = dp[i][v];
	if (u == v) return u;
	for (int i = LN - 1; i >= 0; i--){
		if (dp[i][u] != dp[i][v]){
			u = dp[i][u];
			v = dp[i][v];
		}
	}
	return dp[0][u];
}


int get_answer(){
	for(int i=0;i<szz;i++){
		if(S[i]<szz){//answer definitely exists in this block.
			for(int j=0;j<szz;j++){
				if(D[i][j]==0){
					return szz*i+j;
				}
			}
		}
	}
}


inline void add(int i){
	int color = col[ID[i]];
	if(color>maxn) return;
	if(!valid[ID[i]]){
		if(D[color/szz][color%szz]==0) ++S[color/szz];	//present in this block.
		++D[color/szz][color%szz];
	}
	else{
		if(D[color/szz][color%szz]==1) --S[color/szz];	//present in this block.
		--D[color/szz][color%szz];
	}
	valid[ID[i]]^=1;
}
inline void addNode(int i){
	int color = col[i];
	if(color>maxn) return;
	if(!valid[i]){
		if(D[color/szz][color%szz]==0) ++S[color/szz];	//present in this block.
		++D[color/szz][color%szz];
	}
	else{
		if(D[color/szz][color%szz]==1) --S[color/szz];	//present in this block.
		--D[color/szz][color%szz];
	}
	valid[i]^=1;
}

inline void remove(int i){
	add(i);
}

vector<ll> mo_s_algorithm(vector<Query> queries) {
    vector<ll> answers(queries.size());
    sort(all(queries),cmp);
    int cur_l = 0 +1;
    int cur_r = -1 +1;	//BEWARE OF 1 BASED INDEXING.
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
		if(q.ty==-1){
			answers[q.idx] = get_answer();
		}
		else{
			//addNode(q.ty);
			//we ignore the lca element because the edge
			//(par[lca],lca) does not lie in the path between u..v
			//and thus we are not concerned about the color of lca node.
			answers[q.idx] = get_answer();
			//addNode(q.ty);
		}
    }
    return answers;
}


int main()
{
	dp[0][1] = 1;	//for lca
    fast_cin;
    cin >> n >> q;
    for(int i=0;i<n-1;i++){
		int u,v,w;
		cin >> u >> v >> w;
		G[u].pb({v,w});
		G[v].pb({u,w});
	}

	col[1]=maxn+10;
	dfs(1);

    vector<Query> queries(q);
    for(int i=0;i<q;i++){
        int u,v;
		cin >> u >> v;
        if(l[u]>l[v]) swap(v,u);

		if(r[u]>r[v]){	//lca(u,v) = u.
			// [l[u], l[v]]
			queries[i].l = l[u]+1;//the 1 is added because we consider edges.
			//and l[u] will contain the color corresponding to the edge (par[lca],lca)
            queries[i].r = l[v];
			queries[i].ty = -1;

		}
		else{
			//[r[u], l[v]] U [l[lca],l[lca]]
			queries[i].l = r[u];
            queries[i].r = l[v];
			queries[i].ty = lca(u,v);
		}
        queries[i].idx=i;
    }

    auto ans=mo_s_algorithm(queries);
    for(auto a:ans){
        cout << a <<"\n";
    }

}
