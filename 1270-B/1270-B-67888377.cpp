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
        int n;
        cin>>n;
        int arr[n];
        for(int i =0 ;i<n;i++) cin>>arr[i];
        int ind = 0;
        for(int i =0 ;i<(n-1);i++){
            if(abs(arr[i+1]-arr[i])>=(2)) ind = (i+1);            
        }
        if(ind==0){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        cout<<(ind)<<" "<<(ind+1)<<endl;
    }
}