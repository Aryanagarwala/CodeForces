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
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        char a[n][m];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++) a[i][j] = 'B';
        }
        a[0][0] = 'W';
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cout<<a[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}