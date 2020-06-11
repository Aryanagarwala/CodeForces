#include <iostream>
#include <algorithm>
#define int long long
#define double long double
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        bool done[n];
        for(int i = 0;i<n;i++) cin>>a[i];
        for(int i = 0;i<n;i++) done[i] = false;
        done[0] = true;
        int turns = n-1;
        bool change = true;
        while(turns>0 && change){
            change = false;
            pair<int, int> smallest = make_pair(1e12, 1e12);
            for(int i = 1;i<n;i++){
                if(a[i]<a[i-1] && !done[i]){
                    smallest = min(smallest, make_pair(a[i], i));
                }
            }
            if(smallest.first == 1e12) continue;
            change = true;
            for(int i = smallest.second;turns>0 && i>0 && done[i]==false && a[i]<a[i-1];i--, turns--){
                done[i] = true;
                int temp = a[i];
                a[i] = a[i-1];
                a[i-1] = temp;
            }
        }
        for(int i = 0;i<n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
}