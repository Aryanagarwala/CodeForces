#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int n, k;
    cin>>n>>k;
    vector<pair<int, int>> seg[200005];
    for(int i = 0;i<n;i++){
        int l, r;
        cin>>l>>r;
        seg[l].push_back(make_pair(r, i));
    }
    int ans = 0;
    vector<int> ans1;
    unordered_map<int, int> removed;
    priority_queue<pair<int, int>> pq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq1;
    int currentseg = 0;
    for(int i = 1;i<200005;i++){
        for(pair<int, int> j: seg[i]){
            pq.push(j);
            pq1.push(j);
            currentseg++;
        }
        while((!pq.empty()) && currentseg>k){
            currentseg--;
            removed[pq.top().first]++;
            ans1.push_back(pq.top().second);
            pq.pop();
            ans++;
        }
        while((!pq1.empty()) && pq1.top().first==i){
            if(removed[i]) removed[i]--;
            else{
                currentseg--;
            }
            pq1.pop();
        }
    }
    cout<<ans<<endl;
    for(int i: ans1){
        cout<<(i+1)<<" ";
    }
    cout<<endl;
}