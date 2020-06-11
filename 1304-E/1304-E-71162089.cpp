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
using namespace std;
#define sz 100010

vector<int> adj[sz];    // stores the tree
vector<int> et;
int depth[sz];
int first[sz];
int smol(int u, int v){
    if(u==-5) return v;
    if(v==-5) return u;
    return depth[u]<depth[v]?u:v;
}
void buildtree(int l, int u, int i, int seg[]){
    if(l==u){
        seg[i] = et[l];
        return;
    }
    buildtree(l, mid(l, u), lchild(i), seg);
    buildtree(mid(l, u)+1, u, rchild(i), seg);
    seg[i] = smol(seg[lchild(i)], seg[rchild(i)]);
}
int query(int l, int u, int i, int ll, int uu, int seg[]){
    if(l>=ll && u<=uu){
        return seg[i];
    }
    if(l>uu || u<ll) return -5;
    return smol(query(l, mid(l, u), lchild(i), ll, uu, seg), query(mid(l, u)+1, u, rchild(i), ll, uu, seg));
}
void dfs(int i, int p, int dep){
    first[i] = et.size();
    depth[i] = dep;
    et.push_back(i);
    for(int j: adj[i]){
        if(j==p) continue;
        dfs(j, i, dep+1);
        et.push_back(i);
    }
}
int LCA(int a, int b, int seg[]){
    if(a==b) return a;
    if(first[a]>first[b]) swap(a, b);
    return query(0, et.size()-1, 0, first[a], first[b], seg);
}
int dist(int a, int b, int seg[]){
    if(a==b) return 0;
    int lca = LCA(a, b, seg);
    int ans = depth[a] - depth[lca] + depth[b] - depth[lca];
    return ans;
}
int32_t main(){
    // constructing the described tree
    int n;
    cin>>n;
    for(int i = 1;i<n;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 1);
    int seg[4*(et.size())];
    buildtree(0, et.size()-1, 0, seg);
    int q;
    cin>>q;
    while(q--){
        int x, y, a, b, k;
        cin>>x>>y>>a>>b>>k;
        int path1 = dist(a, b, seg);
        int path2 = dist(a, x, seg) + 1 + dist(b, y, seg);
        int path3 = dist(a, y, seg) + 1 + dist(b, x, seg);
        if(path1<=k && path1%2==k%2){
            cout<<"YES"<<endl;
            continue;
        }
        if(path2<=k && path2%2==k%2){
            cout<<"YES"<<endl;
            continue;
        }
        if(path3<=k && path3%2==k%2){
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }

    return 0;
}