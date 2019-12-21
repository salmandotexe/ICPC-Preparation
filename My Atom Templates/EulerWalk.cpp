// convert rooted tree to array
// 0 - white(not yet visited), 1- grey(currently being explored), 2-black(explored completely )
vector<int> color(MX+1);
vector<int> parent(MX+1);
int tt=0;
vector<int> tin(MX+1) ; 	// v was visited at tin[v] time
vector<int> tout(MX+1);		// v was left at tout[v] time
vector<int> vis(MX+1);		// at time tt, vis[tt] node was visited
void dfs(int v)
{
	color[v] = 1 ;		// grey

	vis[tt] = v ;
	tin[v] = tt++ ;
	for( auto& u : G[v] )
	{
		if ( color[u] == 0 )		// white
		{
			dfs(u) ;
			parent[u] = v ;
		}

	}
	tout[v] = tt ;

	color[v] = 2 ;		// black
}
// vis is the array of the rooted tree
