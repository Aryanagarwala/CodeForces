#include <iostream>
    #include <queue>
    #include <algorithm>
    #include <cmath>
    #include <map>
    #include <vector>
    #include <set>
    #include <unordered_map>
    #define um unordered_map
    #define mid(l, u) (l+u)/2
    #define rchild(i) (i*2 + 2)
    #define lchild(i) (i*2 + 1)
    #define int long long
    using namespace std;
    int32_t main(){
        int t;
        cin>>t;
        while(t--){
            int n, d;
            cin>>n>>d;
            int a[n];
            for(int i =0 ;i<n;i++) cin>>a[i];
            for(int i = 1;i<n;i++){
                int canmove = min(a[i], d/i);
                a[0]+=canmove;
                d-=(canmove*i);
            }
            cout<<a[0]<<endl;
        }
        return 0;
    }