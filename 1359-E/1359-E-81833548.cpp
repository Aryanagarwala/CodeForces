#include <bits/stdc++.h>
#define int long long
#define INF 1000000000000000000
#define mid(l, u) ((l+u)/2)
#define rchild(i) (i*2 + 2)
#define lchild(i) (i*2 + 1)
using namespace std;
const int N = 500005;
const int MOD = 998244353;
bool notprime[N];
int sum[N];
int fact[N];
int invfact[N];
int prod[N];
int sieve(){
    for(int i = 2;i<N;i++){
        if(notprime[i]) continue;
        for(int j = i+i;j<N;j+=i) notprime[j] = true;
    }
    for(int i = 2;i<N;i++) sum[i] = sum[i-1] + (!notprime[i]);
    for(int i = N-1;i>=1;i--){
    }
}
int modpow(int x, int p){
    if(p==0) return 1;
    if(p==1) return x%MOD;
    int temp = modpow(x, p/2);
    temp*=temp;
    temp%=MOD;
    if(p%2==1) temp*=x;
    temp%=MOD;
    return temp;
}
int nCr(int n, int r){
    //cout<<n<<" "<<fact[n]<<" "<<r<<" "<<invfact[r]<<" "<<(n-r)<<" "<<invfact[n-r]<<endl;
    return ((((fact[n])*(invfact[r]))%MOD)*invfact[n-r])%MOD;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    fact[0] = 1;
    for(int i = 1;i<N;i++){
        fact[i] = fact[i-1]*i;
        fact[i]%=MOD;
        invfact[i] = modpow(fact[i], MOD-2);
        invfact[i]%=MOD;
    }
    invfact[0] = 1;
    int n, k;
    cin>>n>>k;
    int ans = 0;
    for(int i = 1;i<=n;i++){
        int prod = (n/i) - 1;
        //cout<<i<<" "<<prod<<endl;
        if(prod<(k-1)) continue;
        ans+=nCr(prod, k-1);
        ans%=MOD;
    }
    cout<<ans<<endl;
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