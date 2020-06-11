#include <iostream>
#include <queue>
#include <algorithm>
#include <fstream>
#include <map>
#define eq 10000
#define int long long
#define MOD 1000000007
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int a, b, x, y;
        cin>>a>>b>>x>>y;
        int area = a*y;
        area = max(area, a*(b-y-1));
        area = max(area, b*(x));
        area = max(area, b*(a-1-x));
        cout<<area<<endl;
    }

}