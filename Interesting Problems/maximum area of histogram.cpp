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
    while(i<n){
        if(s.empty() || v[s.top()]<=v[i]){  //if higher, push in stack.
            s.push(i++);
        }
        else{
            //if lower, while the top of stack is more than current element, keep popping.
            //when we do pop, we check answer and update maximum.
            //since we store the indices in stack, we can retrieve the width (len.) wrt the v[top of stack].
            // If this bar is lower than top of stack,  
            // then calculate area of rectangle with stack  
            // top as the smallest (or minimum height) bar.  
            // 'i' is 'right index' for the top and element  
            // before top in stack is 'left index' 
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
