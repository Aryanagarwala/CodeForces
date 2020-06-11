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

    int n; cin >> n;
    int a[n];
    for(int i = 0;i<n;i++) cin>>a[i];
    int maxi = -1;
    int ind = -1;
    for(int i = 0;i<n;i++){
        if(maxi>a[i]){
            ind = i;
            break;
        }
        maxi = max(maxi, a[i]);
    }
    if(ind==-1){
        cout<<0<<endl;
        return 0;
    }
    int shifts = n - ind;
    maxi = -1;
    bool sorted = true;
    for(int i = ind;i<n;i++){
        if(maxi>a[i]){
            sorted = false;
            break;
        }
        maxi = max(maxi, a[i]);
    }
    for(int i = 0;i<ind;i++){
        if(maxi>a[i]){
            sorted = false;
            break;
        }
        maxi = max(maxi, a[i]);
    }
    if(sorted){
        cout<<shifts<<endl;
        return 0;
    }
    cout<<-1<<endl;
    return 0;
}