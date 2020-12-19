//https://vjudge.net/problem/Gym-100971H

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

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
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int maxn=200005;

vi a[maxn],b[maxn];

int main()
{
	fast_cin;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		a[x].pb(i+1);
		b[y].pb(i+1);
	}
	ordered_set s;
	for(int k=1;k<=n;k++){
		for(auto i : a[k]) s.insert(i);
		for(auto i : b[k-1]) {
			auto it=s.find(i);
			if(it!=s.end()) s.erase(it);
		}
		auto it=s.find_by_order(k-1);
		if(it==s.end()) cout <<"-1 ";
		else{
			cout << *it <<" ";
		}
	}
}

/*
        In this problem for each k we find kth smallest index such that a[i] <= k <= b[i]
        Before processing each k, add the new members from from a[] such that k>=a[i].
        And erase the members with b[i] <= k-1. 
        
        Then we use some form of Tree Order statistic. in this case, ordered_set. Alternatives are Segtree, Fenwick/BIT or Sqrt structure.
*/
