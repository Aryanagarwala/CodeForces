#include <bits/stdc++.h>
#define INF 10000000000000000
#define MOD 1000000017
#define mid(l, u) ((l+u)/2)
#define rchild(i) (i*2 + 2)
#define lchild(i) (i*2 + 1)
#define int long long
using namespace std;
map<int, int> mp;
bool cmp(int a ,int b){
    return mp[a]>=mp[b];
}
signed main(){
    int n, m;
    cin>>n>>m;
    set<int> s;
    for(int i = 0;i<m;i++){
        int temp;
        cin>>temp;
        s.insert(temp);
        mp[temp]++;
    }
    int ans = 0;
    for(int i = 1;i<=m;i++){
        int count = 0;
        for(int j: s){
            count+=(mp[j]/i);
        }
        if(count>=n) ans = i;
    }
    cout<<ans<<endl;

}
//l, mid(l, r) || l+1, r
//