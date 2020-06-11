//https://codeforces.com/problemset/problem/1324/D

// https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define rep(i, a, b) for(auto (i)=a;i<b;i++)
#define list(i, N) for(auto (i)=0;i<N;i++)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

typedef long long ll;
#define mp make_pair
#define pb push_back
#define eb emplace_back

#define int ll
#define INF 10000000000000000
#define mod 1000000007

template<class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}
//ith topic -> (a[i], b[i])
//iterate on i
//a[i] - b[i] > b[j] - a[j]
//policy based data structure (PBDS)
//order of key (x) returns number of elements in ordered set that are strictly less than x
using namespace std;
int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    int a[n]; list(i,n) cin >> a[i];
    int b[n]; list(i,n) cin >> b[i];
    vector<int> diff;
    for(int i = 0;i<n;i++) diff.push_back(a[i] - b[i]);
    sort(diff.begin(), diff.end());
    int ans = 0;
    for(auto it = diff.begin();it!=diff.end();it++){
        int need = *it;
        need*=-1; //need + diff = 0
        // need++; //need + diff > 0
        //the minimum difference we can pair it with
        auto it1 = upper_bound(diff.begin(), it, need);
        int toadd = it - it1;
        ans+=toadd;
        //cout<<(*it)<<" "<<need<<" "<<toadd<<endl;
    }
    cout<<ans<<endl;
    return 0;
}