#include <iostream>
#include <queue>
#define int long long
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        int sum = 0;
        int add = 0;
        for(int i = 0;i<n;i++){
            cin>>a[i];
            if(a[i]==0){
                add++;
                a[i] = 1;
            }
            sum+=a[i];
        }
        cout<<(add + (sum==0))<<endl;
    }
}