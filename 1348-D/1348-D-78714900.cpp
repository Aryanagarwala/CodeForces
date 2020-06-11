#include <bits/stdc++.h>
#define int long long
#define INF 1000000000000
using namespace std;
int binsearch(int currn, int currm, int remnights, int reqn){
    int l = 0;
    int u = currn;
    int ans = 0;
    while(l<=u){
        int m = (l+u)/2;
        int after = (currn + m)*remnights + currm;
        if(after<=reqn){
            ans = max(ans, m);
            l = m+1;
        }
        else u = m-1;
    }
    return ans;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int l = 1;
        int u = 30;
        int ans = n;
        while(l<=u){
            int m = (l+u)/2;
            int num = pow(2, m) - 1;
            if(num>=n){
                ans = min(ans, m);
                u = m-1;
            }
            else{
                l = m+1;
            }
        }
        ans--;
        cout<<ans<<endl;
        int currn = 1;
        int currm = 1;
        int remnights = ans;
        int reqn = n;
        while(remnights){
            int toadd = binsearch(currn, currm, remnights, reqn);
            cout<<toadd<<" ";
            currn+=toadd;
            remnights--;
            currm+=currn;
        }
        cout<<endl;
    }
}
//acdabcd