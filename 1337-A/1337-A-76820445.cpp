#include <bits/stdc++.h>
#define int long long
#define mid(l, u) ((l+u)/2)
#define test(a) tryCombination(a);
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
using namespace std;
signed main(){
    int t;
    cin>>t;
    while(t--){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        cout<<b<<" "<<c<<" "<<c<<endl;
        /*int x, n, m;
        cin>>x>>n>>m;
        int dp[n+1][m+1];
        dp[0][0] = x;
        for(int i = 0;i<=n;i++){
            for(int j = 0;j<=m;j++){
                if(i==0 && j==0) continue;
                dp[i][j] = 1e16;
                if(i>0){
                    dp[i][j] = min(dp[i][j], dp[i-1][j]);
                }
            }
        }*/
    }
}