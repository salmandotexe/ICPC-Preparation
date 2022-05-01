// Can A be transformed into B using a stack?
// https://github.com/salmandotexe/IUPC-Solutions/tree/main/KUET%20IUPC%202019 
// Problem A: Stack Mania
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
vi pos[maxn];

int main()
{
    fast_cin;
    int T;
    cin >> T;
    for(int tc=1;tc<=T;tc++)
    {
        int n;
        cin >> n;
        vi a(n),b(n);
        queue<int> ip,op;
        for(int i=0;i<n;i++){
            cin >> a[i];
            ip.push(a[i]);
        }

        for(int i=0;i<n;i++){
            cin >> b[i];
            op.push(b[i]);
        }
        stack<int> st;

        while(!ip.empty()){
            auto cur = ip.front();
            if(cur == op.front()){
                op.pop();
                ip.pop();
                while(!st.empty() && st.top() == op.front()) st.pop(), op.pop();
            }
            else{
                st.push(cur);
                ip.pop();
            }
        }
        cout <<"Case "<<tc<<": ";
        if(st.empty() && ip.empty() && op.empty()){
            cout <<"POSSIBLE\n";
        }
        else{
            cout <<"IMPOSSIBLE\n";
        }
    }
}
