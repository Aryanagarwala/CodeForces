#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n, x, a, b;
        cin>>n>>x>>a>>b;
        cout<<min(n-1, abs(a-b) + x)<<endl;
    }
}