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
const int maxn=200005;
ll Sum[4*maxn];
ll laz[4*maxn];
ll v[maxn];
int n;

void init(int i, int a, int b){
    if(a==b) {
        Sum[i] = v[a];
        return;
    }
    int m= (a+b)/2;
    init(2*i, a,m);
    init(2*i+1, m+1,b);
    Sum[i]=(Sum[2*i] + Sum[2*i+1]);
}

void prop(int i){
    laz[2*i]+=laz[i];
    laz[2*i+1]+=laz[i];
    laz[i]=0;
}

void update(int i){
    Sum[i]=(Sum[2*i]+laz[2*i]+Sum[2*i+1]+laz[2*i+1]);
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
    if(b<lo || a>hi) return 0;//
    if(a<=lo && hi<=b) {
        return (Sum[i]+laz[i]);
    }
    int m=(lo+hi)/2;
    //partial.
    prop(i);
    ll s=(get(a,b,2*i,lo,m)+get(a,b,2*i+1,m+1,hi));
    update(i);
    return s;
}

int main()
{

    int T;
    cin >> T;
    ll p=0;
    ll w=0;
    for(int tc=1;tc<=T;tc++)
    {
        mem(laz,0);
        mem(Sum,0);
        cin >> n;
        //SegTree st(n);
        for(int i=0;i<n;i++) //,st.increment(i,i,v[i]);
        {
            cin >> v[i];
            add(i,i,v[i]);
        }
        int q;
        cin >> q;
        bool tr=1;
        while(q--){
            int l,r;
            cin >> l >> r;
            ll ans=get(l,r);
            ll ex;
            cin >> ex;
            if(ex==ans){
                p++;
            }
            else{
                w++;
                tr=0;
            }
        }
        if(tr){
            //cout <<"Case "<<tc<<" passed.\n";
        }
    }
}
