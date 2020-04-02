//toposort does not exist if graph contains cycles.

void dfs(int x, int parent) {
    vis[x] = true;
    inStack[x] = true;
    for(int u = 0; u < n; u++) {
        if (graph[x][u] == 1 && u != parent && vis[u] && inStack[u]) {
            // there is a cycle: u -> ... -> parent -> x
        }
        if(!vis[u] && graph[x][u] == 1) {
            dfs(u, x);
        }
    }
    inStack[x] = false;
    order.push_back(x);
}
