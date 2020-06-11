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
    int n, a, b, k;
    cin>>n>>a>>b>>k;
    int h[n];
    for(int i = 0;i<n;i++) cin>>h[i];
    int times[n];
    for(int i = 0;i<n;i++){
        int rem = h[i]%(a+b);
        if(rem>0 && rem<=a){
            times[i] = 0;
            continue;
        }
        if(rem==0) rem = b;
        else rem-=a;
        times[i] = (rem/a) + (((rem%a)>0)?1:0);
    }
    sort(times, times+n);
    int sum = 0;
    int pnts = 0;
    for(int i = 0;i<n;i++){
        if((sum+times[i])<=k) pnts++;
        else break;
        sum+=times[i];
    }
    cout<<pnts<<endl;
    return 0;
}