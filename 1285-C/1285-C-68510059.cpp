#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
int gcd(int a, int b){
    if(a==0) return b;
    return gcd(b%a, a);
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int x;
    cin>>x;
    pair<int, int> ans = make_pair(1, x);
    int cmin = x;
    for(int i = 1;(i*i)<=x;i++){
        if(x%i!=0) continue;
        if(gcd(i, x/i)==1){
            if(max(i, x/i)<cmin){
                ans = make_pair(i, x/i);
            }
        }
    }
    cout<<ans.first<<" "<<ans.second<<endl;
}