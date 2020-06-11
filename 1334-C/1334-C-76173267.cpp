#include <bits/stdc++.h>
#define int long long
#define INF 10000000000000000
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
#define mid(l, u) ((l+u)/2)
#define MOD 1000000007
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n], b[n];
        for(int i =0 ;i<n;i++) cin>>a[i]>>b[i];
        int DP[n];
        DP[0] = 0;
        int prevdamage = 0;
        for(int i = 0;i<n;i++){
            DP[0]+=max((int)0, a[i] - prevdamage);
            prevdamage = b[i];
        }
        for(int i = n-1;i>0;i--) {
            int prev = (i - 1 + n) % n;
            int next = (i + 1) % n;
            DP[i] = DP[next] - max((int) 0, a[i] - b[prev]) + a[i] - a[next] + max((int) 0, a[next] - b[i]);
            //cout<<i<<" "<<DP[next]<<" "<<max((int) 0, a[i] - b[prev])<<" "<<a[i]<<" "<<a[next]<<" "<<max((int) 0, a[next] - b[i])<<endl;
        }
        int ans = DP[0];
        for(int i = 1;i<n;i++){
            ans = min(DP[i], ans);
        }
        cout<<ans<<"\n";
    }
    return 0;
}