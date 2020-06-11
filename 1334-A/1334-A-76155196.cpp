//Can you see this?
//yes

#include <bits/stdc++.h>
#define int long long
#define INF 10000000000000000
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
#define mid(l, u) ((l+u)/2)
#define MOD 1000000007
using namespace std;
int32_t main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        pair<int, int> p[n];
        for(int i = 0;i<n;i++) cin>>p[i].first>>p[i].second;
        if(p[0].second>p[0].first){
            cout<<"NO"<<endl;
            continue;
        }
        string ans = "YES";
        for(int i = 1;i<n;i++){
            if(p[i].first<p[i].second || p[i].first<p[i-1].first || p[i].second<p[i-1].second || (p[i].first - p[i-1].first)<(p[i].second - p[i-1].second)) ans = "NO";
        }
        cout<<ans<<endl;
     }
    return 0;
}