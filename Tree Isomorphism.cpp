// https://cses.fi/problemset/task/1700

#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define ll long long
#define mod 1000000007
 
using namespace std;
const uint64_t base = mt19937_64(1234)() % (mod / 3) + (mod / 3);
const uint64_t base2 = mt19937_64(4321)() % (mod / 3) + (mod / 3);
const int maxn = 1e5+5;
 
vi G[maxn];
vi H[maxn];
 
int n;
 
ll b[maxn];
ll b2[maxn];
 
ll Hash2[maxn];
int sz2[maxn];
 
inline void dfs2(int u, int p=-1){
    sz2[u]=1;
    for(auto &v:H[u]){
        if(v!=p) {
            dfs2(v,u);
            sz2[u]+=sz2[v];
        }
    }
    Hash2[u] = 1;
    for(auto &v:H[u]){
        if(v!=p){
            Hash2[u] *= (b[sz2[v]] + Hash2[v]);
        }
 
    }
    Hash2[u]*=base;
    Hash2[u]%=mod;
}
 
 
ll Hash[maxn];
int sz[maxn];
 
inline void dfs1(int u, int p=-1){
    sz[u]=1;
    for(auto &v:G[u]){
        if(v!=p) {
            dfs1(v,u);
            sz[u]+=sz[v];
        }
    }
    Hash[u] = 1;
    for(auto &v:G[u]){
        if(v!=p){
            Hash[u] *= (b[sz[v]] + Hash[v]);
        }
 
    }
    Hash[u]*=base;
    Hash[u]%=mod;
}
 
 
inline void clr(){
    for(int i=0;i<=n;i++) G[i].clear(),H[i].clear();
}
inline void solve(){
    cin >> n;
    clr();
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
 
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        H[a].pb(b);
        H[b].pb(a);
    }
    dfs2(1);
    dfs1(1);
    if(Hash[1]==Hash2[1]){
        cout <<"YES\n";
    }
    else{
        cout <<"NO\n";
    }
}
 
int main(){
    ///freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    b[0]=1;
    b2[0]=1;
    for(int i=1;i<maxn;i++){
        b[i] = (b[i-1] * base)%mod;
        b2[i] = (b2[i-1]*base2)%mod;
    }
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
