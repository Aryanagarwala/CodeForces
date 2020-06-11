#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mid(l, u) ((l+u)/2)
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
#define int long long
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
vector<int> adj[1005];
int par[1005];
int lca(int a, int b){
    cout<<"? "<<a<<" "<<b<<endl;
    int ans;
    cin>>ans;
    return ans;
}
int dfs(int i, int p, int root){
    par[i] = root;
    for(int j: adj[i]){
        if(j==p) continue;
        dfs(j, i, root);
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int curr = 1;
    bool vis[n+1];
    for(int i = 1;i<n;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1;i<=n;i++){
        vis[i] = false;
        par[i] = 0;
    }
    bool found = false;
    while(!found){
        vis[curr] = true;
        vector<int> un;
        bool difffound = false;
        for(int i: adj[curr]){
            if(par[i]!=curr) difffound = true;
            if(par[i]==0) un.push_back(i);
        }
        if(!difffound){
            cout<<"! "<<curr<<endl;
            return 0;
        }
        for(int j = 1;j<un.size();j+=2){
            int lol = lca(un[j], un[j-1]);
            if(lol==curr){
                par[un[j]] = curr;
                par[un[j-1]] = curr;
                continue;
            }
            for(int k = 0;k<un.size();k++) par[un[k]] = curr;
            if(lol==un[j]){
                par[curr] = un[j];
                par[un[j]] = 0;
            }
            else{
                par[curr] = un[j-1];
                par[un[j-1]] = 0;
            }
            dfs(curr, par[curr], par[curr]);
            curr = par[curr];
            goto end;
        }
        if(un.size()%2==1){
            if(vis[un[un.size()-1]]){
                int lmao = lca(un[un.size()-1], curr);
                cout<<"! "<<lmao<<endl;
                return 0;
            }
            curr = un[un.size()-1];
        }
        difffound = false;
        for(int i: adj[curr]){
            if(par[i]!=curr) difffound = true;
        }
        if(!difffound){
            cout<<"! "<<curr<<endl;
            return 0;
        }
        end:
        continue;
    }
}