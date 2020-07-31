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

const int maxn=2e5+5;
bool prime[maxn];

vll P;      //stores Primes upto [0...maxn).

void prec(){
    mem(prime,1);
    prime[0]=prime[1]=0;
    for(int i=4;i<maxn;i+=2) prime[i] = 0;

    P.pb(2);
    for(int i=3;i<maxn;i+=2){
        if(!prime[i]) continue;
        P.pb(i);
        for(int j=i+i;j<maxn;j+=i) prime[j]=0;
    }
}

//This prime factorization works in O( π(sqrt(N)) ) //<--- worst case is number of primes under sqrt(N).
/*

x                       π(x)
1e1         |             4
1e2         |            25
1e3         |           168
1e4         |          1229
1e5         |          9592
1e6         |         78498
1e7         |        664579
1e8         |       5761455
1e9         |      50847534
1e10        |     455052511
1e11        |    4118054813

Pi(x) ~ x/ln(x) (PNT)

*/

vll fac(ll n){
    vll ans;
    for(auto p:P){
        if(p*p>n) break;
        while(n%p==0){
            n/=p;
            ans.pb(p);
        }
    }
    if(n>1) ans.pb(n);
    return ans;
}

int main()
{
    prec();
    auto ans=fac(1340);
    OUT(ans);
}
