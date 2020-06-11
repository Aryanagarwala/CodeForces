#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <fstream>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <map>
#define int long long
#define mid(l, u) ((l+u)/2)
#define rchild(i) (i*2 + 2)
#define lchild(i) (i*2 + 1)
#define INF -10000000000
using namespace std;
int ansmin, ansmax;
int k;
int dfs(int curr, int prev, vector<pair<int, int>> adj[]){
    int sz = 1;
    for(pair<int, int> j: adj[curr]){
        if(j.first==prev) continue;
        int csize = dfs(j.first, curr, adj);
        sz+=csize;
        int rem = (2*k) - csize;
        ansmax+=min(rem, csize)*j.second;
        ansmin+=(csize%2)*j.second;
    }
    return sz;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>k;
        vector<pair<int, int>> adj[2*k];
        for(int i = 1;i<(2*k);i++){
            int a, b, t;
            cin>>a>>b>>t;
            adj[a-1].push_back(make_pair(b-1, t));
            adj[b-1].push_back(make_pair(a-1, t));
        }
        ansmin = 0;
        ansmax = 0;
        dfs(0, -1, adj);
        cout<<ansmin<<" "<<ansmax<<endl;
    }
}
//3 10
//0 4 7
/*
 1 3
2 11
4 8
5 7
6 10
9 12
 */