#include <bits/stdc++.h>
#define int long long
#define mid(l, u) ((l+u)/2)
#define test(a) tryCombination(a);
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
using namespace std;
int n, k;
const int N = 2e5 + 5;
vector<int> adj[N];
bool tour[N];
vector<pair<int, int>> height;
int sum = 0;
int dfs1(int curr, int par, int anc){
    int sz = 1;
    for(int j: adj[curr]){
        if(j==par) continue;
        sz+=dfs1(j, curr, anc+1);
    }
    height.push_back(make_pair(  (sz-1) - anc, curr));
    return sz;
}
void dfs(int curr, int par, int tourpar){
    if(tour[curr]==false) sum+=tourpar;
    else tourpar++;
    for(int j: adj[curr]){
        if(j==par) continue;
        dfs(j, curr, tourpar);
    }
}
signed main(){
    cin>>n>>k;
    for(int i = 1;i<n;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1;i<=n;i++) tour[i] = true;
    dfs1(1, 0, 0);
    sort(height.begin(), height.end());
    for(int i = 0;i<k;i++){
        pair<int, int> t = height[i];
        tour[t.second] = false;
        //cout<<t.second<<endl;
    }
    dfs(1, 0, 0);
    cout<<sum<<endl;
}