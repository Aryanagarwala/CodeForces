#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
signed main() {
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int done = k*k;
        if(n<done){
            cout<<"NO"<<endl;
            continue;
        }
        int rem = n-k;
        if(rem%2==1){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
    }
    return 0;
}