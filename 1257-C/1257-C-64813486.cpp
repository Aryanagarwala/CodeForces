#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        vector<int> occ[n+1];
        for(int i = 0;i<n;i++){
            cin>>a[i];
            occ[a[i]].push_back(i);
        }
        int ans = n+1;
        for(int i = 1;i<=n;i++){
            if(occ[i].size()<2) continue;
            for(int j = 1;j<occ[i].size();j++){
                ans = min(ans, occ[i][j] - occ[i][j-1]);
            }
        }
        if(ans>n){
            cout<<-1<<endl;
            continue;
        }
        else{
            cout<<(ans+1)<<endl;
            continue;
        }
    }
}