#include <iostream>
#include <algorithm>
#define MOD (1000000007)
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        int a[n];
        for(int i =0 ;i<n;i++) cin>>a[i];
        sort(a, a+n);
        int count = 1;
        for(int i = 1;i<n;i++){
            if(a[i]-a[i-1]==1) count = 2;
        }
        cout<<count<<endl;
    }
}