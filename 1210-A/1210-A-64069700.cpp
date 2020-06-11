#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int n, m;
vector<int> adj[10];
int solve(int arrangement[]){
    map<pair<int, int>, bool> used;
    int count = 0;
    for(int i = 0;i<n;i++){
        if(arrangement[i]==6) continue;
        for(int j: adj[i]){
            if(arrangement[j]==6) continue;
            if(used[make_pair(arrangement[i], arrangement[j])]) continue;
            count++;
            used[make_pair(arrangement[i], arrangement[j])] = true;
            used[make_pair(arrangement[j], arrangement[i])] = true;
        }
    }
    return count;
}
int arrange(int i, int arrangement[]){
    if(i==n) return solve(arrangement);
    int ans = 0;
    for(int j = 0;j<7;j++){
        arrangement[i] = j;
        ans = max(ans, arrange(i+1, arrangement));
    }
    return ans;
}
int32_t main() {
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a, b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    int arrangement[n];
    int ans = arrange(0, arrangement);
    cout<<ans<<endl;
}