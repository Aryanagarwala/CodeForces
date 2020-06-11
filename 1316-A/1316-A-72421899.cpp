#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mid(l, u) ((l+u)/2)
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
#define int long long
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int arr[n];
        cin>>arr[0];
        int sum =0 ;
        for(int i =1 ;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        arr[0]+=sum;
        arr[0] = min(arr[0], m);
        cout<<arr[0]<<endl;
    }
}