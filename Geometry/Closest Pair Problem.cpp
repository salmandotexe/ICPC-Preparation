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

int n;

struct point{
    double x,y;
};
inline bool cmpx(const point &a, const point &b){
    if(a.x<b.x) return 1;
    if(a.x==b.x) return a.y<b.y;
    return 0;
}

inline bool cmpy(const point &a, const point &b){
    if(a.y<b.y) return 1;
    if(a.y==b.y) return a.x<b.x;
    return 0;
}
inline double dist(const point &a, const point &b){
    double dx=b.x-a.x;
    double dy=b.y-a.y;
    return sqrt(dx*dx+dy*dy);
}

const int maxn=1e5+5;

point a[maxn];
point temp[maxn];

double solve(int l, int r)//
{
    if(r-l==1) return dist(a[l],a[r]);
    if(r-l==2) return min(dist(a[l],a[l+1]),dist(a[r],a[l+1]));
    int m=(l+r)/2;
    double d=min(solve(l,m),solve(m+1,r));                   //divides in the middle, finds answer for left and right partitions.
    int p=0;
    for(int i=l;i<=r;i++){      //accounts for the case where one point lies in left half, other in right. so, considers point a[i] if a[m].x - d< a[i].x < a[m].x + d.
        if(a[m].x-d < a[i].x && a[i].x < a[m].x+d){
            temp[p++]=a[i];
        }
    }
    sort(temp,temp+p,cmpy);
    for(int i=0;i<p;i++) for(int j=i+1;j<p;j++){
        if(temp[j].y-temp[i].y>d) break;
        d=min(d,dist(temp[i],temp[j]));
    }
    return d;
}
int main()
{
    scanf("%d", &n);
    double ans=0;
    for(int i=0;i<n;i++) scanf("%lf%lf", &a[i].x, &a[i].y);
    sort(a,a+n,cmpx);
    ans=solve(0,n-1);
    printf("%.6f\n", ans);
}
