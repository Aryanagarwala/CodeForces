#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int cost[n];
        pair<int, int> a[n];
        vector<int> adj[n];
        vector<pair<int, int>> edges;
        for(int i = 0;i<n;i++){
            cin>>cost[i];
            a[i].first = cost[i];
            a[i].second = i;
        }
        if(n==2){
            cout<<-1<<endl;
            continue;
        }
        sort(a, a+n);
        int ans = 0;
        int nodes = 0;
        for(int i = 0;i<n;i++){
            while(adj[i].size()<2){
                pair<int, int> mini = make_pair(1e9, 1e9);
                for(int k = 0;k<n;k++){
                    if(k!=i){
                        bool found = false;
                        for(int l: adj[i]){
                            if(l==k) found = true;
                        }
                        if(!found){
                            mini = min(make_pair((int)adj[k].size(), k), mini);
                        }
                    }
                }
                edges.push_back(make_pair(i, mini.second));
                ans += cost[i] + cost[mini.second];
                adj[i].push_back(mini.second);
                adj[mini.second].push_back(i);
                //cout<<i<<" "<<mini.second<<" "<<adj[i].size()<<endl;
                nodes++;
            }
        }
        if(nodes>m || n==2){
            cout<<-1<<endl;
            continue;
        }
        ans += (a[0].first + a[1].first)*(m - nodes);
        for(int i = 0;i<(m-nodes);i++){
            edges.push_back(make_pair(a[0].second, a[1].second));
        }
        cout<<ans<<endl;
        for(pair<int, int> j: edges){
            cout<<(j.first+1)<<" "<<(j.second+1)<<endl;
        }
    }
}