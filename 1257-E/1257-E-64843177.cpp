#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
#define int long long
using namespace std;
int32_t main(){
    int n[3];
    cin>>n[0]>>n[1]>>n[2];
    vector<int> a[3];
    int total = n[0]+n[1]+n[2];
    bool occ[total+1][3];
    int cost[total+1][3];
    int bcost[total+1];
    for(int i = 0;i<=total;i++){
        occ[i][0] = occ[i][1] = occ[i][2] = false;
        cost[i][0] = cost[i][1] = cost[i][2] = 0;
    }
    for(int i = 0;i<3;i++){
        for(int j = 0;j<n[i];j++){
            int num;
            cin>>num;
            a[i].push_back(num);
            occ[num][i] = true;
        }
    }
    for(int i = 0;i<3;i++){
        cost[0][i] = 0;
        for(int j = 1;j<=total;j++){
            cost[j][i] = cost[j-1][i] + occ[j][i];
        }
    }
    for(int i = total;i>0;i--){
        //cout<<cost[total][1]<<" "<<cost[i-1][1]<<" "<<cost[total-1][2]<<" ";
        bcost[i] = cost[total][1] - cost[i-1][1];
        bcost[i] += cost[i-1][2];
        //cout<<bcost[i]<<endl;
    }
    int mini = cost[total][2];
    int ans = 1e9;
    for(int i = total;i>=0;i--){
        //cout<<cost[total][0]<<" "<<cost[i][0]<<" "<<cost[i][1]<<" ";
        int costoftransfer = (cost[total][0] - cost[i][0]) + cost[i][1] + mini;
        //cout<<i<<" "<<costoftransfer<<" "<<mini<<endl;
        ans = min(costoftransfer, ans);
        mini = min(mini, bcost[i]);
    }
    cout<<ans<<endl;
}