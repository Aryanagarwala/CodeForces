#include <bits/stdc++.h>
//#define int long long
#define INF 1000000000000000000
#define mid(l, u) ((l+u)/2)
#define rchild(i) (i*2 + 2)
#define lchild(i) (i*2 + 1)
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, m, a, b;
        cin>>n>>m>>a>>b;
        if((n*a)!=(m*b)){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        int mat[n][m];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++) mat[i][j] = 0;
        }
        for(int i =0 ;i<m;i++){
            pq.push({0, i});
        }
        for(int i = 0;i<n;i++){
            vector<pair<int, int>> rs;
            for(int j = 0;j<a;j++){
                rs.push_back(pq.top());
                pq.pop();
            }
            for(pair<int, int> j: rs){
                mat[i][j.second] = 1;
                pq.push({j.first + 1, j.second});
            }
        }
        for(int i =0 ;i<n;i++){
            for(int j = 0;j<m;j++){
                cout<<mat[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
/*
6 8
0 10 5 3 2 8
1 3 1
3 2 5
3 4 1
4 6 2
1 5 1
 */

//The number of unique distances for a tree with k vertices is k^2 max
//DP[i][D] ?
//First truncate all paths so that ecah path has length <= D