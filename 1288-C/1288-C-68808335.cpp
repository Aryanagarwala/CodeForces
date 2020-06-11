#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#define INF 10000000000000000
#define MOD 1000000007
#define int long long
using namespace std;
const int N = 2e5 + 5;
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>>n>>m;
    if(m==1){
        int ans = n*(n+1);
        ans/=2;
        ans%=MOD;
        cout<<ans<<endl;
        return 0;
    }
    int sum[n+1];
    int dp[m+1][n+1][n+1];
    for(int i = 1;i<=m;i++){
        for(int j = 1;j<=n;j++){
            sum[j] = 0;
            for(int k = 1;k<=n;k++) dp[i][j][k] = 0;
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = i;j<=n;j++) dp[1][i][j] = 1;
    }
    int ind = 1;
    sum[n] = dp[ind][1][n];
        for(int j = n-1;j>=1;j--){
            sum[j]+=dp[ind][1][j];
            sum[j]%=MOD;
            dp[ind][1][j] += dp[ind][1][j+1];
            dp[ind][1][j] %= MOD;
        }
        for(int i = 2;i<=n;i++){
            sum[n]+=dp[ind][i][n];
            sum[n]%=MOD;
            dp[ind][i][n] = sum[n];
            dp[ind][i][n]%=MOD;
            for(int j = n-1;j>=i;j--){
                sum[j]+=dp[ind][i][j];
                sum[j]%=MOD;
                dp[ind][i][j] = dp[ind][i][j+1] + sum[j];
                dp[ind][i][j]%=MOD;
            }
        }

    for(int i = 0;i<=n;i++) sum[i] - 0;
    for(ind = 2;ind<m;ind++){
        //cout<<ind<<endl;
        for(int i = 1;i<=n;i++){
            sum[i] = 0;
            for(int j = i;j<=n;j++) (dp[ind][i][j] = dp[ind-1][i][j]);
        }
        sum[n] = dp[ind][1][n];
        for(int j = n-1;j>=1;j--){
            sum[j]+=dp[ind][1][j];
            sum[j]%=MOD;
            dp[ind][1][j] += dp[ind][1][j+1];
            dp[ind][1][j] %= MOD;
        }
        for(int i = 2;i<=n;i++){
            sum[n]+=dp[ind][i][n];
            sum[n]%=MOD;
            dp[ind][i][n] = sum[n];
            dp[ind][i][n]%=MOD;
            for(int j = n-1;j>=i;j--){
                sum[j]+=dp[ind][i][j];
                sum[j]%=MOD;
                dp[ind][i][j] = dp[ind][i][j+1] + sum[j];
                dp[ind][i][j]%=MOD;
            }
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++){
        for(int j = i;j<=n;j++){
            ans+= (dp[m-1][i][j]);
            ans%=MOD;
        }
    }
    cout<<ans<<endl;
}
//dp[i][j] = dp[i][j+1] + dp[i-1][j] + dp[i][j]