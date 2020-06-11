#include <bits/stdc++.h>
#define int long long
#define INF 1000000000000
using namespace std;
signed main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, a, b;
        cin>>x>>y>>a>>b;
        int o1 = abs(x- y)*a + min(x, y)*b;
        int o2 = (x+y)*a;
        cout<<min(o1, o2)<<endl;
    }
}