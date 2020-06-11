#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#define int long long
#define double long double
#define mid(l, u) ((l+u)/2)
#define lchild(i) (i*2+  1)
#define rchild(i) (i*2 + 2)
#define INF 1000000000000000
using namespace std;
int n, root;
vector<int> adj[2001];
bool used[2001];
int req[2001];
int arr[2001];
int dfscount(int i, vector<int> &vals){
    vals.push_back(arr[i]);
    for(int j: adj[i]) dfscount(j, vals);
}
int rep(int i, int val, vector<int> &vals){
    if(arr[i]>=val) arr[i] = *upper_bound(vals.begin(), vals.end(), arr[i]);
    for(int j: adj[i]) rep(j, val, vals);
}
int dfs(int i){
    int amt = 0;
    for(int j: adj[i]) amt+=dfs(j);
    if(amt<req[i]){
        cout<<"NO"<<endl;
        exit(0);
    }
    int un = 2000;
    for(int j = 2000;j>=1;j--){
        if(!used[j]) un = j;
    }
    used[un] = true;
    arr[i] = un;
    vector<int> vals = {un};
    for(int j: adj[i]) dfscount(j, vals);
    sort(vals.begin(), vals.end());
    arr[i] = vals[req[i]];
    for(int j: adj[i]){
        rep(j, arr[i], vals);
    }
    return amt+1;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++) used[i] = false;
    for(int i = 1;i<=n;i++){
        int p;
        cin>>p>>req[i];
        if(p==0){
            arr[i] = req[i]+1;
            used[req[i]+1] = true;
            root = i;
            continue;
        }
        adj[p].push_back(i);
    }
    for(int j: adj[root]){
        dfs(j);
    }
    cout<<"YES"<<endl;
    for(int i = 1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
//2 1

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