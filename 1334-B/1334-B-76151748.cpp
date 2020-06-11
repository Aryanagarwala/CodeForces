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
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n>>x;
        int a[n];
        for(int i = 0;i<n;i++) cin>>a[i];
        sort(a, a+n);
        int amt = 0;
        int sum = 0;
        int q = 1;
        for(int i = n-1;i>=0;i--, amt++){
            sum+=a[i];
            if(sum/q < x) break;
            q++;
        }
        cout<<amt<<endl;
    }
    return 0;
}