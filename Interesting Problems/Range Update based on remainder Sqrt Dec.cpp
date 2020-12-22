// https://vjudge.net/problem/Gym-101182E

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
const int maxn=2e5+5;
const int sz=455;

stack<int> t[maxn];
int ans[maxn];
int sq[sz+5][sz+5];

/*
    Abridged identical problem:
    
    Given n lightbulbs, The ith lightbulb appears at time a_i, it is switched off initially. You have to turn it on.
    Lighbulb i turns off every b_i seconds after it is turned on.

    You have to keep every lightbulb (that has appeared so far) in time T_i on.
    Find out how many lightbulbs you need to switch on for every instant T_i in 1..T.
    
    n T
    4 8
    
    ai bi
    2  2
    1  3
    3  4
    5  10
    
    Output:
    1 1 1 2 1 1 2 1

*/
int main()
{
	fast_cin;
	int n,T;
	cin >> n >> T;
	for(int i=0;i<n;i++){
		int ai,bi;
		cin >> ai >> bi;
		t[ai].push(bi);
	}


	for(int i=1;i<=T;i++){
		for(int j=1;j<=sz;j++) ans[i]+=sq[j][i%j];     
		ans[i]+=(int)t[i].size();

		while(!t[i].empty()){
			auto u=t[i].top(); t[i].pop();
            
			if(i+u<=T){
				if(u>=sz)
					t[i+u].push(u);
				else{
					sq[u][i%u]++;       
				}
			}
		}
	}
	for(int i=1;i<=T;i++){
		cout << ans[i] <<" ";
	}
	cout <<"\n";
}
