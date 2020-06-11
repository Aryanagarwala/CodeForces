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
vector<int> adj[(int)1e5 + 5];
int cval[(int)1e5 + 5];
int fval[(int)1e5 + 5];
vector<int> ans;
int cnt = 0;
void dfs(int i, int p, vector<int> f, int d){
    if((cval[i]^(f[d%2]%2))!=fval[i]){
        f[d%2]++;
        cnt++;
        ans.push_back(i);
    }
    for(int j: adj[i]){
        if(j==p) continue;
        dfs(j, i, f, d+1);
    }
}
int32_t main(){
    int n;
    cin>>n;
    for(int i = 1;i<n;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1;i<=n;i++){
        cin>>cval[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>fval[i];
    }
    dfs(1, 0, {0, 0}, 0);
    cout<<cnt<<endl;
    for(int j: ans){
        cout<<j<<endl;
    }
}