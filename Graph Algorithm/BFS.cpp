#include<bits/stdc++.h>

using namespace std;

vector<int> BFS (vector<vector<int>> g,int source,int non)
{
    queue <int> Q;
    vector<int> level (non,-1);
    Q.push(source);
    level[source]  = 0;

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();

        for(auto v:g[u]){
            if(level[v]==-1){
                level[v] = level[u]+1;
                Q.push(v);
            }
        }
    }
    return level;
}

int main()
{
    int number_of_nodes,number_of_edges;
    cin>>number_of_nodes>>number_of_edges;
    vector<vector<int>> a(number_of_nodes);
    for(int i = 0;i<number_of_edges;i++){
        int u,v;
        cin>>u>>v;
        a[u-1].push_back(v-1);
        //a[v-1].push_back(u-1); //if the graph is undirected
    }
    vector<int> distance = BFS(a,6,number_of_nodes);
    for(int i = 1;i<=number_of_nodes;i++){
        cout<<i<<" "<<distance[i-1]<<endl;
    }
}
