#include <bits/stdc++.h>
#define int long long
#define INF 1000000000000
using namespace std;
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans = 2;
        for(int i = 1;i<(n/2);i++){
            ans+=(pow(2, i+1));
        }
        cout<<ans<<endl;
    }
}