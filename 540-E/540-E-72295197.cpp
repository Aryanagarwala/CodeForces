#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mid(l, u) ((l+u)/2)
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
#define int long long
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
bool cmp(pair<int, int> a, pair<int, int> b){
    return a>=b;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    map<int, int> mp;
    set<int> s;
    int n;
    cin>>n;
    //6 5 4 3 2 1
    for(int i = 0;i<n;i++){
        int u, v;
        cin>>u>>v;
        s.insert(u);
        s.insert(v);
        if(mp[u]==0) mp[u] = u;
        if(mp[v]==0) mp[v] = v;
        int temp = mp[u];
        mp[u] = mp[v];
        mp[v] = temp;
    }
    oset yo;
    oset yo1;
    int ans = 0;
    vector<int> arr;
    for(int j: s){
        arr.push_back(j);
    }
    sort(arr.begin(), arr.end());
    //4 1 3 2
    for(int i = 0;i<arr.size();i++){
        ans+= (yo.order_of_key(1e9 + 5) - yo.order_of_key(mp[arr[i]]+1));
        yo.insert(mp[arr[i]]);
        yo1.insert(arr[i]);
    }
    for(int i = 0;i<arr.size();i++){
        int u = max(mp[arr[i]], arr[i]);
        int l = min(mp[arr[i]], arr[i]);
        if(l==u) continue;
        int gap = (u-l-1);
        ans+=gap;
        ans-=((yo.order_of_key(u) - yo.order_of_key(l+1)));
    }
    cout<<ans<<endl;
    return 0;
}