#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
#define MOD ((long long)1e9 + 7)
#define int long long
using namespace std;
int findroot(int i, int root[]){
    if(root[i]==i) return i;
    else return root[i] = findroot(root[i], root);
}
bool UNION(int i, int j, int root[], int ranks[]){
    int r1 = findroot(i, root);
    int r2 = findroot(j, root);
    if(r1==r2) return false;
    else{
        if(ranks[r1]<ranks[r2]){
            root[r1] = r2;
            ranks[r2]+=ranks[r1];
        }
        else{
            root[r2] = r1;
            ranks[r1]+=ranks[r2];
        }
    }
    return true;
}
int32_t main(){
    int n;
    cin>>n;
    int ranks[n+1];
    int root[n+1];
    for(int i = 0;i<=n;i++) ranks[i] = 1;
    for(int i = 0;i<=n;i++) root[i] = i;
    pair<int, int> loc[n];
    for(int i = 0;i<n;i++){
        cin>>loc[i].first>>loc[i].second;
    }
    int cost[n];
    for(int i = 0;i<n;i++){
        cin>>cost[i];
    }
    int k[n];
    for(int i = 0;i<n;i++){
        cin>>k[i];
    }
    vector<pair<long long, pair<int, int>>> edges;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<i;j++){
            long long c = (k[i] + k[j])*(abs(loc[i].first - loc[j].first) + abs(loc[i].second - loc[j].second));
            edges.push_back(make_pair(c, make_pair(i, j)));
        }
        edges.push_back(make_pair(cost[i], make_pair(i, n)));
    }
    sort(edges.begin(), edges.end());
    vector<int> buildhere;
    vector<pair<int, int>> connections;
    int ans = 0;
    for(pair<int, pair<int, int>> cedge: edges){
        bool include = UNION(cedge.second.first, cedge.second.second, root, ranks);
        if(include){
            ans+=cedge.first;
            if(cedge.second.second==n) buildhere.push_back(cedge.second.first);
            else{
                connections.push_back(cedge.second);
            }
        }
    }
    cout<<ans<<endl;
    cout<<buildhere.size()<<endl;
    for(int node: buildhere){
        cout<<(node+1)<<" ";
    }
    cout<<endl;
    cout<<connections.size()<<endl;
    for(pair<int, int> conn: connections){
        cout<<(conn.first + 1)<<" "<<(conn.second+1)<<endl;
    }
}