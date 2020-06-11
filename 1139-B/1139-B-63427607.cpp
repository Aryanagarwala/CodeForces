#include <iostream>
#define int long long
using namespace std;
int32_t main() {
    int n, total, temp;
    cin>>n;
    int a[n];
    for(int i =0 ;i<n;i++) cin>>a[i];
    total = temp = a[n-1];
    for(int i = n-2;i>=0;i--){
        total += temp = max((int)0, min(temp-1, a[i]));
    }
    cout<<total<<endl;
}