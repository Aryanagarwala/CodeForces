#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <fstream>
#include <algorithm>
#include <set>
#define INF 10000000000000000
#define MOD 1000000007
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n>>x;
        string s;
        cin>>s;
        int pref[n];
        pref[0] = (s[0]=='0'?1:-1);
        bool found = x==0;
        if(pref[0]==x) found = true;
        for(int i = 1;i<n;i++){
            pref[i] = (s[i]=='0'?1:-1);
            pref[i]+=pref[i-1];
            if(pref[i]==x)  found = true;
        }
        int count = x==0;
        if(pref[n-1]==0){
            if(found) cout<<-1<<endl;
            else cout<<0<<endl;
            continue;
        }
        for(int i = 0;i<n;i++){
            if(((pref[i]-x)%pref[n-1])==0 && ((x-pref[i])/pref[n-1])>=0){
                //cout<<i<<" "<<pref[i]<<" "<<x<<" "<<pref[n-1]<<endl;
                count++;
            }
        }
        cout<<count<<endl;
    }
}
//1 1 2 3 2 1