#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
#define oset tree < pair<int, int> ,  null_type ,  less<pair<int, int>> ,  rb_tree_tag ,  tree_order_statistics_node_update >
using namespace std;
bool prime[200001];
vector<int> primes;
vector<int> pf[200001];
vector<int> pfinv[200001];
void sieve(){
    int maxi = 0;
    for(int i = 2;i<=200000;i++){
        if(!prime[i]) continue;
        primes.push_back(i);
        pf[i].push_back(i);
        for(int j = i+i;j<=200000;j+=i){
            prime[j] = false;
            pf[j].push_back(i);
            maxi = max(maxi, (int) pf[j].size());
        }
    }
}
int findpow(int a, int b){
    int tr = 0;
    while(a%b==0){
        tr++;
        a/=b;
    }
    return tr;
}
signed main(){
    for(int i = 1;i<=200000;i++) prime[i] = true;
    prime[1] = false;
    sieve();
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++) cin>>arr[i];
    for(int i = 0;i<n;i++){
        for(int j: pf[arr[i]]){
            pfinv[j].push_back(findpow(arr[i], j));
        }
    }
    int ans = 1;
    for(int i: primes){
        if(pfinv[i].size()<(n-1)) continue;
        sort(pfinv[i].begin(), pfinv[i].end());
        if(pfinv[i].size()<n){
            ans*=pow(i, pfinv[i][0]);
            //cout<<i<<" "<<pfinv[i][0]<<endl;
        }
        else{
            ans*=pow(i, pfinv[i][1]);
            //cout<<i<<" "<<(pfinv[i][1])<<endl;
        }
    }
    cout<<ans<<endl;
}