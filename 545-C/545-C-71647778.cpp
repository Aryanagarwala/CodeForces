#include <iostream>
    #include <queue>

#include <algorithm>
#include <fstream>
#include <map>
#define eq 10000
#define int long long
#define MOD 1000000007
    using namespace std;
    int32_t main(){
        int n;
        cin>>n;
        pair<int, int> arr[n];
        for(int i = 0;i<n;i++) cin>>arr[i].first>>arr[i].second;
        int prev = -1e10;
        int count = 0;
        for(int i = 0;i<n;i++){
            if(prev<(arr[i].first-arr[i].second)) count++;
            else{
                if(i==(n-1)){
                    count++;
                }
                else if(arr[i].first+arr[i].second<arr[i+1].first){
                    count++;
                    arr[i].first+=arr[i].second;
                }
            }
            prev = arr[i].first;
        }
        cout<<count<<endl;
    }