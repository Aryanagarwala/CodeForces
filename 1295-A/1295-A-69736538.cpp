#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <fstream>
#include <algorithm>
#include <set>
#define INF 10000000000000000
#define MOD 1000000007
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int count = n/2;
        if(n%2==0){
            cout<<1;
        }
        else cout<<7;
        for(int i = 1;i<count;i++) cout<<1;
        cout<<endl;
    }
}
//1 1 2 3 2 1