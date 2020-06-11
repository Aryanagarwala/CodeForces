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
int32_t main(){
    int n, m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int count = 1;
    bool vis[n+1];
    for(int i = 0;i<=n;i++) vis[i] = false;
    vis[1] = true;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int j: adj[curr]){
            if(vis[j]) continue;
            count++;
            q.push(j);
            vis[j] = true;
        }
    }
    if(count==n && m==n) cout<<"FHTAGN!"<<endl;
    else cout<<"NO"<<endl;
}