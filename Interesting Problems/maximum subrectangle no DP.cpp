//http://www.lightoj.com/volume_showproblem.php?problem=1424
//warning: problem in the link is only used to test. it will get TLE as O(nmnlogm) solution.
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

int n,m;
const int maxn=2e3+5;
char C[maxn][maxn];
int  f[maxn][maxn];

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    cin >> T;
    for(int tc=1;tc<=T;tc++)
    {
        cin >> n >> m;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> C[i][j];
        for(int i=1;i<=n;i++){
            int x=0;
            for(int j=1;j<=m;j++){
                x+=(C[i][j]=='1');
                f[i][j]=x;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                f[i][j]+=f[i-1][j];
            }
        }
        auto get=[&](int i, int j, int i2, int j2){
            return f[i2][j2]-f[i-1][j-1]- (f[i-1][j2]-f[i-1][j-1]) - (f[i2][j-1]-f[i-1][j-1]);
        };
        ll mx=0;

        auto ok=[&](int i, int j, int i2, int j2){
            return (get(i,j,i2,j2)==0);
        };
        
        //Try all combination of 3 edges. binary search on the final edge.

        cout <<"Case "<<tc<<": ";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(C[i][j]!='0') continue;
                for(int i2=i;i2<=n;i2++){
                    //binary search on J.
                    ll lo=j,hi=m;
                    while(hi-lo>1){
                        ll mid=(lo+hi)/2;
                        if(ok(i,j,i2,mid)){
                            lo=mid;
                        }
                        else hi=mid-1;
                    }
                    int j2=lo;
                    mx=max(mx,1LL*(i2-i+1)*(j2-j+1));
                }
            }
        }
        cout << mx <<'\n';

    }
}
