#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
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


/*  Suffix Array Template starts here */
const int inf=0x3f3f3f3f;

const int maxn=10000010;
const int maxlg=26;

int Plc[maxlg][maxn];
int S[maxn], stp;
pair<pii,int> L[maxn];

void generate_SA(const string &s){
    int n = s.size();
    for(int i = 0; i < n; i++) Plc[0][i] = s[i];
    int cur;
    for(cur = stp = 1; (cur>>1) < n; cur*=2, stp++){
        for(int i=0; i<n; i++){
            L[i].f.f= Plc[stp-1][i];
            L[i].f.s= i+cur<n ? Plc[stp-1][i+cur] : -inf;
            L[i].s=i;
        }
        sort(L,L+n);
        for(int i=0;i<n;i++){
            if(!i || L[i-1].f.f!=L[i].f.f || L[i-1].f.s !=L[i].f.s ) Plc[stp][L[i].s]=i;
            else Plc[stp][L[i].s] = Plc[stp][L[i-1].s];
        }
    }
    for(int i=0;i<n;i++){
        S[Plc[stp-1][i]]= i;
    }
    stp--;
}

int lcp(int u, int v, int n){
    int ret=0,k;
    if(u==v) return n-u;
    for(k = stp; k>=0 && u<n && v<n; k--)
        if(Plc[k][u]==Plc[k][v]) ret+= 1<<k, u+= 1<<k, v+= 1<<k;
    return ret;
}



int main()
{
    fast_cin;
    string s;
    cin >> s;
    int n=s.size();
    generate_SA(s);
    for(int i=0;i<n;i++){
        cout << S[i] <<"\n";
    }
    //https://vjudge.net/problem/SPOJ-SARRAY
}
