#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
int mini = 1, root;
int deg[N];
pair<int, int> dfs(int i, int par){
    int child = 0;
    pair<int, int> curr;
    for(int j: adj[i]){
        if(j==par) continue;
        pair<int, int> lol = dfs(j, i);
        curr.first = curr.first||lol.first;
        curr.second = curr.second||lol.second;
        child++;
    }
    if(child==0){
        //leaf
        return make_pair(0, 1);
    }
    if(curr.first && curr.second) mini = 3;
    int temp = curr.first;
    curr.first = curr.second;
    curr.second = temp;
    return curr;
}
int dfs1(int i, int par){
    int child = 0;
    int leaf = 0;
    int tr = 0;
    for(int j: adj[i]){
        if(j==par) continue;
        child++;
        int lel = dfs1(j, i);
        if(lel==0) leaf++;
        tr+=lel;
    }
    if(child==0) return 0;
    tr+=child;
    if(leaf){
        tr-=(leaf-1);
    }
    return tr;
}
int32_t main() {
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++) deg[i] = 0;
    for(int i = 1;i<n;i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
        if(deg[a]>1) root = a;
        if(deg[b]>1) root = b;
     }
    dfs(root, -1);
    cout<<mini<<" "<<dfs1(root, -1)<<endl;
    return 0;
}