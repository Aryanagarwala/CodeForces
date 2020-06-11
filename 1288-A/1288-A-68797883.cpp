#include <iostream>
#include <vector>
#include <cmath>
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
        int n, d;
        cin>>n>>d;
        vector<int> vec;
        for (int i = 1; i * i <= d; i++) {
            vec.push_back((d/i) - 1);
        }
        bool f = false;
        for (int i = 0;i<vec.size();i++) {
            if ((vec[i] + ceil(((double)d )/ (vec[i] + 1))) <= n) f = true;
        }

        if (f || d<=n) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}