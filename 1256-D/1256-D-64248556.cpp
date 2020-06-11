#include <iostream>
#include <algorithm>
#define int long long
#define double long double
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        int a[n];
        for(int i = 0;i<n;i++){
            a[i] = s[i]-48;
        }
        int countones = 0;
        for(int i = 0;i<n && k>0;i++){
            if(a[i]==1){
                countones++;
                continue;
            }
            else{
                if(countones==0) continue;
                int change = min(countones, k);
                k-=change;
                a[i-change] = 0;
                a[i] = 1;
            }
        }
        for(int i = 0;i<n;i++) cout<<a[i];
        cout<<endl;
    }
}