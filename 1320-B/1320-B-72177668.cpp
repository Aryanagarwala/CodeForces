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
    vector<int> adj1[n+1];
    vector<int> adj[n+1];
    for(int i = 0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[v].push_back(u);
        adj1[u].push_back(v);
    }
    int k;
    cin>>k;
    int arr[k];
    for(int i = 0;i<k;i++) cin>>arr[i];
    int count[n+1];
    for(int i = 1;i<=n;i++) count[i] = 0;
    count[arr[k-1]] = 1;
    queue<pair<int, int>> q;
    int vis[n+1];
    for(int i = 1;i<=n;i++){
        vis[i] = -1;
    }
    vis[arr[k-1]] = 0;
    q.push(make_pair(arr[k-1], 0));
    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();
        for(int j: adj[curr.first]){
            if(vis[j]!=-1){
                if(vis[j]==(curr.second+1)) count[j]+=count[curr.first];
                continue;
            }
            q.push(make_pair(j, curr.second+1));
            vis[j] = curr.second+1;
            count[j]+=count[curr.first];
        }
    }
    for(int i = 1;i<=n;i++) count[i] = 0;
    for(int i = 1;i<=n;i++){
        for(int j: adj1[i]){
            if(vis[j] == (vis[i]-1)) count[i]++;
        }
    }
    int mincount = 0, maxcount = 0;
    for(int i = 1;i<k;i++){
        //cout<<arr[i-1]<<" "<<arr[i]<<" "<<count[arr[i-1]]<<endl;
        if(vis[arr[i]] != (vis[arr[i-1]]-1)){
            mincount++;
            maxcount++;
        }
        else if(count[arr[i-1]]>1){
            maxcount++;
        }
    }
    cout<<mincount<<" "<<maxcount<<endl;
 }