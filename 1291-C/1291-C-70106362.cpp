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
        int n, m, k;
        cin>>n>>m>>k;
        int a[n];
        for(int i =0;i<n;i++) cin>>a[i];
        k = min(k, m-1);
        int idk = m-1-k;
        int ans = -100;
        for(int front = 0;front<=k;front++){
            int back = k - front;
            vector<int> rem;
            for(int j = front;j<(n-back);j++){
                rem.push_back(a[j]);
            }
            int len = rem.size();
            int worst = 10000000000;
            for(int takefromfront = 0;takefromfront<=idk;takefromfront++){
                int takefromback = idk - takefromfront;
                worst = min(worst, max(rem[takefromfront], rem[len-takefromback-1]));
            }
            ans = max(ans, worst);
        }
        cout<<ans<<endl;
    }
}
//1 1 2 3 2 1