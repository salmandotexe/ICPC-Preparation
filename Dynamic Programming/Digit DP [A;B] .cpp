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

#define memo1 if(vis[i][lt][gt][x][y][z]==tc) return dp[i][lt][gt][x][y][z];
#define memo2 vis[i][lt][gt][x][y][z]=tc, dp[i][lt][gt][x][y][z]=res;
vll L,R;
int n;

ll dp[50][2][2][17][17][17];
int vis[50][2][2][17][17][17];
int tc;

ll f(int i, int lt=0 , int gt=0 , int x=0, int y=0, int z=0){
    if(max({x,y,z})>=17) return 0;
    if(i==n) return (x>=1 && x==y && y==z);

    memo1;
    int lo=L[i],hi=R[i];
    if(gt) lo=0;
    if(lt) hi=9;

    ll res=0;
    for(int d=lo;d<=hi;d++){
        res+=f(i+1,lt|d<hi, gt|d>lo, x+(d==3), y+(d==6), z+(d==9)), res%=mod;
    }
    memo2;
    return res;
}
int main()
{
    fast_cin;
    int T;
    cin >> T;
    for(tc=1;tc<=T;tc++)
    {
        string a,b;
        cin >> a >> b;
        L.clear();
        R.clear();
        for(int i=(int)a.size()-1;i>=0;i--)
            L.pb(a[i]-'0');
        for(int i=(int)b.size()-1;i>=0;i--)
            R.pb(b[i]-'0');
        while(L.size()<R.size()) L.pb(0LL);
        reverse(all(L));
        reverse(all(R));

        n=R.size();
        auto ans=f(0);
        cout << ans <<"\n";
    }
}
https://vjudge.net/problem/SPOJ-NUMTSN/origin
