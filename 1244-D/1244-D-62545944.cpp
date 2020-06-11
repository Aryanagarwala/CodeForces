#include <iostream>
#include <vector>
using namespace std;
long long c[100005][3];
long long dp[3][3];
vector<long long> adj[100005];
int group[100005];
int answer[100005];
int remaining(int a, int b){
    bool vis[4]; for(int i = 0;i<4;i++) vis[i] = false;
    vis[a] = vis[b] = true;
    for(int i = 0;i<4;i++){
        if(!vis[i]) return i;
    }
}
int remaining(int a, int b, int c){
    bool vis[4]; for(int i = 0;i<4;i++) vis[i] = false;
    vis[a] = vis[b] = vis[c] = true;
    for(int i = 0;i<4;i++){
        if(!vis[i]) return i;
    }
}
bool IsPossible(int i, int p, int c){
    int child1, child2 = -1;
    bool ans = true;
    for(int j: adj[i]){
        if(j!=p){
            c++;
            ans = ans&&IsPossible(j, i, 1);
        }
    }
    if(c>2) return false;
    else return ans;
}
long long dfs(int i, int p, int pgroup, int cgroup){
    group[i] = cgroup;
    for(int k = 0;k<3;k++) dp[cgroup][k]+=c[i][k];
    int child1group = remaining(pgroup, cgroup);
    int child2group = remaining(pgroup, cgroup, child1group);
    bool child1 = false;
    for(int j: adj[i]){
        if(j!=p){
            dfs(j, i, cgroup, child1==true?child2group:child1group);
            child1 = true;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            dp[i][j] = 0;
        }
    }
    int n;
    cin>>n;
    for(int i = 0;i<3;i++){
        for(int j = 0;j<n;j++) cin>>c[j][i];
    }
    for(int i = 1;i<n;i++){
        int u, v;
        cin>>u>>v;
        adj[v-1].push_back(u-1);
        adj[u-1].push_back(v-1);
    }
    if(!IsPossible(0, -1, 0)){
        cout<<-1<<endl;
        return 0;
    }
    else{
        long long minimum = 1e16;
        dfs(0, -1, 3, 0);
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                if(j!=i) {
                    for (int k = 0; k < 3; k++) {
                        if (k != i && k!=j) {
                            if (dp[0][i] + dp[1][j] + dp[2][k] <= minimum) {
                                for (int l = 0; l < n; l++) {
                                    if (group[l] == 0) answer[l] = i + 1;
                                    if (group[l] == 1) answer[l] = j + 1;
                                    if (group[l] == 2) answer[l] = k + 1;
                                }
                                minimum = dp[0][i] + dp[1][j] + dp[2][k];
                            }
                        }
                    }
                }
            }
        }
        cout<<minimum<<endl;
        for(int i =0 ;i<n;i++) cout<<answer[i]<<" ";
        cout<<endl;
    }
    return 0;
}