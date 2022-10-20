//Tested on: https://vjudge.net/problem/Gym-103729L

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;

struct node{
    ll sum = 0, laz = 0, cnt = 0;
};

const int maxn = 1e5+5;

node Tree[4*maxn];
ll a[maxn];
ll s[maxn];

node zero;

node make_data(int lo){
    node ret = zero;
    ret.cnt= s[lo];
    ret.sum = a[lo];
    ret.laz = 0;
    return ret;
}

inline node operator+ (const node& a, const node& b){
    node ret=zero;
    ret.cnt = a.cnt + b.cnt;
    ret.sum = a.sum + b.sum;
    return ret;
}

inline void push(int i){
    if(Tree[i].laz){
        Tree[i<<1].laz += Tree[i].laz;
        Tree[i<<1].sum += Tree[i<<1].cnt*Tree[i].laz;
        Tree[i<<1|1].laz += Tree[i].laz;
        Tree[i<<1|1].sum += Tree[i<<1|1].cnt*Tree[i].laz;
        Tree[i].laz = 0;
    }
}

inline void build(int lo = 0, int hi = n-1, int i = 1){
    if(lo>=hi){
        Tree[i] = make_data(lo);
        return;
    }
    int mid = lo + hi >> 1;
    build(lo,mid,i<<1);
    build(mid+1,hi,i<<1|1);
    Tree[i] = Tree[i<<1] + Tree[i<<1|1];
}

node get(int a, int b, int lo = 0, int hi = n-1, int i = 1){
    if(b<lo || a > hi || a > b) return zero;
    if(a<=lo && hi <=b){
        return Tree[i];
    }
    push(i);
    int mid = lo + hi >>1;
    auto ans = get(a,b,lo, mid, i<<1) + get(a,b,mid+1, hi, i<<1|1);
    Tree[i] = Tree[i<<1] + Tree[i<<1|1];
    return ans;
}

inline void fix(int pos, ll val, int lo = 0, int hi = n-1, int i = 1){
    if(pos < lo || pos > hi || lo>hi) return;

    if(pos==lo && lo==hi){
        Tree[i].cnt = val;
        return;
    }
    push(i);
    int mid = lo + hi >> 1;
    fix(pos,val,lo,mid,i<<1);
    fix(pos,val,mid+1,hi,i<<1|1);
    Tree[i] = Tree[i<<1] + Tree[i<<1|1];
}

inline void add(int a, int b, ll val , int lo = 0 ,int hi  = n-1, int i = 1){
    if(b< lo || a > hi || lo  > hi) return;

    if(a<=lo && hi <=b){
        Tree[i].sum += Tree[i].cnt * val;
        Tree[i].laz += val;
        return;
    }
    push(i);
    int mid = lo + hi >> 1;
    add(a,b,val,lo,mid,i<<1);
    add(a,b,val,mid+1,hi,i<<1|1);
    Tree[i] = Tree[i<<1] + Tree[i<<1|1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef salman
        freopen("in.txt","r",stdin);
    #endif
    int q;
    cin >> n >> q;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> s[i];
    build();
    while(q--){
        int ty;
        cin >> ty;
        if(ty==2 || ty==1){
            int pos;
            cin >> pos;
            pos--;
            fix(pos,ty==2);
        }
        else if(ty==3){
            ll x,y,v;
            cin >> x >> y >> v;
            x--,y--;
            add(x,y,v);
        }
        else{
            int x,y;
            cin >> x >> y;
            x--,y--;
            cout << get(x,y).sum <<"\n";
        }
    }
}
