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
#define precise fixed(cout);cout<<setprecision(16);
#define OUT(x) for(auto a:x) cout << a << " "; cout << endl;
#define OK cout << "@===================ok===================@" <<endl;
#define WTF cout <<"< "<<lo<<" | "<< hi <<" >" << endl;

using namespace std;
const int maxn=100005;

ll t[4*maxn];
ll laz[4*maxn];
int n;

inline void prop(int i){
    laz[2*i]+=laz[i];
    laz[2*i+1]+=laz[i];
    laz[i]=0;
}

inline void add(int a, int b, int val, int i=1, int lo=0, int hi=n-1){
    if(b<lo || a>hi || lo>hi) return;//Interval is disjoint. do nothing

    if(a<=lo && hi<=b){//Interval is enclosed. update lazily
        laz[i]+=val;
        return;
    }

    int m=(lo+hi)/2;

    //Parial covering: push down lazy changes to children.

    prop(i);

    //Find stuff for children.
    add(a,b,val,2*i,lo,m);
    add(a,b,val,2*i+1,m+1,hi);

    //Update node.
    t[i]=t[2*i]+(m-lo+1)*laz[2*i] + t[2*i+1]+(hi-m)*laz[2*i+1];
}


inline ll get(int a, int b, int i=1, int lo=0, int hi=n-1){
    if(b<lo || a>hi) return 0;
    if(a<=lo && hi<=b){
        return t[i] +(hi-lo+1)*laz[i];
    }
    int m=(lo+hi)/2;
    prop(i);
    ll ans= get(a,b,2*i,lo,m) + get(a,b,2*i+1,m+1,hi);
    t[i]=t[2*i]+(m-lo+1)*laz[2*i] + t[2*i+1]+(hi-m)*laz[2*i+1];
    return ans;
}

int main()
{
    //Segment Tree RSQ. lightoj problem link: https://vjudge.net/problem/LightOJ-1164
    //fast_cin e mara
    int T,k;
    scanf("%d", &T);
    for(int tc=1;tc<=T;tc++)
    {
        scanf("%d%d", &n,&k);
        printf("Case %d:\n", tc);
        mem(t,0); mem(laz,0);       								//memset(t,0,sizeof(t));

        while(k--){
            int A,B,C,D;
            scanf("%d", &A);
            if(A==1){												//handle rsq
                scanf("%d%d", &B,&C);
                printf("%lld\n", get(B,C));
            }
            else if (A==0){											//handle update queries.
                scanf("%d%d%d", &B,&C,&D);
                add(B,C,D);
            }
        }

    }
}
