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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n], b[n];
        for(int i =0 ;i<n;i++) cin>>a[i];
        for(int i =0 ;i<n;i++) cin>>b[i];
        if(a[0]!=b[0]){
            cout<<"NO"<<endl;
            continue;
        }
        map<int, int> mp;
        for(int j = 0;j<n;j++){
            mp[a[j]]++;
        }
        bool poss = true;
        for(int i = n-1;i>0;i--){
            mp[a[i]]--;
            //cout<<a[i]<<" "<<b[i]<<" "<<mp[1]<<" "<<mp[-1]<<endl;
            if(a[i]>b[i] && mp[-1]==0) poss = false;
            if(a[i]<b[i] && mp[1]==0) poss = false;
        }
        if(poss) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}