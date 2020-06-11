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
const int N = 2*1e5 + 10;
int a[N];
int dp[N];
int n, p, k;
int f(int i){
    if(i<0) return 0;
    if(dp[i]>-1) return dp[i];
    else{
        if(i>=(k-1)) return dp[i] = a[i] + f(i-k);
        else return dp[i] = a[i] + f(i-1);
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>p>>k;
        for(int i =0 ;i<n;i++) cin>>a[i];
        sort(a, a+n);
        for(int i =0 ;i<n;i++) dp[i] = -1;
        int ans = 0;
        for(int i = 0;i<n;i++){
            int cost = f(i);
            if(cost<=p) ans = (i+1);
        }
        cout<<ans<<endl;
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