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
int dp[300];
int pow2[10];
int n, m;
void f(int lol, int id){
    //cout<<lol<<" "<<id<<endl;
    if(dp[lol]!=0) return;
    dp[lol] = id;
    for(int i = 0;i<10;i++){
        if(lol&pow2[i]){
            int l = lol^pow2[i];
            f(l, id);
        }
    }
}
int32_t main() {
    pow2[0] = 1;
    for(int i = 1;i<10;i++) pow2[i] = 2*pow2[i-1];
    cin>>n>>m;
    int arr[n][m];
    for(int i =0 ;i<n;i++){
        for(int j = 0;j<m;j++) cin>>arr[i][j];
    }
    int l = 0;
    int u = 1e9;
    int maxi = -1;
    pair<int, int> ans;
    while(u>=l){
        int mid = (l+u)/2;
        int mask[n];
        for(int i = 0;i<300;i++) dp[i] = 0;
        for(int i = 0;i<n;i++){
            mask[i] = 0;
            for(int j = 0;j<m;j++){
                if(arr[i][j]>=mid) mask[i]+=pow2[j];
            }
            f(mask[i], i+1);
        }
        pair<int, int> tans;
        bool found = false;
        //cout<<mid<<endl;
        for(int i = 0;i<n;i++){
            int lookfor = mask[i]^(pow2[m]-1);
            //cout<<i<<" "<<mask[i]<<" "<<lookfor<<" "<<dp[lookfor]<<endl;
            if(dp[lookfor]>0){
                found = true;
                tans = make_pair(i+1, dp[lookfor]);
            }
        }
        if(found){
            if(mid>maxi){
                ans = tans;
                maxi = mid;
            }
            l = mid+1;
        }
        else u = mid-1;
    }
    cout<<ans.first<<" "<<ans.second<<endl;
}
//dp[i][j] = dp[i][j+1] + dp[i-1][j] + dp[i][j]