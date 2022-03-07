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

// https://codeforces.com/contest/1649/problem/C

int main()
{
    freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    vi v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    ll res=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            res+=abs(v[i]-v[j]);
        }
    }
    cout << res <<"\n";

    sort(all(v));
  
    ll s1=0,s2=0;
    for(int i=0,c=n,d=1;i<n;i++,c--,d++){
        s2 += 1LL*c*v[i];
        s1 += 1LL*d*v[i];
    }
    cout << s1-s2 <<"\n";

    /*
          Because: 
          
          Let S = |a1 - a1| + |a1 - a2| + .. |a1 - an| + 
                              |a2 - a2| + .. |a2 - an| + ..
    
          Let w be a sorted in decreasing order.
          WLOG,
          
              S = w1 - w1 + w1 - w2 +  .. w1 - wn +
                            w2 - w2 +  .. w2 - wn + ..
              
              S = (n*w1 + (n-1)w2 + ... 1*wn) - (1*w1 + 2*w2 + ... n*wn)
    */
    
}
