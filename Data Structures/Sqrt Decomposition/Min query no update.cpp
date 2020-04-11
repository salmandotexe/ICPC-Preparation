#include <stdio.h>
#include <cmath>
#include <algorithm>
#define inf 0x3f3f3f3f
#define in(x) scanf("%d", &x)
#define IN(x) scanf("%lld", &x)
#define get(x) x/sz

using namespace std;

const int maxn=100005;
int ar[maxn];
int sq[100+(int)sqrt(maxn)];
int sz;

int query(int l, int r){
    int mn=inf;
    while(l<r && l%sz && l) mn=min(mn,ar[l++]);
    while(l+sz<=r) mn=min(mn,sq[get(l)]),l+=sz;
    while(l<=r) mn=min(mn,ar[l++]);
    return mn;
}

//https://vjudge.net/problem/LightOJ-1082

int main()
{
    int T;
    in(T);
    for(int tc=1;tc<=T;tc++){
        int n,q;
        in(n); in(q);
        sz=sqrt(n)+1;
        for(int i=0;i<n;i++) in(ar[i]);
        for(int i=0;i<=sz+1;i++) sq[i]=inf;

        for(int i=0;i<n;i++) sq[i/sz]=min(sq[i/sz],ar[i]);
        printf("Case %d:\n",tc);
        while(q--){
            int u,v;
            in(u);in(v);
            auto ans=query(u-1,v-1);
            printf("%d\n",ans);
        }
    }
}
