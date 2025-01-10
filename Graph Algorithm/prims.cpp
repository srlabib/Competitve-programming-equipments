//O(n*n)
#include<bits/stdc++.h>

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key

using namespace std; 
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

#define checkbit(x,n) (x&(1LL<<n))
#define setbit(x,n) (x=(x|(1LL<<n)))
#define resetbit(x,n) (x=(x&(~(1LL<<n))))

#define All(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i=a;i<b;i++)
template<typename T> void get_vector(T&a){for(auto&e:a)cin>>e;}
template<typename T> void put_vector(T a){for(auto e:a)cout<<e<<" ";cout<<endl;}
#define int long long
int inf = 1e18;

struct edge{
    int v ;
    int w ;
};
void solve()
{

    int n,e;
    cin>>n>>e; //NODES & EDGES
    vector<vector<int>>adj(n+1,vector<int>(n+1,inf));
    for(int i = 0; i<e; i++){
        int u,v,w;
        cin>>u>>v>>w;

        adj[u][v] = min(adj[u][v],w);
        adj[v][u] = min(adj[v][u],w);
    }

    int min_cost = 0;

    vector<edge>min_e(n+1,{0,inf});

    vector<bool>selected(n+1);
    
    selected[1] = 1;    // FIRST CHOOSING ARBITRARY FIRST ELEMENT

    int last = 1;   // LAST CHOSEN ELEMENT



    for(int i = 2; i<=n; i++){
        for(int to = 0; to<=n; to++){   //updating all min_edge from all non_selected elements to selected elements
            if(!selected[to] && adj[last][to]<min_e[to].w)min_e[to] = {last,adj[last][to]};
        }

        int v = -1;     
        for(int j = 1; j<=n; j++){      // choosing the next edge with min weight that connects a non-selected node to the selected nodes
            if(!selected[j] && (v == -1 || min_e[j].w < min_e[v].w )){
                v = j;
            }
        }

        if (min_e[v].w == inf) {  
            cout << "No MST!" << endl;
            exit(0);
        }

        min_cost += min_e[v].w;
        selected[v] = 1;
        last = v;

    }

    cout << min_cost << endl;

    

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}
