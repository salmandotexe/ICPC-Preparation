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

//  Convex Hull - Returns vector of points belonging to hull in anti-clockwise order.
typedef complex<double> point;
#define x real()
#define y imag()
double dot(point a,point b){ return (conj(a)*b).x ; }
double cross(point a,point b){ return (conj(a)*b).y ; }
double dist(point a, point b){ return abs(a-b); }			//distance btw points a and b
double dist(point a, point b, point c, bool issegment = false){		//distance btw line ab and point c
	double d = cross(b-a,c-a)/dist(a,b) ;
	if( issegment == true )						// if line is a segment, issegment is true
	{
		double dt1 = dot(b-a,c-b) ;
		if( dt1 > 0 )  return dist(b,c);
		double dt2 = dot(a-b,c-a) ;
		if( dt2 > 0 )  return dist(a,c);
	}
	return abs(d) ;
}
template<class T>
istream& operator>> (istream& is, complex<T>& p){
   T value;
   is >> value;
   p.real(value);
   is >> value;
   p.imag(value);
   return is;
}
bool cmp(point& a, point& b)
{
	if ( a.x == b.x )
	{
		return a.y < b.y ;
	}
	else
	{
		return a.x < b.x ;
	}
}
vector<point> hull(vector<point> P)
{
   int n = P.size() ;
   int k = 0;
   vector<point> H(2*n) ;
   sort( all(P), cmp );
   for (int  i = 0;  i < n;  i++) {			// lower monotone chain
		while( k>=2 && cross( H[k-1]-H[k-2], P[i]-H[k-2] ) <= 0)
				k--;
		H[k++] = P[i] ;
   }
   for (int  i = n-2, t=k+1;  i >= 0;  i--) {		// upper monotone chain
		while( k>=t && cross( H[k-1]-H[k-2], P[i]-H[k-2] ) <= 0)
				k--;
		H[k++] = P[i];
   }
   H.resize(k-1);
   return H;
}

int main()
{


}
