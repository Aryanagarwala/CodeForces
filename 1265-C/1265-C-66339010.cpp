#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <cstdlib>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0;i<n;i++) cin>>arr[i];
        vector<int> d;
        for(int i = 0;i<(n/2);i++) if(arr[i+1]!=arr[i]) d.push_back(i);
        int g = 0, s = 0, b = 0, t = 0;
        if(d.size()<3){
            cout<<0<<" "<<0<<" "<<0<<endl;
            continue;
        }
        g = d[0] + 1;
        auto it = lower_bound(d.begin(), d.end(), (2*g));
        if(it==d.end()){
            cout<<0<<" "<<0<<" "<<0<<endl;
            continue;
        }
        s = *it - g + 1;
        if(d[d.size()-1]==(s+g-1)){
            cout<<0<<" "<<0<<" "<<0<<endl;
            continue;
        }
        b = (d[d.size()-1] - (s+g-1));
        if(b<=g){
            cout<<0<<" "<<0<<" "<<0<<endl;
            continue;
        }
        cout<<g<<" "<<s<<" "<<b<<endl;
    }
}