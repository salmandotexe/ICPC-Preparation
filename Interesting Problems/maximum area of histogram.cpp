//this case easily simulates why this works.

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
    vi v={1,2,0,3,4,5,3,0,5,5,5};
    int n=v.size();

    stack<int> s;
    int i=0;

    ll res=0;
    //stack contains increasing order of heights.
    while(i<n){
        if(s.empty() || v[s.top()]<=v[i]){  //if v[i] higher, push in stack.
            s.push(i++);
        }
        else{
            //if current height v[i] is lower, 
            // while elements in stack are greater, find the area of rectangle with height= v[stack top].
            // (note that i is not incremented, while loop runs until s.empty() or top of stack<=v[i])
            // right side is i. left side is s.top() after popping.
            ll tp=s.top();
            s.pop();
            res=max(res,1LL*v[tp]*(s.empty()?i:i-s.top()-1));
        }
    }
    while(!s.empty()){
        ll tp=s.top();
        s.pop();
        res=max(res,1LL*v[tp]*(s.empty()?i:i-s.top()-1));
    }
    cout << res << endl;
}
