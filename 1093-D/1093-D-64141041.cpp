#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define int long long
using namespace std;
long long MOD = 998244353;
long long pow2[(int)3e5 + 5];
int bfs(int start, vector<int> adj[], bool vis[], int parity[]){
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(start, -1), 0));
    vis[start] = true;
    int count[] = {0, 0};
    parity[start] = 0;
    while(!q.empty()){
        pair<pair<int, int>, int> t = q.front();
        q.pop();
        count[t.second]++;
        for(int j: adj[t.first.first]){
            if(!vis[j]){
                vis[j] = true;
                q.push(make_pair(make_pair(j, t.first.first), t.second^1));
                parity[j] = (t.second^1);
            }
            else if(parity[j]!=(t.second^1)) return 0;
        }
    }
    return (pow2[count[0]] + pow2[count[1]])%MOD;
}
int32_t main() {
    pow2[0] = 1;
    for(int i = 1;i<=3e5;i++) pow2[i] = (pow2[i-1]*2)%MOD;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        bool vis[n];
        int parity[n];
        vector<int> adj[n];
        for(int i = 0;i<m;i++){
            int u, v;
            cin>>u>>v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        for(int i =0 ;i<n;i++){
            vis[i] = false;
            parity[i] = 3;
        }
        int ans = 1;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                ans*=bfs(i, adj, vis, parity);
                ans%=MOD;
            }
        }
        cout<<ans<<endl;
    }
}