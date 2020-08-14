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
//https://codeforces.com/contest/1398/problem/C
    fast_cin;
    int T;
    cin >> T;
    for(int tc=1;tc<=T;tc++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vll pref(n+2);
        for(int i=1;i<=n;i++){
            pref[i]+=pref[i-1]+(s[i-1]-'0');
        }
        ll res=0;
        map<ll,int> m;

        //explanation: Sum of subarray[l..r] = pref[r] - pref[l-1]
        //Count in how many places, the following holds:
        //    pref[r]-pref[l-1] == r - l + 1
        //=>  pref[r] - r == pref[l-1] - l + 1.

        for(int i=1;i<=n;i++){
            ll pp=pref[i-1]-i+1;
            m[pp]++;
            res+=m[pref[i]-i];
        }
        cout << res <<"\n";
    }
}
