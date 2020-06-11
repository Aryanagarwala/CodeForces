#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#define mid(l, u) ((l+u)/2)
using namespace std;
int32_t main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans = 0;
        vector<pair<pair<int, int>, int>> level[12];
        level[0].push_back(make_pair(make_pair(1, n), 0));
        int lvl = 1;
        while(true){
            for(pair<pair<int, int>, int> c: level[lvl-1]){
                if(c.first.second-c.first.first==0) continue;
                level[lvl].push_back(make_pair(make_pair(c.first.first, mid(c.first.first, c.first.second)), 0));
                level[lvl].push_back(make_pair(make_pair(mid(c.first.first, c.first.second)+1, c.first.second), 1));
            }
            if(!level[lvl].size()) goto printans;
            vector<int> q[2];
            for(pair<pair<int, int>, int> c: level[lvl]){
                for(int i = c.first.first;i<=c.first.second;i++){
                    q[c.second].push_back(i);
                }
            }
            cout<<q[0].size()<<" "<<q[1].size()<<" ";
            for(int i: q[0]) cout<<i<<" ";
            for(int i: q[1]) cout<<i<<" ";
            cout<<endl;
            cout.flush();
            int tempans;
            cin>>tempans;
            ans = max(ans, tempans);
            lvl++;
        }
        printans:
        cout<<-1<<" "<<ans<<endl;
    }
}