#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#define int long long
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, a, b;
        cin>>x>>y>>a>>b;
        int lo = 0;
        int hi = 1e10;
        bool found = false;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            int xpos = x + (a*mid);
            int ypos = y - (b*mid);
            if(ypos<xpos){
                hi = mid - 1;
            }
            else if(xpos<ypos){
                lo = mid + 1;
            }
            else{
                found = true;
                break;
            }
        }
        cout<<(found?(lo+hi)/2:-1)<<endl;
    }
}