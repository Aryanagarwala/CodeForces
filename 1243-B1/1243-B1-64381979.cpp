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
        string s, t;
        cin>>s>>t;
        vector<int> needs;
        vector<int> needt;
        for(int i = 0;i<n;i++){
            if(s[i]!=t[i]){
                needs.push_back(t[i]);
                needt.push_back(s[i]);
            }
        }
        if(needs.size()!=2){
            cout<<"No"<<endl;
            continue;
        }
        else{
            if(needs[0]==needs[1] && needt[0]==needt[1]){
                cout<<"Yes"<<endl;
                continue;
            }
            else{
                cout<<"No"<<endl;
                continue;
            }
        }
    }
}
//89
//69
//83