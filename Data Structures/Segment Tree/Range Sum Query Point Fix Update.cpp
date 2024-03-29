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
int n,k,q;
unordered_map<string,int> m;

const int maxn=2e5+5;

ll t[4*maxn];

inline ll get(int a, int b, int i=1, int lo=0, int hi=n-1){
    if(b<lo || a>hi) return 0;
    if(a<=lo && hi<=b) return t[i];
    int mid=(lo+hi)/2;
    ll t1=get(a,b,2*i,lo,mid);
    ll t2=get(a,b,2*i+1,mid+1,hi);
    //t[i]=t[2*i]+t[2*i+1];
    return t1+t2;
}

inline void upd(int pos, int val, int i=1, int lo=0, int hi=n-1){
    if(pos<lo || pos>hi || lo>hi) return;
    if(pos==lo && pos==hi) {
        t[i]=val;
        return;
    }
    int mid=(lo+hi)/2;
    if(pos<=mid) upd(pos,val,2*i,      lo,mid);
    else         upd(pos,val,2*i+1, mid+1, hi);
    t[i]=t[2*i]+t[2*i+1];
}


// https://vjudge.net/problem/Gym-102448B

int main()
{
    fast_cin;
    cin >> n >> k >> q;
    vector<string> drinks_at_ith_hour(n);
    for(auto &a:drinks_at_ith_hour) cin >> a;

    for(int i=0;i<k;i++){
        string s; int x;
        cin >> s >> x;
        m[s]=x;
    }
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=m[drinks_at_ith_hour[i]];
    }
    while(q-->0){
        int ty;
        cin >> ty;
        if(ty==1){
            int x; string s;
            cin >> x >> s; x--;
            upd(x,m[s]);
        }
        else if(ty==2){
            int l,r;
            cin >> l >> r;
            ll time_=1LL*(r-l+1)*60;
            l--,r--;
            ll vol=get(l,r);
            if(vol*2LL<=time_) cout <<"NO\n";
            else cout <<"YES\n";
        }
    }
}
