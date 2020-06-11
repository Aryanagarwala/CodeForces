#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
int main() {
    ll n, c;
    cin>>n>>c;
    ll a[n];
    ll b[n];
    a[0] = 0;
    b[0] = 0;
    ll dp[n][2];
    for(int i = 1;i<n;i++) cin>>a[i];
    for(int i = 1;i<n;i++) cin>>b[i];
    dp[0][0] = 0; //elevator
    dp[0][1] = 0; //stairs
    ll smallest = 0;
    ll smallest1 = 0;
    for(int i = 1;i<n;i++){
        dp[i][0] = smallest + b[i] + c;
        dp[i][1] = smallest1 + a[i];
        smallest = min(dp[i][1], smallest+b[i]);
        smallest1 = min(min(dp[i][0], dp[i][1]), smallest1+a[i]);
    }
    for(int i = 0;i<n;i++){
        cout<<min(dp[i][0], dp[i][1])<<" ";
    }
    cout<<endl;
}