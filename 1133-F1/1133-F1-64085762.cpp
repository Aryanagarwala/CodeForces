#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
int n, m;
int findroot(int i, int root[]){
    if(i==root[i]) return i;
    else return root[i] = findroot(root[i], root);
}
bool UNION(int i, int j, int root[], int ranks[]){
    int r1 = findroot(i, root), r2 = findroot(j, root);
    if(r1==r2) return false;
    if(ranks[r1]<ranks[r2]){
        root[r1] = r2;
        ranks[r2]+=ranks[r1];
    }
    else{
        root[r2] = r1;
        ranks[r1]+=ranks[r2];
    }
    return true;
}
int32_t main() {
    cin>>n>>m;
    int root[n+1], ranks[n+1], order[n+1];
    for(int i = 1;i<=n;i++){
        root[i] = i;
        ranks[i] = 1;
        order[i] = 0;
    }
    vector<int> adj[n+1];
    vector<pair<int, int>> edges;
    vector<pair<int, int>> include;
    for(int i = 0;i<m;i++){
        int u, v;
        cin>>u>>v;
        order[v]++;
        order[u]++;
        edges.push_back(make_pair(u, v));
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int maxedge = 1;
    for(int i = 2;i<=n;i++){
        if(order[i]>order[maxedge]) maxedge = i;
    }
    for(int j: adj[maxedge]){
        UNION(maxedge, j, root, ranks);
        include.push_back(make_pair(maxedge, j));
    }
    for(pair<int, int> e: edges){
        if(e.first==maxedge || e.second==maxedge) continue;
        if(UNION(e.first, e.second, root, ranks)){
            include.push_back(make_pair(e.first, e.second));
        }
    }
    for(pair<int, int> e: include){
        cout<<e.first<<" "<<e.second<<endl;
    }
}