https://codeforces.com/problemset/problem/279/C

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
    int n,m;
    cin >> n >> m;
    vi v(n+2),inc(n+2),dec(n+2);
    for(int i=1;i<=n;i++) {
        cin >> v[i];
        inc[i]=i;
        dec[i]=i;
    }


    for(int i=1;i<=n;i++){
        if(v[i]>=v[i+1]){
            int j=i+1;
            while(j<=n && v[j-1]>=v[j]) dec[j]=i,j++;
            i=j-1;
        }
    }

    for(int i=1;i<=n;i++){
        if(v[i]<=v[i+1]){
            int j=i+1;
            while(j<=n && v[j-1]<=v[j]) j++;
            for(int x=i;x<j;x++) inc[x]=j-1;
            i=j-1;
        }
    }

    while(m--){
        int l,r;
        cin >> l >> r;
        if(inc[l]>=dec[r]) cout <<"Yes\n";
        else cout <<"No\n";
    }



}
