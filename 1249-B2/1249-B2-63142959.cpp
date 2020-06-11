#include <iostream>
#include <algorithm>
#define MOD (1000000007)
using namespace std;
int f(int start, int current, int a[], int len, int ans[]){
    if(current==start) return ans[current] = len;
    return ans[current] = f(start, a[current]-1, a, len+1, ans);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        int a[n];
        for(int i =0 ;i<n;i++) cin>>a[i];
        int ans[n];
        for(int i = 0;i<n;i++) ans[i] = -1;
        for(int i = 0;i<n;i++){
            if(ans[i]!=-1) continue;
            ans[i] = f(i, a[i]-1, a, 1, ans);
        }
        for(int i = 0;i<n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}