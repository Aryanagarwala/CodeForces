#include <bits/stdc++.h>
#define int long long
#define INF 1000000000000000000
#define mid(l, u) ((l+u)/2)
#define rchild(i) (i*2 + 2)
#define lchild(i) (i*2 + 1)
using namespace std;
int a[100005];
int dp[100005][65][2];
bool vis[100005][65][2];
int n;
int f(int i, int maxnum, bool cont){
    //cout<<"FCALL "<<i<<" "<<maxnum<<" "<<cont<<endl;
    if(i==0 && cont) return -INF;
    if(i==0) return 0;
    if(a[i]>maxnum) return (cont)?(-INF):(0);
    //cout<<"didn't return cause >\n";
    if(vis[i][maxnum+30][cont]) return dp[i][maxnum+30][cont];
    //cout<<"didn't memoise\n";
    vis[i][maxnum+30][cont] = true;
    if(a[i]!=maxnum){
        if(cont) return dp[i][maxnum+30][cont] = a[i] + f(i-1, maxnum, cont);
        else return dp[i][maxnum+30][cont] = max((int)0, a[i] + f(i-1, maxnum, cont));
    }
    else{
        if(cont) return dp[i][maxnum+30][cont] =  f(i-1, maxnum, false);
        return dp[i][maxnum+30][cont] =  a[i] + f(i-1, maxnum, false);
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>a[i];
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=60;j++){
            for(int k = 0;k<=1;k++){
                dp[i][j][k] = 0;
                vis[i][j][k] = false;
            }
        }
    }
    int maxi = 0;
    for(int i =1;i<=n;i++){
        for(int j = -30;j<=30;j++){
            maxi = max(maxi, f(i, j, true));
            //cout<<i<<" "<<j<<" "<<(f(i, j, true))<<endl;
        }
    }
    cout<<maxi<<endl;
    return 0;
}
/*
 3 2
 1 2 3
 2
1
 */
/*
6 5
3 5 1 6 4 2
3
5
1
2
4
 */

/*
10 9
3 7 1 9 4 10 8 2 6 5
9
8
7
6
5
4
3
2
1
 */