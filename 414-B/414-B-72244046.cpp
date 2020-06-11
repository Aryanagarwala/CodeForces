#include <iostream>
using namespace std;
int MOD = 1e9 + 7;
int main() {
    int n, k;
    cin>>n>>k;
    long long dp[n+1][k+1];
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=k;j++){
            dp[i][j] = 0;
        }
    }
    for(int i = 1;i<=n;i++){
        dp[i][k] = 1;
    }
    for(int i = k-1;i>0;i--){
        for(int j = 1;j<=n;j++){
            int l = j;
            while(l<=n){
                dp[j][i] += dp[l][i+1];
                dp[j][i]%=MOD;
                l+=j;
            }
        }
    }
    long long pos = 0;
    for(int i = 1;i<=n;i++){
        pos+=dp[i][1];
        pos%=MOD;
    }
    cout<<pos<<endl;
    return 0;
}