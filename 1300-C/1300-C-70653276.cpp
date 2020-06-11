#include <iostream>
#include <queue>
#include <algorithm>
#define int long long
using namespace std;
int32_t main(){
    int pow2[40];
    pow2[0] = 1;
    for(int i = 1;i<40;i++) pow2[i] = pow2[i-1] * 2;
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i<n;i++) cin>>a[i];
    bool found = false;
    int ind = -1;
    int count = 0;
    for(int bit = 39;bit>=0 && !found;bit--){
        count = 0;
        ind = -1;
        found = false;
        for(int i =0 ;i<n;i++){
            if(pow2[bit]&a[i]){
                //cout<<bit<<" "<<i<<" "<<pow2[bit]<<" "<<a[i]<<endl;
                ind = i;
                count++;
            }
        }
        //cout<<bit<<" "<<count<<endl;
        if(count==1) found = true;
    }
    if(found){
        int temp = a[ind];
        a[ind] = a[0];
        a[0] = temp;
    }
    for(int i =0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}