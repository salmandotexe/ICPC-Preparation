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
template<class T>
istream& operator>> (istream& is, complex<T>& p){
   T value;
   is >> value;
   p.real(value);
   is >> value;
   p.imag(value);
   return is;
}
