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
ll gcd( ll a, ll b )
{
	if(b==0)
	{
	     return a;
	}
	else
	{
	     return gcd( b, a%b );
	}
}
ll lcm (ll a, ll b)
{
	return max(a,b)/gcd(a,b) * min(a,b);
}

vll Div(ll n){
    vll ans;
    if(n<=100){
        for(int i=1;i<n;i++){
            if(n%i==0){
                ans.pb(i);
            }
        }
        ans.pb(n);
    }
    else{
        for(ll i=1;i*i<=n;i++){
            if(n%i==0){
                ans.pb(i);
                if(i*i!=n) ans.pb(n/i);
            }
        }
    }
    return ans;
}


int main()
{
    fast_cin;
    int T;
    cin >> T;
    for(int tc=1;tc<=T;tc++)
    {
        ll n;
        cin >> n;
        ll mn=1e18+1;
        ll i=1,j=n-1;
        for(auto a:Div(n)){
            if(a==n || a==1) continue;
            ll L=lcm(a,n-a);
            if(L<mn){
                mn=L,i=a,j=n-a;
            }
        }
        cout << i <<" "<< j <<"\n";
    }
}
