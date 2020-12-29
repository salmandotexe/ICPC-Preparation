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
const int maxn=2e5+5;
const int szz=512;

struct Query{
    int l,r,idx,k;
};
bool cmp(const Query &a, const Query &b){
    return mp(a.l/szz, a.r) < mp(b.l/szz, b.r);
}

int a[maxn];
int cnt[maxn],cnt2[maxn];
int ans[maxn];
//gnu pbds hack resistant unordered map

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
int n,q;
int len=0;

int get_answer(int k){
    if(k==0) return 0;
    ll r=(len+k-1)/k;
    return (cnt2[r]>0)?ans[cnt2[r]]:-1;
}

void add(int i){
    cnt[a[i]]++;
    len++;
    cnt2[cnt[a[i]]]++;
    ans[cnt2[cnt[a[i]]]]=min(ans[cnt2[cnt[a[i]]]], a[i]);
}

void remove(int i){
    cnt2[cnt[a[i]]]--;
    if(cnt2[cnt[a[i]]]==0) ans[cnt2[cnt[a[i]]]]=inf;
    len--;
    cnt[a[i]]--;
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
    freopen("in.txt","r",stdin);
    mem(ans,63);
    fast_cin;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    vector<Query> queries(q);
    for(int i=0;i<q;i++){
        int l,r,k;
        cin >> l >> r >> k;
        queries[i].l = l-1;
        queries[i].r = r-1;
        queries[i].idx = i;
        queries[i].k = k;
    }

    auto ans=mo_s_algorithm(queries);
    for(auto a:ans){
        cout << a <<"\n";
    }

}
