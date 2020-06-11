#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#define int long long
using namespace std;
int status[100005];
vector<int> adj[100005];
int n, m;
bool cycle = false;
int iter = 0;
void dfs(int i){
    if(status[i]==2) return;
    if(status[i]==1){
        cycle = true;
        return;
    }
    status[i] = 1;
    for(int j: adj[i]){
        dfs(j);
        if(cycle) return;
    }
    status[i] = 2;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int s;
    cin>>n>>m;
    bool special[n+1];
    for(int i = 1;i<=n;i++) special[i] = false;
    for(int i = 1;i<=n;i++) status[i] = 0;
    for(int i  = 1;i<=n;i++){
        int c;
        cin>>c;
        if(c==0) special[i] = true;
        while(c--){
            int v;
            cin>>v;
            adj[i].push_back(v);
        }
    }
    cin>>s;
    dfs(s);
    pair<int, int> vis[n+1][2];
    for(int i = 1;i<=n;i++){
        vis[i][0] = vis[i][1] = make_pair(-1, -1);
    }
    pair<int, int> found = {-1, -1};
    vis[s][0] = {1, 1};
    queue<pair<int, int>> q;
    q.push({s, 0});
    while(!q.empty() && found.first==-1){
        pair<int, int> c = q.front();
        q.pop();
        if(c.second==1 && special[c.first]){
            found = c;
            break;
        }
        //cout<<"Visited "<<c.first<<" "<<c.second<<endl;
        int nxt = c.second^1;
        for(int j: adj[c.first]){
            if(vis[j][nxt].first!=-1) continue;
            //cout<<"visting "<<j<<" from "<<c.first<<endl;
            vis[j][nxt] = c;
            //cout<<c.first<<" "<<c.second<<endl;
            q.push(make_pair(j, nxt));
        }
    }
    if(found.first==-1){
        if(cycle){
            cout<<"Draw\n";
            return 0;
        }
        cout<<"Lose\n";
        return 0;
    }
    cout<<"Win\n";
    stack<int> st;
    while(found!=make_pair(s, (int)0)){
        st.push(found.first);
        //cout<<found.first<<" "<<vis[found.first][found.second].first<<endl;
        found = make_pair(vis[found.first][found.second].first, vis[found.first][found.second].second);
    }
    st.push(s);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n";
}
//b k
//1 3
//