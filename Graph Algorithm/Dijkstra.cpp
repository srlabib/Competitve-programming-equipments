#include<bits/stdc++.h>
 
using namespace std;
 
 
vector<bool>mark;
const long long inf = 1e18;
vector<long long> distance(vector<vector<pair<long long,long long>>>G,int source){
    set<pair<long long,long long>>Q;
    vector<long long>distance(G.size(),inf);
 
    Q.insert({0,source});
    distance[source] = 0;
    while(!Q.empty()){
        int u = (*Q.begin()).second;
        Q.erase(Q.begin());
        if(mark[u]==1)continue;
        mark[u] = 1;
        for(auto v:G[u]){
            if(distance[v.first]>distance[u]+v.second){
                distance[v.first] = distance[u]+v.second;
                Q.insert({distance[v.first],v.first});
            }
        }
    }
    return distance;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    mark.resize(n+1);
    vector<vector<pair<long long,long long>>>graph(n+1);
    int q;
    cin>>q;
    while(q--){
        long long u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }
    vector<long long>res = distance(graph,1);
    for(int i = 1; i<=n; i++)cout << res[i]<< ' ';
    cout << endl;
 
 
}
