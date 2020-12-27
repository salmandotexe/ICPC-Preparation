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
int a[maxn];
const int sz=350;

//gnu pbds hack resistant unordered map
//https://codeforces.com/problemset/problem/220/B

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};
gp_hash_table<int, int, chash> freq;

struct Query{
    int l,r,idx;
};
bool cmp(const Query &a, const Query &b){
    return mp(a.l/sz, a.r) < mp(b.l/sz, b.r);
}

int ansvar=0;

int get_answer(){
    return ansvar;
}

void add(int i){
    if(freq[a[i]]==a[i]) ansvar--;
    freq[a[i]]++;
    if(freq[a[i]]==a[i]) ansvar++;
}

void remove(int i){
    if(freq[a[i]]==a[i]) ansvar--;
    freq[a[i]]--;
    if(freq[a[i]]==a[i]) ansvar++;
}

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
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
        answers[q.idx] = get_answer();
    }
    return answers;
}


int main()
{
    fast_cin;
    int n,q;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<Query> queries(q);
    for(int i=0;i<q;i++){
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--,queries[i].r--,queries[i].idx=i;
    }
    auto ans=mo_s_algorithm(queries);
    for(auto a:ans){
        cout << a <<"\n";
    }
}
