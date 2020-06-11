#include <iostream>
#include <vector>
#include <queue>
#define int long long
#define lchild(i) (i*2 + 1)
#define INF 10000000000000000
#define rchild(i) (i*2 + 2)
#define mid(l, u) ((l+u)/2)
using namespace std;
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        int pref[n+1];
        pref[0] = 0;
        for(int i = 1;i<=n;i++){
            pref[i] = (s[i-1] - '0');
            pref[i]+=pref[i-1];
            //cout<<i<<" "<<pref[i]<<endl;
        }
        int dp[n];
        for(int i = 1;i<=n;i++){
            dp[i] = INF;
            dp[i] = pref[i-1];
            if((i-k)>=1){
                int cost = dp[i-k] + pref[i-1] - pref[i-k];
                dp[i] = min(dp[i], cost);
            }
            if(s[i-1]=='0') dp[i]++;
            //cout<<i<<" "<<dp[i]<<endl;
        }
        int ans = pref[n];
        for(int i = 1;i<=n;i++){
            ans = min(ans, dp[i] + pref[n] - pref[i]);
            //cout<<"cost of ending at "<<i<<" = "<<dp[i] + pref[n] - pref[i]<<endl;
        }
        cout<<ans<<endl;
    }
}
//b k
//1 3
//