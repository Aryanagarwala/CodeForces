#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#define int long long
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n, k1, k2;
        cin>>n>>k1>>k2;
        int arr[k1], arr1[k2];
        int max1 = -1, max2 = -1;
        for(int i = 0;i<k1;i++) cin>>arr[i];
        for(int i =0 ;i<k2;i++) cin>>arr1[i];
        for(int i =0 ;i<k1;i++) max1 = max(max1, arr[i]);
        for(int i =0 ;i<k2;i++) max2 = max(max2, arr1[i]);
        if(max1>max2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}