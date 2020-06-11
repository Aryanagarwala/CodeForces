#include <iostream>
    #include <queue>
    #include <algorithm>
    #include <cmath>
    #include <map>
    #include <vector>
    #include <set>
    #include <unordered_map>
    #define um unordered_map
    #define mid(l, u) (l+u)/2
    #define rchild(i) (i*2 + 2)
    #define lchild(i) (i*2 + 1)
    #define int long long
    using namespace std;
    int32_t main(){
        int n, m, k;
        cin>>n>>m>>k;
        int spe[k];
        vector<int> adj[n+1];
        unordered_map<int, bool> spec;
        unordered_map<int, bool> vis;
        int dist[n+1][2];
        for(int i =0 ;i<k;i++){
            cin>>spe[i];
            spec[spe[i]] = true;
        }
        for(int i = 0;i<m;i++){
            int x, y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int count = 0;
        //BFS FROM 0
        int currentdist = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(1, 0));
        vis[1] = true;
        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();
            dist[curr.first][0] = curr.second;
            if(curr.first==n){
                currentdist = curr.second;
            }
            for(int j: adj[curr.first]){
                if(vis[j]) continue;
                vis[j] = true;
                q.push(make_pair(j, curr.second+1));
            }
        }
        while(!q.empty()) q.pop();
        q.push(make_pair(n, 0));
        for(int i = 1;i<=n;i++) vis[i] = false;
        vis[n] = true;
        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();
            dist[curr.first][1] = curr.second;
            for(int j: adj[curr.first]){
                if(vis[j]) continue;
                vis[j] = true;
                q.push(make_pair(j, curr.second+1));
            }
        }
        int best = -100;
        int smol = 10000000000;
        vector<pair<int, int>> v;
        for(int i = 0;i<k;i++){
            v.push_back(make_pair(dist[spe[i]][0], dist[spe[i]][1]));
        }
        sort(v.begin(), v.end());
        smol = v[0].second;
        for(int i = 1;i<k;i++){
            if(smol<=v[i].second){
                cout<<currentdist<<endl;
                return 0;
            }
            smol = min(smol, v[i].second);
            best = max(best, v[i-1].first + 1 + v[i].second);
        }
        int ans = min(best, currentdist);
        cout<<ans<<endl;
        return 0;
    }