#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <fstream>
#include <algorithm>
#include <set>
#define INF 10000000000000000
#define MOD 1000000007
#define mid(l, u) ((l+u)/2)
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
#define int long long
using namespace std;
int segtree[(int)(8e5) + 5];
int lazy[(int)(8e5) + 5];
int build(int l, int u, int i, int arr[]){
    lazy[i] = 0;
    if(l==u) return segtree[i] = arr[l];
    return segtree[i] = min(build(l, mid(l, u), lchild(i), arr), build(mid(l, u)+1, u, rchild(i), arr));
}
int query(int l, int u, int i, int ll, int uu){
    if(lazy[i]!=0){
        segtree[i]+=lazy[i];
        if(l!=u){
            lazy[lchild(i)]+=lazy[i];
            lazy[rchild(i)]+=lazy[i];
        }
        lazy[i] = 0;
    }
    if(l>=ll && u<=uu) return segtree[i];
    if(ll>u || uu<l) return INF;
    return min(query(l, mid(l, u), lchild(i), ll, uu), query(mid(l,u)+1, u, rchild(i), ll, uu));
}
int update(int l, int u, int i, int ll, int uu, int upval){
    if(lazy[i]){
        segtree[i]+=lazy[i];
        if(l!=u){
            lazy[lchild(i)]+=lazy[i];
            lazy[rchild(i)]+=lazy[i];
        }
        lazy[i] = 0;
    }
    if(l>=ll && u<=uu){
        segtree[i]+=upval;
        if(l!=u){
            lazy[lchild(i)]+=upval;
            lazy[rchild(i)]+=upval;
        }
        return segtree[i];
    }
    if(ll>u || uu<l) return segtree[i];
    return segtree[i] = min(update(l, mid(l, u), lchild(i), ll, uu, upval), update(mid(l,u)+1, u, rchild(i), ll, uu, upval));
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    pair<int, int> sarr[n], arr[n];
    int totalsum = 0;
    for(int i =0 ;i<n;i++){
        cin>>sarr[i].first;
        arr[i].first = sarr[i].first;
    }
    int orig[n];
    for(int i = 0;i<n;i++){
        cin>>sarr[i].second;
        arr[i].second = sarr[i].second;
        totalsum+=arr[i].second;
    }
    int ind[n+1];
    sort(sarr, sarr+n);
    orig[0] = sarr[0].second;
    ind[sarr[0].first] = 0;
    for(int i =1 ;i<n;i++){
        orig[i] = sarr[i].second + orig[i-1];
        ind[sarr[i].first] = i;
    }
    build(0, n-1, 0, orig);
    int ans = INF;
    int ours = 0;
    for(int i = 0;i<(n-1);i++){
        int index = ind[arr[i].first];
        if(index>0) update(0, n-1, 0, 0, index-1, arr[i].second);
        update(0, n-1, 0, index, n-1, -arr[i].second);
        ans = min(ans, query(0, n-1, 0, 0, n-1));
        ours+=arr[i].second;
        ans = min(ours, ans);
        ans = min(ans, totalsum - ours);
    }
    cout<<ans<<endl;
}
//1 1 2 3 2 1