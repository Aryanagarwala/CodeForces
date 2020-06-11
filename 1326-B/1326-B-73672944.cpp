#include<bits/stdc++.h>
    #define int long long
    using namespace std;
    int32_t main(){
        int n;
        cin>>n;
        int b[n];
        for(int i = 0;i<n;i++) cin>>b[i];
        int a[n];
        int currmax = 0;
        for(int i =0 ;i<n;i++){
            a[i] = b[i] + currmax;
            currmax = max(a[i], currmax);
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    //(((2^90)%998244353)*512)%998244353