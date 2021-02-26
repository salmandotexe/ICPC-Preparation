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
const int maxn=4e5+5;

struct node
{
	int op;
	ll l,r;
}a[maxn>>1];//n events

struct Tree
{
	int l,r;
	set<int> id;
}tree[maxn<<2];//Line segment tree

ll b[maxn];//Discretization of abscissa
int n,tot;

void build(int i,int l,int r)
{
	tree[i].l=l,tree[i].r=r;
	if(l==r)
		return ;
	int mid=l+r>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
}

void update(int i,int l,int r,int idx)
{
	if(tree[i].l==l&&tree[i].r==r)//Target interval
	{
		tree[i].id.insert(idx);//Insert the idx of the target
		return ;
	}
	int mid=tree[i].l+tree[i].r>>1;
	if(r<=mid)
		update(i<<1,l,r,idx);
	else if(l>mid)
		update(i<<1|1,l,r,idx);
	else
		update(i<<1,l,mid,idx),
		update(i<<1|1,mid+1,r,idx);
}

int query(int i,int pos,int idx)
{
	set<int> ::iterator it=tree[i].id.begin(),ed=tree[i].id.end();
	ll x,y;
	while(it!=ed)//Violently judge which target the shot was inside
	{
		x=a[*it].l,y=a[*it].r;//Target center coordinates
		if(((a[idx].l-x)*(a[idx].l-x)+(a[idx].r-y)*(a[idx].r-y))<y*y)//The shooting point is inside the target
			return *it;
		++it;
	}
	if(tree[i].l==tree[i].r)//The leaf node has not yet returned, indicating that the shot did not hit the target
		return -1;
	int mid=tree[i].l+tree[i].r>>1;
	if(pos<=mid)
		return query(i<<1,pos,idx);
	else
		return query(i<<1|1,pos,idx);
}

void del(int i,int l,int r,int idx)
{
	if(tree[i].l==l&&tree[i].r==r)
	{
		tree[i].id.erase(idx);
		return ;
	}
	int mid=tree[i].l+tree[i].r>>1;
	if(r<=mid)
		del(i<<1,l,r,idx);
	else if(l>mid)
		del(i<<1|1,l,r,idx);
	else
		del(i<<1,l,mid,idx),
		del(i<<1|1,mid+1,r,idx);
}

int main()
{
	scanf("%d",&n);
	int op;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %lld %lld",&a[i].op,&a[i].l,&a[i].r);
		if(a[i].op==1)//Create a target
			b[++tot]=a[i].l-a[i].r,b[++tot]=a[i].l+a[i].r;
		else //shooting
			b[++tot]=a[i].l;
	}
	sort(b+1,b+1+tot);//Sorting and de-duplication for discretization
	tot=unique(b+1,b+1+tot)-b-1;
	build(1,1,tot);//Build a tree
	int l,r,pos,ans;
	for(int i=1;i<=n;i++)
	{
		if(a[i].op==1)//Create a target
		{
			l=lower_bound(b+1,b+1+tot,a[i].l-a[i].r)-b;//Get the interval where the target is [l,r]
			r=lower_bound(b+1,b+1+tot,a[i].l+a[i].r)-b;
			update(1,l,r,i);//Insert the number i in the set that maintains the line segment tree node of the interval
		}
		else //shooting
		{
			pos=lower_bound(b+1,b+1+tot,a[i].l)-b;//Get the abscissa of the shot discretized
			ans=query(1,pos,i);//Query target number
			printf("%d\n",ans);
			if(ans!=-1)//If the target exists, delete it
			{
				l=lower_bound(b+1,b+1+tot,a[ans].l-a[ans].r)-b;
				r=lower_bound(b+1,b+1+tot,a[ans].l+a[ans].r)-b;
				del(1,l,r,ans);
			}
		}
	}
	return 0;
}
