// Area of polygon whose perimeter points are given in order in array
vector< point > p;
double polyarea(){
	double area = 0;
	int n = p.size();
	for(int i=1; i+1<n ; i++ )
	{
		point v1 = p[i] - p[0] ;	//taking 0th point as origin
		point v2 = p[i+1] - p[0] ;
		area += cross(v1,v2) ;
	}
	return abs(area/2.0);
}
