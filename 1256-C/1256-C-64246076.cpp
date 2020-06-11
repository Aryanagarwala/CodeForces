#include <iostream>
#include <algorithm>
#define int long long
#define double long double
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, d;
    cin>>n>>m>>d;
    int c[m];
    int plat[n+5];
    int remaining = 0;
    for(int i = 0;i<(n+5);i++) plat[i] = 0;
    for(int i =0 ;i<m;i++) cin>>c[i];
    for(int i = 1;i<m;i++) remaining+=c[i];
    int pos[m];
    pos[0] = min(d, n - remaining-c[0]+1);
    plat[pos[0]] = 1;
    plat[pos[0]+c[0]] = -1;
    for(int i = 1;i<m;i++){
        remaining-=c[i];
        pos[i] = min((pos[i-1] + c[i-1] - 1) + d, n - remaining-c[i]+1);
        plat[pos[i]] += (i+1);
        plat[pos[i]+c[i]] -= (i+1);
    }
    if((pos[m-1] + c[m-1] - 1 + d)>=(n+1)){
        cout<<"YES"<<endl;
        for(int i = 1;i<=n;i++){
            plat[i] += plat[i-1];
            cout<<plat[i]<<" ";
        }
        cout<<endl;
    }
    else cout<<"NO"<<endl;
}