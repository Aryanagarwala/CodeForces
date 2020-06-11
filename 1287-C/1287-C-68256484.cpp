#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#define int long long
#define double long double
#define mid(l, u) ((l+u)/2)
#define lchild(i) (i*2+  1)
#define rchild(i) (i*2 + 2)
#define INF 1000000000000000
using namespace std;
int dp[105][3][105][105];
int arr[100];
int n;
int f(int i, int prev, int e, int o){
    if(i==n) return 0;
    if(dp[i][prev][e][o]!=-1) return dp[i][prev][e][o];
    int ans = INF;
    if(arr[i]!=0) return dp[i][prev][e][o] = f(i+1, arr[i]%2, e, o) + (prev!=(arr[i]%2)) - (prev==2);
    if(e){
        ans = min(ans, f(i+1, 0, e-1, o) + ((prev==1)?1:0));
    }
    if(o){
        ans = min(ans, f(i+1, 1, e, o-1) + ((prev==0)?1:0));
    }
    //cout<<i<<" "<<prev<<" "<<e<<" "<<o<<" "<<ans<<endl;
    return dp[i][prev][e][o] = ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    bool used[n+1];
    for(int i = 1;i<=n;i++) used[i] = false;
    for(int i =0 ;i<n;i++){
        cin>>arr[i];
        used[arr[i]] = true;
    }
    int u[] = {0, 0};
    for(int i = 1;i<=n;i++) if(used[i]==false) u[i%2]++;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<3;j++){
            for(int k = 0;k<=u[0];k++){
                for(int h = 0;h<=u[1];h++){
                    dp[i][j][k][h] = -1;
                }
            }
        }
    }
    cout<<f(0, 2, u[0], u[1])<<endl;
}
//2 1

//3 10
//0 4 7
/*
 1 3
2 11
4 8
5 7
6 10
9 12
 */