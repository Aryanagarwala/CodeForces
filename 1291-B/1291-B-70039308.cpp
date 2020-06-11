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
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int pivot = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] < i) {
                pivot = i;
                break;
            }
        }
        if (pivot == -1) {
            cout << "Yes" << endl;
            continue;
        }
        bool possible = true;
        for(int i = pivot;i<n;i++){
            a[i] = max(min(a[i-1] - 1, a[i]),(int) 0);
            if(a[i]>=a[i-1]) possible = false;
        }
        if(possible){
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
}
//1 1 2 3 2 1