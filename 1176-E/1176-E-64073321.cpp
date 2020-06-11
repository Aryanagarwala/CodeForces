#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int32_t main() {
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        bool vis[n];
        vector<int> adj[n];
        vector<int> sol[2];
        for(int i = 0;i<n;i++) vis[i] = false;
        for(int i = 0;i<m;i++){
            int u, v;
            cin>>u>>v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        queue<pair<int, int>> bfs;
        bfs.push(make_pair(0, 0));
        vis[0] = true;
        while(!bfs.empty()){
            pair<int, int> current = bfs.front();
            bfs.pop();
            sol[current.second].push_back(current.first);
            for(int j: adj[current.first]){
                if(!vis[j]){
                    vis[j] = true;
                    bfs.push(make_pair(j, current.second^1));
                }
            }
        }
        int ind = sol[0].size()>sol[1].size()?1:0;
        cout<<sol[ind].size()<<endl;
        for(int j: sol[ind]) cout<<(j+1)<<" ";
        cout<<endl;
    }
}