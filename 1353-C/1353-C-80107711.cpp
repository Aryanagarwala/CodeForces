#include <iostream>
#include <vector>
#include <queue>
#define int long long
using namespace std;
signed main(){
    int dp[500006];
    dp[1] = 0;
    int dist = 1;
    for(int i = 3;i<=500005;i+=2){
        dp[i] = dp[i-2] + ((i-1)*4)*(dist++);
    }
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<dp[n]<<endl;
    }
}
//b k
//1 3
//