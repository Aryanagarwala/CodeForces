#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        if(__gcd(a, b)==1) cout<<"Finite"<<endl;
        else cout<<"Infinite"<<endl;
    }
}