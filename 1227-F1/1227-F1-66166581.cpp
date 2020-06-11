#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#define int long long
using namespace std;
int MOD = 998244353;
int32_t main(){
    int n, k;
    cin>>n>>k;
    int h[n];
    for(int i = 0;i<n;i++) cin>>h[i];
    int dp[n][2*n + 1];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<=(2*n);j++) dp[i][j] = 0;
    }
    if(h[n-1]==h[0]){
        dp[0][n] = k;
    }
    else{
        dp[0][n-1] = 1;
        dp[0][n+1] = 1;
        dp[0][n] = k-2;
    }
    for(int i = 1;i<n;i++){
        for(int j = 1;j<(2*n);j++){
            if(h[i]==h[i-1]){
                dp[i][j] = dp[i-1][j]*k;
                dp[i][j]%=MOD;
            }
            else{
                dp[i][j+1] += dp[i-1][j];
                dp[i][j-1] += dp[i-1][j];
                dp[i][j] += (k-2)*dp[i-1][j];
                dp[i][j+1]%=MOD;
                dp[i][j-1]%=MOD;
                dp[i][j]%=MOD;
            }
        }
    }
    /*for(int i = 0;i<n;i++){
        for(int j = 0;j<=(2*n);j++){
            cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;
        }
    }*/
    int answer = 0;
    for(int i = n+1;i<=(2*n);i++){
        answer+=dp[n-1][i];
        answer%=MOD;
    }
    cout<<answer<<endl;
}