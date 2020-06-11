#include <iostream>
#include <queue>
#include <algorithm>
#include <fstream>
#include <map>
#define eq 10000
#define int long long
#define MOD 1000000007
using namespace std;
int a, b, p;
string s;
int cost[(int)1e5 + 5];
int f(int i, char prev){
    if(i==(s.length()-1)) return prev=='B'?b:a;
    if(s[i]==prev) return cost[i] = f(i+1, prev);
    cost[i] = f(i+1, s[i]);
    return cost[i] + ((prev=='B')?b:a);
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        cin>>a>>b>>p>>s;
        f(0, s[0]);
        cost[s.length()-1] = 0;
        int ans = s.length()-1;
        for(int i = s.length()-2;i>=0;i--){
            if(p>=cost[i]) ans = i;
            //cout<<cost[i]<<" ";
        }
            //cout<<endl;
        cout<<(ans+1)<<endl;
    }
}