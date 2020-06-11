#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i<n;i++) cin>>a[i];
        sort(a, a+n);
        int l = 0;
        int u = n-2;
        int finala[n];
        finala[n-1] = a[n-1];
        for(int ind = n-2;ind>=0;ind--){
            if(ind%2==(n%2)){
                finala[ind] = a[l++];
            }
            else{
                finala[ind] = a[u--];
            }
        }
        for(int i = 0;i<n;i++){
            cout<<finala[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
//-2 4 5 5 6 8
//8 -2 6 4 5 5
//5 5 4 6 -2 8