#include <bits/stdc++.h>
using namespace std;
int main(){
    map<pair<int, int>, bool> seen;
    seen[{0, 0}] = true;
    pair<int, int> prev = {0, 0};
    int ans = 1;
    int n;
    cin>>n;
    while(n--){
        int a, b;
        cin>>a>>b;
        if(seen[{a, b}]) continue;
        seen[{a, b}] = true;
        if(min(a, b)<max(prev.first, prev.second)){
            prev = {a, b};
            continue;
        }
        if(prev.first!=prev.second) ans++;
        ans+= (min(a, b) - max(prev.first, prev.second));
        //cout<<a<<" "<<b<<endl;
        //cout<<(min(a, b) - max(prev.first, prev.second))<<endl;
        prev = {a, b};
    }
    cout<<ans<<endl;
}