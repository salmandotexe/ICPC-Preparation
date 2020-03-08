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

const ll m=mod;

ll extended_euclidean(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = extended_euclidean(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll inverse(ll a){
    ll x, y;
    ll g = extended_euclidean(a, m, x, y);
    assert(g==1);
    x = (x % m + m) % m;
    return x;
}
const int maxn=1e6+5;
ll fac[maxn];

void prec()
{
    fac[0]=1;
    for(int i=1;i<maxn;i++) {
        fac[i]=(1LL*i*fac[i-1])%mod;
    }
}

ll ncr(ll n, ll r){
    ll num=fac[n];
    num*=inverse(fac[n-r]);
    num%=mod;
    num*=inverse(fac[r]);
    num%=mod;
    return num;
}

int main()
{
    prec();
    cout << ncr(4, 0) <<" "<< ncr(4, 1) <<" "<< ncr(4, 2) <<" "<< ncr(4, 3) <<" "<< ncr(4, 4) <<endl;
}
