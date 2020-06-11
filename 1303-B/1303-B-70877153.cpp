#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#define int long long
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n, g, b;
        cin>>n>>g>>b;
        int req = n/2 + (n%2);
        int ans = 1000000000000000000;
        int l = n;
        int u = 1000000000000000000;
        while(u>=l){
            int m = (l+u)/2;
            int gdays = (m/(g+b))*g + min(g, (m%(g+b)));
            if(gdays>=req){
                ans = min(ans, m);
                u = m - 1;
            }
            else l = m+1;
        }
        cout<<ans<<endl;
    }
}