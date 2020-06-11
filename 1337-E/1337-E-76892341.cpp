#include <bits/stdc++.h>
#define int long long
#define MOD 998244353
#define mid(l, u) ((l+u)/2)
#define test(a) tryCombination(a);
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
using namespace std;
string s, t;
int n, m;
const int N = 3005;
int dp[N][N];
int ans = 0;
int f(int i, int l, int r, int lmoves, int rmoves){
    if(i==n){
        return 1;
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    int tr = 0;
    if(l==0 && r>=(m-1)){
        tr = 1;
        //cout<<lmoves<<" "<<rmoves<<" "<<"WORKS"<<endl;
    }
    if(l>0){
        if(l<=m && t[l-1]!=s[i]) goto next;
        tr+=f(i+1, l-1, r, lmoves+1, rmoves);
        tr%=MOD;
    }
    next:
    if(r<(n-1)){
        if(r<(m-1)){
            if(t[r+1]!=s[i]) goto last;
        }
        tr+=f(i+1, l, r+1, lmoves, rmoves+1);
        tr%=MOD;
    }
    last:
    //cout<<i<<" "<<l<<" "<<r<<" "<<tr<<" "<<endl;
    return dp[l][r] = tr;
}
signed main(){
    cin>>s>>t;
    n = s.length();
    m = t.length();
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=n;j++){
            dp[i][j] = -1;
        }
    }
    for(int i = 0;i<n;i++){
        if(i<m && t[i]!=s[0]) continue;
        ans+=f(1, i, i, 0, 0);
        ans%=MOD;
    }
    ans*=2;
    ans%=MOD;
    cout<<ans<<endl;
}
//baab
//ba
//baa
//baab
//