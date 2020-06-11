#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int a[n+1];
    map<pair<int, int>, int> mp;
    int cost = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        cost+=a[i];
    }
    int q;
    cin>>q;
    while(q--){
        int s, t, u;
        cin>>s>>t>>u;
        if(mp[{s, t}]!=0){
            a[mp[{s, t}]]++;
            if(a[mp[{s, t}]]>=1) cost++;
        }
        mp[{s, t}] = u;
        if(u==0){

            cout<<cost<<"\n";
            continue;
        }
        a[u]--;
        if(a[u]>=0) cost--;
        cout<<cost<<"\n";
    }
}
//b k
//1 3
//