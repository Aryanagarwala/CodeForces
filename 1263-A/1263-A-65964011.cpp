#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <vector>
#include <queue>
#define int long long
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--) {
        int arr[3];
        for (int i = 0; i < 3; i++) cin >> arr[i];
        sort(arr, arr+3);
        int days = 0;
        int toadd = min(arr[2]-arr[1], arr[0]);
        days+=toadd;
        arr[2]-=toadd;
        arr[0]-=toadd;
        sort(arr, arr+3);
        toadd = arr[0]/2;
        arr[2]-=(arr[0] - toadd);
        arr[1]-=toadd;
        days+=arr[0];
        days+= min(arr[1], arr[2]);
        cout<<days<<endl;
    }
}