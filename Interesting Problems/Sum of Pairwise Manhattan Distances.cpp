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
const int maxn = 1e5+5;
vll X[maxn], Y[maxn];

ll proc(ll color){
    ll res=0;
    for(const vll &v : {X[color],Y[color]}) {
        const int n = v.size();
        ll s1=0,s2=0;
        for(int i=0,c=n,d=1;i<n;i++,c--,d++){   
          // Computes Sum of |v_i - v_j| for 1<=i<=j<=n; 
          // more details: https://github.com/salmandotexe/ICPC-Preparation/blob/master/Mathematics/%7C%20a_i%20-%20a_j%20%7C%20for%201%3C%3Di%3C%3Dj%3C%3Dn%20.cpp
            
            s2 += 1LL*c*v[i];
            s1 += 1LL*d*v[i];
        }
        res+= (s1-s2);
    }
    return res;
}

// https://codeforces.com/contest/1649/problem/C
int main()
{
    fast_cin;
    int n,m;
    cin >> n >> m;
    int mx=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;
            cin >> x;
            X[x].pb(i);
            Y[x].pb(j);
            mx=max(mx,x);
        }
    }
    ll res=0;
    for(int c=1;c<=mx;c++){
        sort(all(X[c]));
        sort(all(Y[c]));
        res += proc(c);
    }
    cout << res <<"\n";
}
