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
vector<pair<int, int>> adj[(int)2e5 + 5];
int dp[(int)2e5 + 5][2];
int mini = 2e5 + 5;
void dfs(int i, int p){
    dp[i][0] = 0;//pointing away from us
    dp[i][1] = 0;//pointing towards us (BAD)
    for(pair<int, int> j: adj[i]){
        if(j.first==p) continue;
        dfs(j.first, i);
        dp[i][0]+=dp[j.first][0];
        dp[i][1]+=dp[j.first][1];
        dp[i][j.second]++;
    }
}
void compans(int i, int p, int overhead){
    //subtract overhead
    mini = min(mini, overhead);
    dp[i][1] = overhead;
    for(pair<int, int> j: adj[i]){
        if(j.first==p) continue;
        overhead = overhead + (j.second==1?-1:1);
        compans(j.first, i, overhead);
        overhead-=(j.second==1?-1:1);
    }
}
int32_t main(){
    int n;
    cin>>n;
    for(int i = 1;i<n;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(make_pair(v, 0));
        adj[v].push_back(make_pair(u, 1));
    }
    dfs(1, 0);
    compans(1, 0, dp[1][1]);
    cout<<mini<<endl;
    for(int i = 1;i<=n;i++){
        if(dp[i][1]==mini) cout<<i<<" ";
    }
    cout<<endl;
}