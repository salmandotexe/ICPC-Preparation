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

const int maxn=1e5+5;
const int sz=345;

int n;
int a[maxn];
vi b[sz];


void build(){
    for(int i=0,j=0,c=0;i<n;i++,c++){
        if(c>=sz) c=0, j++;
        b[j].pb(a[i]);
    }
    for(int i=0;i<sz;i++) sort(all(b[i]));
}

//This gets the count of numbers greater than k in a[L...R]

ll query(int l, int r, int k){
    ll res=0;
    int b_l = l/sz, b_r=r/sz;

    if(b_l==b_r) for(int i=l;i<=r;i++) res+= (a[i]>k);
    else {

        for(int i=l, en=(b_l+1)*sz-1; i<=en; i++){
            res += (a[i]>k);
        }

        for(int i=b_l+1; i<b_r; i++){
            res += (b[i].end()-upper_bound(all(b[i]),k));
        }

        for(int i=b_r*sz; i<=r; i++){
            res += (a[i]>k);
        }
    }
    return res;
}



int main()
{
    fast_cin;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    build();
    int q;
    cin >> q;
    while(q--){
        int i,j,k;
        cin >> i >> j >> k;
        i--,j--;
        cout << query(i,j,k) <<"\n";  //O(sqrt(N) logn) constant factor high.
    }


}
