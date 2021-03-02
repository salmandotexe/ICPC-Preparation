//  https://vjudge.net/problem/Gym-101630J
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
const int maxn=3005;
vector<pll> G[maxn];
ll n,m,k;
ll u[maxn],v[maxn],w[maxn];
ll dis[maxn];

struct Node{
    ll id, val;
    Node(ll id=0, ll val=0):id(id),val(val){};

};

bool operator<(const Node &a, const Node &other){
    if(a.val!=other.val) return a.val>other.val;
    return a.id<other.id;
}


ll solve(ll x){     //try taking x as kth maximum.
    for(int i=0;i<=n;i++) G[i].clear();

    for(int i=1;i<=m;i++){
        G[u[i]].pb({v[i],max(0LL,w[i]-x)});   //weights<=x get zero'd. => this is not part
        G[v[i]].pb({u[i],max(0LL,w[i]-x)});   //of the k maximums so we dont count them.
    }

    mem(dis,63);
    dis[1]=0;
    priority_queue<Node> q;

    q.push(Node(1,0));
    while(!q.empty()){
        ll u=q.top().id,w=q.top().val;
        q.pop();
        if(dis[u]!=w) continue; //This line halves the time taken to run dijkstra.
        for(auto &e:G[u]){
            auto v=e.f, wei = e.s;
            if(dis[v]>wei + w){
                dis[v]=w+wei;
                q.push(Node(v,dis[v]));
            }
        }
    }
    return dis[n] + k*x;
    //we add k xs' in the end because we subtracted x from the k remaining elements.
}

int main(){
    fast_cin;
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        cin >> u[i] >> v[i] >> w[i];
    }
    auto ans=solve(0);
    for(int i=1;i<=m;i++){
        ans=min(ans,solve(w[i]));
    }
    cout << ans <<"\n";
}
