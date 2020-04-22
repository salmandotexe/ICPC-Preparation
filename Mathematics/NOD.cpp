#include <stdio.h>
#include <vector>
#include <cstring>
#define ll long long int
#define vll vector<ll>
#define mem(a,val) memset(a,val,sizeof(a))
#define pb push_back
using namespace std;

vll P;
const int maxn=1e6+50;
bool prime[maxn];

void prec(){
    mem(prime,1);
    prime[0]=prime[1]=0;
    P.pb(2);
    for(int i=4;i<maxn;i+=2) prime[i]=0;

    for(int i=3;i*i<maxn;i+=2){
        if(prime[i]){
            for(int j=i*i;j<maxn;j+=i) prime[j]=0;
        }
    }
    for(int i=3;i<maxn;i+=2) if(prime[i]) P.pb(i);
}

inline ll nod(ll n){
    ll res=1;
    for(auto p:P){
        if(p*p>n) break;
        if(n%p==0){
            int pp=0;
            while(n%p==0){
                n/=p;
                pp++;
            }
            res*=(pp+1);
        }
    }
    if(n!=1) res*=2;
    return res;
}

int main()
{
    prec();
    int T;
    scanf("%d", &T);
    for(int tc=1;tc<=T;tc++)
    {
        ll n;
        scanf("%lld", &n);
        auto ans=nod(n);
        printf("Case %d: %lld\n",tc,ans-1);
    }
}
