#include <iostream>
    #include <algorithm>
    #include <cmath>
    #include <unordered_map>
    #include <fstream>
    #include <stack>
    #include <vector>
    #include <set>
    #include <queue>
    #include <cstdlib>
    #include <cstring>
    #include <map>
    #define int long long
    using namespace std;
    int32_t main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int t;
        cin>>t;
        while(t--){
            int n;
            cin>>n;
            n*=2;
            int arr[n+1];
            int pre[n+3];
            int post[n+3];
            for(int i =1;i<=n;i++){
                cin>>arr[i];
                arr[i] = arr[i]==2?1:-1;
            }
            pre[0] = 0;
            post[n+1] = 0;
            for(int i = 1;i<=(n/2);i++) pre[i] = arr[i] + pre[i-1];
            for(int i = n;i>(n/2);i--) post[i] = post[i+1] + arr[i];
            int ind[3*n];
            for(int i =0 ;i<(3*n);i++) ind[i] = -1;
            ind[n] = 0;
            for(int i = 1;i<=(n/2);i++){
                ind[pre[i]+n] = i;
            }
            int maxi = 0;
            for(int i = (n/2)+1;i<=(n+1);i++){
                if((ind[(-1*post[i])+n]>-1)){
                    //cout<<i<<" "<<ind[(-post[i])+n]<<" "<<post[i]<<" "<<((n-i+1) + ind[(-post[i])+n])<<endl;
                    maxi = max(maxi, (n-i+1) + ind[(-post[i])+n]);
                }
            }
            cout<<(n-maxi)<<endl;
        }
    }