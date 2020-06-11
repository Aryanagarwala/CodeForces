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
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i =0 ;i<n;i++) cin>>a[i];
        int b[n];
        for(int i =0 ;i<n;i++) cin>>b[i];
        sort(a, a+n);
        sort(b, b+n);
        for(int i =0 ;i<n;i++) cout<<a[i]<<" ";
        cout<<endl;
        for(int i = 0;i<n;i++) cout<<b[i]<<" ";
        cout<<endl;
    }
    return 0;
}