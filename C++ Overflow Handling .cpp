const int64_t INF = INT64_MAX;

inline int64_t mul(int64_t a, int64_t b)
{
	return (INF / a > b ? a * b : INF);
}

inline int64_t add(int64_t a, int64_t b)
{
	return (a + b >= INF ? INF : a + b);
}

//returns INF if overflow occurs.
