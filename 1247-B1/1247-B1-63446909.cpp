#include <iostream>
#include <unordered_map>
#define int long long
using namespace std;
int32_t main() {
    int t;
    cin>>t;
    while(t--){
        int n, k, d;
        cin>>n>>k>>d;
        int arr[n];
        for(int i = 0;i<n;i++) cin>>arr[i];
        int currentsum = 0;
        int occurence[k+1];
        int minsum = 0;
        for(int i = 0;i<=k;i++) occurence[i] = -1;
        for(int i = 0;i<d;i++){
            if(occurence[arr[i]]<0) currentsum++;
            occurence[arr[i]] = i;
        }
        minsum = currentsum;
        for(int i = d;i<n;i++){
            if(occurence[arr[i-d]]==(i-d)) currentsum--;
            if(occurence[arr[i]]<=(i-d)) currentsum++;
            occurence[arr[i]] = i;
            minsum = min(minsum, currentsum);
        }
        cout<<minsum<<endl;
    }
}