//https://codeforces.com/problemset/problem/375/D

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
const int szz=512;
struct Query{
    int l,r,idx,k;
};
bool cmp(const Query &a, const Query &b){
    return mp(a.l/szz, a.r) < mp(b.l/szz, b.r);
}


int n,q;
vi G[maxn];
int col[maxn],a[2*maxn];
int st[2*maxn],en[2*maxn];
int cnt[maxn],cnt2[maxn];
int timer=0;

void dfs(int src, int p=-1){
    st[src]=++timer;
    a[timer]=src;   //preorder traversal with 1 based indexing.

    for(auto v:G[src]){
        if(p==v) continue;
        dfs(v,src);
    }
    en[src]=timer;
}

ll get_answer(int k){
    return cnt2[k];
}

void add(int i){
    int color = col[a[i]];
    cnt[color]++;
    cnt2[cnt[color]]++;
}

void remove(int i){
    int color = col[a[i]];
    cnt2[cnt[color]]--;
    cnt[color]--;
}


vector<ll> mo_s_algorithm(vector<Query> queries) {
    vector<ll> answers(queries.size());
    sort(all(queries),cmp);
    int cur_l = 0;
    int cur_r = -1;
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
        answers[q.idx] = get_answer(q.k);
    }
    return answers;
}


int main()
{
    fast_cin;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> col[i];
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs(1);

    vector<Query> queries(q);
    for(int i=0;i<q;i++){
        int a,k;
        cin >> a >> k;
        queries[i].l = st[a];
        queries[i].r = en[a];
        queries[i].idx = i;
        queries[i].k = k;
    }
    auto ans=mo_s_algorithm(queries);
    for(auto a:ans){
        cout << a <<"\n";
    }

}
