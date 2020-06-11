#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#define eq 10000
#define INF 10000000000000000
#define int long long
#define MOD 1000000007
#define mid(l, u) (l+u)/2
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
using namespace std;
int32_t main(){
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    map<char, bool> av;
    for(int i = 0;i<k;i++){
        char c;
        cin>>c;
        av[c] = true;
    }
    int dp[s.length()];
    dp[0] = av[s[0]];
    int ans = dp[0];
    for(int i = 1;i<s.length();i++){
        if(!av[s[i]]){
            dp[i] = 0;
            continue;
        }
        dp[i] = 1 + dp[i-1];
        ans+=dp[i];
    }
    cout<<ans<<endl;
    return 0;
}