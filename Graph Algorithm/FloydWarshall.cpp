#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
#define All(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i=a;i<b;i++)
template<typename T> void get_vector(T&a){for(auto&e:a)cin>>e;}
template<typename T> void put_vector(T a){for(auto e:a)cout<<e<<" ";cout<<endl;}

const ll inf = 1e18;

//complexity O(n^3)

void FloyedWarshall(vector<vl> &graph,vector<vl>&next){
    int n = graph.size();
    FOR(k,1,n){
        FOR(i,1,n){
            FOR(j,1,n){
                if(graph[i][j]>graph[i][k]+graph[k][j]){
                    graph[i][j] = graph[i][k]+graph[k][j];
                    next[i][j] = next[i][k]; //storing the next step for this path
                }
                //graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j])  when we don't need the path, only this line can be written instead of the if block
            }
        }
    }
}

vi find_path(int i, int j, vector<vl>&next){
    vi path;
    path.push_back(i);
    while (i!=j)
    {
        i = next[i][j];//going through the next steps until we reach the destination
        path.push_back(i);
    }
    return path;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,q;
    cin>>n>>m>>q;
    vector<vl>graph(n+1,vl(n+1,inf)),next(n+1,vl(n+1));
    FOR(i,0,n+1)FOR(j,0,n+1)next[i][j] = j;
    FOR(i,0,n+1)graph[i][i] = 0;
    while(m--){
        ll u,v,w;
        cin>>u>>v>>w;
        graph[u][v] = min(graph[u][v],w);
        graph[v][u] = min(graph[v][u],w);
    }
    FloyedWarshall(graph,next);

    //answering queries
    while(q--){
        int u,v;
        cin>>u>>v;
        cout << (graph[u][v]==inf?-1:graph[u][v]) << endl;
        if(graph[u][v]!=inf)put_vector(find_path(u,v,next));
    }



    
    return 0;
}
