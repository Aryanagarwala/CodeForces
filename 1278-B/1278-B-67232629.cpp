#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <fstream>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <map>
#define int long long
using namespace std;
vector<int> yo;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        long double a, b;
        cin>>a>>b;
        if(a<b) swap(a, b);
        int diff = (a-b);
        long double ind = ceil((-1.0 + sqrt(1.0 + 8.0*diff))/2.0);
        int ans = ind;
        while((((ans*(ans+1))/2)-diff)%2) ans++;
        cout<<ans<<endl;
    }
}