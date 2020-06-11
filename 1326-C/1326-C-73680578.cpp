#include<bits/stdc++.h>
    #define int long long
#define MOD 998244353
    using namespace std;
    int32_t main(){
        int k, n;
        cin>>n>>k;
        int a[n];
        for(int i =0 ;i<n;i++){
            cin>>a[i];
        }
        int rem = n-k;
        int sum = n*(n+1)/2 - rem*(rem+1)/2;
        int curr = 1;
        vector<int> ind;
        for(int i = 0;i<n;i++){
            if(a[i]>rem) ind.push_back(i);
        }
        for(int i = 1;i<ind.size();i++){
            int options = ind[i]-ind[i-1];
            curr*=options;
            curr%=MOD;
        }
        cout<<sum<<" "<<curr<<endl;
    }
    //(((2^90)%998244353)*512)%998244353