#include <iostream>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int sum = 0;
        for(int i = 0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        int maxi = -1e16;
        int maxsum = -1e16;
        int csum = 0;
        for(int i  = 0;i<(n-1);i++){
            csum+=arr[i];
            maxsum = max(maxsum, csum);
            csum = max((int)0, csum);
        }
        maxi = max(maxi, maxsum);
        maxsum = -1e16;
        csum = 0;
        for(int i  = 1;i<n;i++){
            csum+=arr[i];
            maxsum = max(maxsum, csum);
            csum = max((int)0, csum);
        }
        maxi = max(maxi, maxsum);
        //cout<<maxsum<<" "<<csum<<endl;
        if(maxi<sum) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}