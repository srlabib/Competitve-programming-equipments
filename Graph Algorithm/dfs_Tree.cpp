vvi adj;
vi dt,ft,dp,level;
vi par;
int t=0; // initialize at each tc

// dp[u] is the number of back edges that crosses the parent edge of u
// dp[u] == 0 means the edge {parent[u],u} is a bridge

void dfs(int u, int p, int h) {
    dt[u] = ++t;
    par[u] = p;
    level[u] = h;

    for (int v : adj[u]) {
        if (v == p) continue;
        if (dt[v] == -1) {
            dfs(v, u, h+1);
            dp[u] += dp[v];  // the number back edge that goes up from the subtree of child
        } else if (dt[v] < dt[u]) {
            dp[u]++;     // number of edges that goes from the node 
            dp[v]--;     // removing the number of edges that actually ended at the node
        }
    }
    ft[u] = ++t;
}
