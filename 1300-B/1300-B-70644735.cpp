#include <iostream>
#include <queue>
#include <algorithm>
#define int long long
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[2*n];
        for(int i = 0;i<(2*n);i++) cin>>a[i];
        sort(a, a+(2*n));
        int ans = 2e9;
        for(int i = n;i<(2*n);i++){
            int cdiff =  i - n + 1;
            cdiff = abs(a[i] - a[i - cdiff]);
            if(cdiff<ans){
                ans = cdiff;
            }
        }
        cout<<ans<<endl;
    }
}