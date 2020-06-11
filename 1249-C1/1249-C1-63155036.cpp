#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#define MOD (1000000007)
using namespace std;
set<long long> s;
long long pow3[10];
void f(int i, long long num){
    if(i==10){
        s.insert(num);
        return;
    }
    f(i+1, num + pow3[i]);
    f(i+1, num);
}
int main() {
    int limit = 10;
    pow3[0] = 1;
    for(int i = 1;i<limit;i++) pow3[i] = pow3[i-1]*3;
    f(0, 0);
    int q;
    cin>>q;
    while(q--){
        long long n;
        cin>>n;
        auto it = s.lower_bound(n);
        cout<<(*it)<<endl;
    }
}