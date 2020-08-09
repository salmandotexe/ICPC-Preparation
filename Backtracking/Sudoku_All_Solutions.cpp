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

const int maxn=10;
const int n=9;
/*
int ar[maxn][maxn] ={ { 3, 1, 6, 5, 7, 8, 4, 9, 2 },
                   { 5, 2, 9, 1, 3, 4, 7, 6, 8 },
                   { 4, 8, 7, 6, 2, 9, 5, 3, 1 },
                   { 2, 6, 3, 0, 1, 5, 9, 8, 7 },
                   { 9, 7, 4, 8, 6, 0, 1, 2, 5 },
                   { 8, 5, 1, 7, 9, 2, 6, 4, 3 },
                   { 1, 3, 8, 0, 4, 7, 2, 0, 6 },
                   { 6, 9, 2, 3, 5, 1, 8, 7, 4 },
                   { 7, 4, 5, 0, 8, 6, 3, 1, 0 } };

                   */

int ar[maxn][maxn] ={0};

void pr(){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++){
            cout << ar[i][j] <<" ";
        }
        cout <<"\n";
    }
}

bool chk(int r, int c, int k){
    for(int i=0;i<n;i++){
        if(ar[r][i]==k) return 0;
        if(ar[i][c]==k) return 0;
    }
    r/=3,c/=3;
    r*=3,c*=3;
    for(int i=r;i<=r+2;i++){
        for(int j=c;j<=c+2;j++){
            if(ar[i][j]==k) return 0;
        }
    }
    return 1;
}

int solve(){
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        bool can=0;
        if(!ar[i][j]){
            for(int k=1;k<=9;k++){
                if(chk(i,j,k)){
                    ar[i][j]=k;
                    solve();
                    ar[i][j]=0;
                }
            }
            return 0;
        }
    }
    pr();
    return 1;
}
int main()
{
    auto ans=solve();
    if(ans){
        cout <<"YES\n";
    }
    else{
        cout <<"NO\n";
    }

}
