#include <bits/stdc++.h>
#define int long long
using namespace std;
int pow2[61];
int search(int x){
    if(x<=0) return 0;
    int l = 1;
    int u = 60;
    int ans = 60;
    while(l<=u){
        int m = (l+u)/2;
        int k = pow2[m]-1;
        if(k>=x){
            ans = min(ans, m);
            u = m-1;
        }
        else l = m+1;
    }
    return ans;
}
int32_t main() {
    pow2[0] = 1;
    for(int i = 1;i<=60;i++) pow2[i] = pow2[i-1]*2;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i<n;i++) cin>>a[i];
        int maxdiff = 0;
        int maxi = -1e9 - 5;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(maxi>a[i]){
                maxdiff = max(maxdiff, maxi - a[i]);
            }
            maxi = max(maxi, a[i]);
        }
        cout<<search(maxdiff)<<endl;
    }
    return 0;
}
//-2 4 5 5 6 8
//8 -2 6 4 5 5
//5 5 4 6 -2 8