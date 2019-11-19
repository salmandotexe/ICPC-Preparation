#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);
#define precise fixed(cout);cout<<setprecision(16);
#define OUT(x) for(auto a:x) cout << a << " "; cout << endl;
#define OK cout << "@===================ok===================@" <<endl;
#define WTF cout <<"< "<<lo<<" | "<< hi <<" >" << endl;

using namespace std;
const int maxn=2e5+5;

ll Min[4*maxn];
ll laz[4*maxn];
ll v[maxn];
int n;

void init(int i, int a, int b){
    if(a==b) {
        Min[i] = v[a];
        return;
    }
    int m= (a+b)/2;
    init(2*i, a,m);
    init(2*i+1, m+1,b);
    Min[i]=min(Min[2*i],Min[2*i+1]);
}

void prop(int i){
    laz[2*i]+=laz[i];
    laz[2*i+1]+=laz[i];
    laz[i]=0;
}

void update(int i){
    Min[i]=min(Min[2*i]+laz[2*i],Min[2*i+1]+laz[2*i+1]);
}

void add( int a, int b, int val, int i=1, int lo=0, int hi=n-1){
    if(b<lo || a>hi) return;//
    if(a<=lo && hi<=b) {
        laz[i]+=val;
        return;
    }
    int m=(lo+hi)/2;
    //partial.
    prop(i);
    add(a,b,val,2*i,lo,m);
    add(a,b,val,2*i+1,m+1,hi);
    update(i);
}

ll get( int a, int b, int i=1, int lo=0, int hi=n-1){
    if(b<lo || a>hi) return inf;//
    if(a<=lo && hi<=b) {
        return Min[i]+laz[i];
    }
    int m=(lo+hi)/2;
    //partial.
    prop(i);
    ll mn=min(get(a,b,2*i,lo,m),get(a,b,2*i+1,m+1,hi));
    update(i);
    return mn;
}

/*
      Solution to: https://codeforces.com/problemset/problem/52/C
*/

int main()
{
    fast_cin

    cin >> n;
    //SegTree st(n);
    int x;
    for(int i=0;i<n;i++) //,st.increment(i,i,v[i]);
    {
        cin >> v[i];
        add(i,i,v[i]);
    }
    int q;
    cin >> q;
    cin.ignore();
    while(q--){
        string str;
        getline(cin,str);
        stringstream ss(str);
        ll x;
        vll what;
        while(ss >> x){
            what.pb(x);
        }
        if(what.size()==2){
            ll a=what[0];
            ll b=what[1];
            ll mn=inf;

            if(a<=b){
                //mn=st.query(a,b);
                mn=get(a,b);
            }
            else{
                //mn=min(st.query(0,b),st.query(a,n-1));
                mn=min(get(0,b),get(a,n-1));
            }
            cout << mn << endl;
        }
        else{
            ll a=what[0];
            ll b=what[1];
            ll c=what[2];

            if(a<=b) {
                //st.increment(a,b,v);
                add(a,b,c);
            }
            else{
                //st.increment(0,b,v);
                add(0,b,c);
                //st.increment(a,n-1,v);
                add(a,n-1,c);
            }
        }
    }
}
