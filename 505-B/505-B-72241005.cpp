#include<iostream>
#include<algorithm>
#include <vector>
#include <queue>
#include <set>
#include<deque>
#include <map>
#define int long long
#define INF 10000000000000000
#define mir(i) (n-1-i)
#define mid(l, u) ((l+u)/2)
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
using namespace std;
int32_t main(){
    int n, m;
    cin>>n>>m;
    vector<pair<int, int>> adj[n+1];
    for(int i = 0;i<m;i++){
        int u, v, c;
        cin>>u>>v>>c;
        adj[u].push_back(make_pair(v, c));
        adj[v].push_back(make_pair(u, c));
    }
    int q;
    cin>>q;
    while(q--){
        int u, v;
        cin>>u>>v;
        int ans = 0;
        for(int col = 1;col<=m;col++){
            queue<int> q;
            q.push(u);
            bool vis[n];
            for(int i = 0;i<=n;i++) vis[i] = false;
            vis[u] = true;
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                if(curr==v) ans++;
                for(pair<int, int> j: adj[curr]){
                    if(vis[j.first]||j.second!=col) continue;
                    vis[j.first] = true;
                    q.push(j.first);
                }
            }
        }
        cout<<ans<<endl;
    }
}