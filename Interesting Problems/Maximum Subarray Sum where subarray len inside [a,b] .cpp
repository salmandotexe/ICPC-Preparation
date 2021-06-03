//https://cses.fi/problemset/task/1644/
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

int main()
{
    fast_cin;
    int n , a,b;
    cin >> n >> a >> b;
    vll v(n+2), p(n+2);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        p[i]=p[i-1]+v[i];
    }
    ll mx=-inf;
    multiset<ll> ms;

    for(int i=a;i<=n;i++){
        //we maintain the sliding window by adding p[i-a] and removing p[i-b-1].
        //thus ms stores [i-a,i-b].
        // .     .        .      .      .    .    .    .    .
        //      -^   [i-2]^ [i-1]^+    ^i
        ms.insert(p[i-a]);
        if(i>b){
            ms.erase(ms.find(p[i-b-1]));
        }
        mx=max(mx,p[i]-*ms.begin());
    }
    cout << mx <<"\n"; 
}
