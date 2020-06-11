#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define INF 10000000000000000
#define int long long
using namespace std;
const int N = 2e5 + 5;
int32_t main() {
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        int cnum = 9;
        int ans = 0;
        while(cnum<=b){
            ans+=a;
            cnum*=10;
            cnum+=9;
        }
        cout<<ans<<endl;
    }
}