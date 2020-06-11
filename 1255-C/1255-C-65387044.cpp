#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define int long long
using namespace std;
map<pair<int, int>, int> mp;
map<int, bool> taken;
map<int, int> cnt;
map<pair<int, int>, int> cnt1;
map<pair<int, int>, int> mp1;
void process(int a, int b, int c){
    if(cnt1[make_pair(a, b)]){
        mp1[make_pair(a, b)]=c;
        mp1[make_pair(b, a)]=c;
    }
    else{
        mp[make_pair(a, b)]= c;
        mp[make_pair(b, a)]= c;
    }
    cnt1[make_pair(a, b)]++;
    cnt1[make_pair(b, a)]++;
}
int32_t main(){
    int n;
    cin>>n;
    vector<vector<int>> fin[n+1];
    for(int i = 0;i<(n-2);i++){
        vector<int> adj;
        for(int j = 0;j<3;j++){
            int num;
            cin>>num;
            adj.push_back(num);
            cnt[num]++;
        }
        process(adj[0], adj[1], adj[2]);
        process(adj[0], adj[2], adj[1]);
        process(adj[2], adj[1], adj[0]);
        for(int j = 0;j<3;j++){
            fin[adj[j]].push_back(adj);
        }
    }
    int finalperm[n];
    int ind = 1;
    for(int i = 1;i<=n;i++){
        if(cnt[i]==1){
            finalperm[0] = i;
            for(int k: fin[i][0]){
                if(k!=i) finalperm[ind++] = k;
            }
            break;
        }
    }
    for(;ind<n;ind++){
        if(cnt1[make_pair(finalperm[ind-1], finalperm[ind-2])]==1){
            int temp = finalperm[ind-2];
            finalperm[ind-2] = finalperm[ind-3];
            finalperm[ind-3] = temp;
        }
        if(mp[make_pair(finalperm[ind-1], finalperm[ind-2])]==finalperm[ind-3]){
            finalperm[ind] = mp1[make_pair(finalperm[ind-1], finalperm[ind-2])];
        }
        else{
            finalperm[ind] = mp[make_pair(finalperm[ind-1], finalperm[ind-2])];
        }
    }
    for(int i = 0;i<n;i++){
        cout<<finalperm[i]<<" ";
    }
    cout<<endl;
}