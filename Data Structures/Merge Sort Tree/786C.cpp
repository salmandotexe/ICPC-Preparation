//https://codeforces.com/problemset/problem/786/C

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

vi t[4*maxn+10];
int a[maxn];
int ocr[maxn];
int prevocr[maxn];


int n;

void build(int i=1, int lo=1, int hi=n){
    if(lo==hi){
        t[i]=vi({a[lo]});
        return;
    }
    int mid=(lo+hi)/2;
    build(2*i,lo,mid);
    build(2*i+1,mid+1,hi);
    t[i]=vi((int)t[2*i].size()+t[2*i+1].size());
    std::merge(all(t[2*i]), all(t[2*i+1]), t[i].begin());
}

inline pii query(int i, int lo, int hi, int idx, int k){
    if(idx<=lo){
        int cnt=lower_bound(all(t[i]),idx) - t[i].begin();
        if(cnt<k) return {hi,cnt};
    }
    if(lo==hi) return {lo,1};

    int mid=(lo+hi)/2;

    if(idx>mid){
        return query(2*i+1,mid+1,hi,idx,k);
    }

    pii L = query(2*i,lo,mid,idx,k);
    if(L.s>=k) return L;

    pii R = query(2*i+1,mid+1,hi,idx,k-L.s);
    return {R.f, R.s + L.s};
}

inline int solve(int k){
    int ret=0;
    int st=1;
    while(st<=n){
        ret++;
        pii get=query(1,1,n,st,k+1);
        if(get.s<=k) break;
        st=get.f;
    }
    return ret;
}


int main()
{
    fast_cin;
    cin >> n;
    mem(ocr,-1);
    for(int i=1;i<=n;i++) {
        int x;
        cin >> x;
        a[i]=ocr[x];
        ocr[x]=i;
    }
    build(1,1,n);
    for(int k=1;k<=n;k++){
        cout << solve(k) <<" ";
    }
    cout <<"\n";
    return 0;
}
