#include <bits/stdc++.h>
#define int long long
#define MOD 998244353
using namespace std;
//find an unused prince such that his index is lower than the used one
//now, the prince actually used by that princess will go unused and a princess after her can use it.
//this ripple effect has to continue until we find someone that did not use a prince and can now use
//dp?
int pow10[1000000];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pow10[0] = 1;
    for(int i = 1;i<1000000;i++){
        pow10[i] = pow10[i-1]*10;
        pow10[i]%=MOD;
    }
    int n;
    cin>>n;
    int dp[n+1];
    dp[1] = 10;
    int sum = 10;
    for(int i = 2;i<=n;i++){
        dp[i] = (pow10[i]%MOD) - (pow10[i-1]%MOD) + ((9*sum)%MOD);
        dp[i]+=MOD;
        dp[i]%=MOD;
        sum+=dp[i];
        sum%=MOD;
    }
    for(int i = n;i>=1;i--) cout<<dp[i]<<" ";
    cout<<endl;
    return 0;
}