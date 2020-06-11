#include <bits/stdc++.h>
#define int long long
#define INF 1000000000000
using namespace std;
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int a[n];
        for(int i =0 ;i<n;i++) cin>>a[i];
        set<int> s;
        for(int i =0 ;i<n;i++) s.insert(a[i]);
        int dist = 0;
        for(int i: s) dist++;
        if(dist>k){
            cout<<-1<<endl;
            continue;
        }
        vector<int> temp;
        for(int i: s) temp.push_back(i);
        for(int i = dist;i<k;i++) temp.push_back(1);
        cout<<(k*n)<<endl;
        for(int i = 0;i<n;i++){
            for(int j: temp){
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
}
//acdabcd