#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <map>
#define MOD 1000000007
#define mid(l, u) ((l+u)/2)
#define int long long
#define double long double
#define child(i) (i*2 + 1)
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i =0 ;i<n;i++){
            cin>>arr[i];
        }
        set<int> base;
        unordered_map<int, int> cnt;
        for(int i =0 ;i<n;i++){
            int lol = 0;
            while(arr[i]%2==0){
                arr[i]/=2;
                lol++;
            }
            base.insert(arr[i]);
            cnt[arr[i]] = max(cnt[arr[i]], lol);
        }
        int ans = 0;
        for(int i: base){
            ans+=cnt[i];
        }
        cout<<ans<<endl;
    }
}