#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mid(l, u) ((l+u)/2)
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
#define int long long
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    pair<int, int> arr[n+5][n+5];
    char ans[n+5][n+5];
    vector<pair<int, int>> x;
    bool vis[n+5][n+5];
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            vis[i][j] = false;
        }
    }
    for(int i = 1;i<=n;i++){
        arr[i][0] = make_pair(-5, -5);
        vis[i][0] = true;
        arr[i][n+1] = make_pair(-5, -5);
        vis[i][n+1] = true;
        arr[0][i] = make_pair(-5, -5);
        vis[0][i] = true;
        arr[0][n+1] = make_pair(-5, -5);
        vis[0][n+1] = true;
        for(int j = 1;j<=n;j++){
            cin>>arr[i][j].first>>arr[i][j].second;
            if(make_pair(i, j) == arr[i][j]){
                x.push_back(make_pair(i, j));
                ans[i][j] = 'X';
            }
        }
    }

    for(pair<int, int> src: x){
        queue<pair<int, int>> q;
        q.push(src);
        vis[src.first][src.second] = true;
        while(!q.empty()){
            pair<int, int> curr = q.front();
            int x = curr.first;
            int y = curr.second;
            q.pop();
            if(!vis[x+1][y] && arr[x+1][y]==src){
                vis[x+1][y] = true;
                q.push(make_pair(x+1, y));
                ans[x+1][y] = 'U';
            }
            if(!vis[x][y+1] && arr[x][y+1]==src){
                vis[x][y+1] = true;
                q.push(make_pair(x, y+1));
                ans[x][y+1] = 'L';
            }
            if(!vis[x-1][y] && arr[x-1][y]==src){
                vis[x-1][y] = true;
                q.push(make_pair(x-1, y));
                ans[x-1][y] = 'D';
            }
            if(!vis[x][y-1] && arr[x][y-1]==src){
                vis[x][y-1] = true;
                q.push(make_pair(x, y-1));
                ans[x][y-1] = 'R';
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(vis[i][j]) continue;
            if(arr[i][j]!=make_pair((int)-1,(int) -1)){
                cout<<"INVALID"<<endl;
                return 0;
            }
            bool found = false;
            int x = i;
            int y = j;
            if(!vis[x+1][y]){
                ans[i][j] = 'D';
                found = true;
            }
            if(!vis[x][y+1]){
                ans[i][j] = 'R';
                found = true;
            }
            if(!vis[x-1][y]){
                ans[i][j] = 'U';
                found = true;
            }
            if(!vis[x][y-1]){
                ans[i][j] = 'L';
                found = true;
            }
            if(!found){
                cout<<"INVALID"<<endl;
                return 0;
            }
        }
    }
    cout<<"VALID"<<endl;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++) cout<<ans[i][j];
        cout<<endl;
    }
}