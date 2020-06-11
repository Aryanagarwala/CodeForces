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
            int n, x;
            cin>>n>>x;
            int maxi = -1;
            bool found = false;
            for(int i = 0;i<n;i++){
                int num;
                cin>>num;
                maxi = max(maxi, num);
                if(num==x) found = true;
            }
            //cout<<x<<" "<<maxi<<endl;
            int ans = (x/maxi) + ((x%maxi>0)?1:0);
            if(ans==1 && !found) ans = 2;
            cout<<ans<<endl;
        }
        return 0;
    }