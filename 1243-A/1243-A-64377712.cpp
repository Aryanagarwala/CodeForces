#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <iomanip>
#include <cmath>
#include <vector>
#define int long long
#define double long double
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int h= 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i =0 ;i<n;i++){
            int num;
            cin>>num;
            pq.push(num);
        }
        int ans = 0;
        while(ans==0){
            int back = pq.top();
            pq.pop();
            if(back>=n){
                ans = n;
                continue;
            }
            n--;
        }
        cout<<ans<<endl;
    }
}
//89
//69
//83