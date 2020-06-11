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

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i<n;i++) cin>>a[i];
    int pref[n+1];
    pref[0] = 0;
    for(int i = 1;i<=n;i++){
        pref[i] = pref[i-1] + a[i-1];
    }
    map<int, int> mp, mp1;
    int ans = 0;
    int l = 1;
    int u = 1;
    mp[0]++;
    mp[pref[1]]++;
    while(u<=n){
        //cout<<l<<" "<<u<<" "<<mp[pref[u]]<<endl;
        if(mp[pref[u]]>1){
            mp[pref[l-1]]--;
            //cout<<"reducing "<<pref[l-1]<<" to "<<mp[pref[l-1]]<<endl;
            if(l==u){
                u++;
                if(u<=n) mp[pref[u]]++;
            }
            l++;
            continue;
        }
        //cout<<l<<" "<<u<<endl;
        ans+=(u-l+1);
        u++;
        if(u<=n) mp[pref[u]]++;
    }
    cout<<ans<<endl;
    return 0;
}