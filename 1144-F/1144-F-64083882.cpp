#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
int n, m;
int32_t main() {
    cin>>n>>m;
    bool vis[n+1];
    vector<pair<int, int>> edges;
    vector<pair<int, pair<int, int>>> adj[n+1];
    int a[n];
    int ans[m];
    queue<pair<int, int>> bfs;
    for(int i = 0;i<m;i++){
        int u, v;
        cin>>u>>v;
        edges.push_back(make_pair(u, v));
        adj[u].push_back(make_pair(v, make_pair(i, 1)));
        adj[v].push_back(make_pair(u, make_pair(i, 0)));
    }
    a[1] = 0;
    for(int i = 1;i<=n;i++) vis[i] = false;
    vis[1] = true;
    bfs.push(make_pair(1, 0));
    while(!bfs.empty()){
        pair<int, int> cnode = bfs.front();
        bfs.pop();
        for(pair<int, pair<int, int>> i: adj[cnode.first]){
            if(!vis[i.first]){
                vis[i.first] = true;
                bfs.push(make_pair(i.first, cnode.second^1));
            }
            else{
                if(a[i.first]!=(cnode.second^1)) goto cyc;
            }
            ans[i.second.first] = cnode.second^i.second.second;
            a[i.first] = cnode.second^1;
        }
    }
    if(false){
        cyc:
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i = 0;i<m;i++) cout<<ans[i];
    cout<<endl;
}