#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define int long long
#define lchild(i) (i*2 + 1)
#define INF 1000000000000000000
#define rchild(i) (i*2 + 2)
#define mid(l, u) ((l+u)/2)
using namespace std;
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int e[n];
        for(int i = 0;i<n;i++) cin>>e[i];
        sort(e, e+n);
        int dp[n+1];
        for(int i = 0;i<=n;i++){
            dp[i] = -INF;
        }
        dp[0] = 0;
        for(int i = 1;i<=n;i++){
            int cost = e[i-1];
            if((i-cost)<0){
                dp[i] = dp[i-1];
                continue;
            }
            dp[i] = max(dp[i-1], dp[i-cost] + 1);
            //cout<<dp[i]<<" ";
        }
        //cout<<endl;
        cout<<dp[n]<<endl;
    }
}
//b k
//1 3
//