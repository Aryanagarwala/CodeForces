#include <iostream>
#include <cmath>
#include <queue>
#include <unordered_map>
#define int long long
using namespace std;
int INF = 1e14;
int cmp(int a, int b){
    return a>b;
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int h, n;
        cin>>h>>n;
        int heights[n];
        unordered_map<int, bool> mp;
        for(int i = 0;i<n;i++){
            cin>>heights[i];
            mp[heights[i]] = true;
        }
        mp[0] = true;
        int dp[n][2];
        for(int i =0 ;i<n;i++) dp[i][0] = dp[i][1] = 0;//0-> landing on, 1-> skipping past
        if(!mp[heights[0]-1]) dp[0][1] = INF;
        for(int i = 1;i<n;i++){
            if(heights[i-1]==(heights[i]+1) && (i-1)!=0){
                dp[i][0] = min(dp[i-1][0]+1, dp[i-1][1]);
                dp[i][1] = dp[i-1][0];
            }
            else{
                dp[i][0] = dp[i-1][0] + 1;
                dp[i][1] = dp[i-1][0];
            }
            if(!mp[heights[i]-1]) dp[i][1] = INF;
        }
        long long ans = min(dp[n-1][0], dp[n-1][1]);
        cout<<ans<<endl;
    }
}