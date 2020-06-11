#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#define int long long
using namespace std;
int root[26];
int findroot(int i){
    if(root[i]==i) return i;
    else return root[i] = findroot(root[i]);
}
bool UNION(int i, int j){
    int r1 = findroot(i);
    int r2 = findroot(j);
    if(r1==r2) return false;
    root[r1] = r2;
    return true;
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        for(int i = 0;i<26;i++){
            root[i] = i;
        }
        bool vis[26];
        cin>>s;
        int topp;
        map<pair<char, char>, bool> mp;
        vector<pair<int, int>> v;
        vector<int> adj[26];
        for(int i = 0;i<(s.length()-1);i++){
            if(mp[make_pair(s[i]-'a', s[i+1]-'a')]) continue;
            mp[make_pair(s[i]-'a', s[i+1]-'a')] = true;
            mp[make_pair(s[i+1]-'a', s[i]-'a')] = true;
            adj[(s[i]-'a')].push_back(s[i+1]-'a');
            adj[s[i+1]-'a'].push_back(s[i]-'a');
            if(!UNION(s[i]-'a', s[i+1]-'a')){
                cout<<"NO"<<endl;
                goto end;
            }
        }
        for(int i = 0;i<26;i++){
            v.push_back(make_pair(adj[i].size(), i));
        }
        sort(v.begin(), v.end());
        if(v[25].first>2){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        for(int i =0 ;i<26;i++) vis[i] = false;
        for(int i = 0;i<26;i++) {
            if(vis[v[i].second]) continue;
            vis[v[i].second] = true;
            queue<int> q;
            q.push(v[i].second);
            while (!q.empty()) {
                topp = q.front();
                q.pop();
                cout<<((char)('a' + topp));
                for (int j: adj[topp]) {
                    if (vis[j]) continue;
                    vis[j] = true;
                    q.push(j);
                }
            }
        }
        cout<<endl;
        end:
        continue;
    }
}