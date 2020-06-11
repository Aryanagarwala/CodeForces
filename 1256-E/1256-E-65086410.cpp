#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>
#include <set>
#include <iomanip>
#define INF 1e16
#define int long long
using namespace std;
int32_t main(){
    int n;
    cin>>n;
    pair<int, int> a[n];
    int team[n];
    for(int i = 0;i<n;i++){
        cin>>a[i].first;
        a[i].second = i;
    }
    sort(a, a+n);
    pair<int, int> dp[n+1];
    dp[n] = make_pair(0, 0);
    dp[n-1] = make_pair(INF, INF);
    dp[n-2] = make_pair(INF, INF);
    for(int i= n-3;i>=0;i--){
        dp[i] = make_pair(INF, INF);
        for(int j = i+2;j<=(n-1) && j<=(i+4);j++){
            dp[i] = min(dp[i], make_pair(a[j].first - a[i].first + dp[j+1].first, j));
        }
    }
    cout<<dp[0].first<<" ";
    int teams = 0;
    for(int i = 0;i<n;i++){
        team[a[i].second] = ++teams;
        int j = i+1;
        while(j<=dp[i].second){
            team[a[j].second] = teams;
            j++;
        }
        i = j-1;
    }
    cout<<teams<<endl;
    for(int i = 0;i<n;i++) cout<<team[i]<<" ";
    cout<<endl;
}
//1 1 2 3 4