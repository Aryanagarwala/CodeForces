#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
int ranks[(int)1e5 + 5];
int root[(int)1e5 + 5];
int spec[(int)1e5 + 5];
int n, m, k;
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    return a.second<b.second;
}
int findroot(int i){
    if(root[i]==i) return i;
    else return root[i] = findroot(root[i]);
}
bool UNION(int i, int j){
    int r1 = findroot(i);
    int r2 = findroot(j);
    if(r1==r2) return false;
    if(ranks[r1]<ranks[r2]){
        ranks[r2]+=ranks[r1];
        spec[r2]+=spec[r1];
        root[r1] = r2;
        return spec[r2]==k;
    }
    else{
        ranks[r1]+=ranks[r2];
        root[r2] = r1;
        spec[r1]+=spec[r2];
        return spec[r1]==k;
    }
}
int32_t main() {
    cin>>n>>m>>k;
    unordered_map<int, bool> special;
    for(int i = 0;i<k;i++){
        int vert;
        cin>>vert;
        special[vert] = true;
    }
    vector<pair<pair<int, int>, int>> edges;
    for(int i = 0;i<m;i++){
        int u, v, weight;
        cin>>u>>v>>weight;
        edges.push_back(make_pair(make_pair(u, v), weight));
    }
    for(int i = 1;i<=n;i++){
        root[i] = i;
        ranks[i] = 1;
        spec[i] = special[i];
    }
    sort(edges.begin(), edges.end(), cmp);
    for(pair<pair<int, int>, int> curr: edges){
        bool include = UNION(curr.first.first, curr.first.second);
        if(include){
            for(int i = 0;i<k;i++) cout<<curr.second<<" ";
            return 0;
        }
    }
}