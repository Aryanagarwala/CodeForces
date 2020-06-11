#include <iostream>
#include <vector>
#include <queue>
#define int long long
using namespace std;
signed main(){
    int n, m, t;
    cin>>n>>m>>t;
    char arr[n][m];
    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        for(int j = 0;j<m;j++){
            arr[i][j] = s[j];
        }
    }
    vector<pair<int, int>> adj[n+1][m+1];
    bool visited[n+1][m+1];
    int time[n+1][m+1];
    queue<pair<int, int>> q;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(i>0) adj[i][j].push_back({i-1, j});
            if(i<(n-1)) adj[i][j].push_back({i+1, j});
            if(j>0) adj[i][j].push_back({i, j-1});
            if(j<(m-1)) adj[i][j].push_back({i, j+1});
            bool found = false;
            for(pair<int, int> p: adj[i][j]){
                if(arr[p.first][p.second]==arr[i][j]){
                    found = true;
                }
            }
            if(found){
                visited[i][j] = true;
                time[i][j] = 0;
                q.push({i, j});
            }
            else{
                visited[i][j] = false;
                time[i][j] = -1;
            }
        }
    }
    while(!q.empty()){
        pair<int, int> p = q.front();
        int i = p.first;
        int j = p.second;
        q.pop();
        for(pair<int, int> nxt: adj[i][j]){
            if(visited[nxt.first][nxt.second]) continue;
            visited[nxt.first][nxt.second] = true;
            time[nxt.first][nxt.second] = time[i][j] + 1;
            q.push({nxt.first, nxt.second});
        }
    }
    while(t--){
        int i, j, p;
        cin>>i>>j>>p;
        i--; j--;
        if(time[i][j]==-1 || time[i][j]>p) cout<<arr[i][j]<<endl;
        else{
            int diff = ((p%2) - (time[i][j]%2) + 2)%2;
            if(diff==1){
                if(arr[i][j]=='0') cout<<'1'<<endl;
                else cout<<'0'<<endl;
            }
            else cout<<arr[i][j]<<endl;
        }
    }
}
//b k
//1 3
//