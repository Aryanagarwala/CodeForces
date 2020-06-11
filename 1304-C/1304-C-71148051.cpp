#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#define int long long
using namespace std;
int32_t main(){
    int q;
    cin>>q;
    while(q--){
        int n, m;
        cin>>n>>m;
        pair<int, pair<int, int>> arr[n];
        for(int i =0 ;i<n;i++) cin>>arr[i].first>>arr[i].second.first>>arr[i].second.second;
        vector<pair<int, pair<int, int>>> a;
        pair<int, int> current;
        int prevtime;
        for(int i = 0;i<n;i++){
            int l = arr[i].second.first, u = arr[i].second.second;
            int j = i+1;
            while(j<n && arr[j].first==arr[i].first){
                l = max(l, arr[j].second.first);
                u = min(u, arr[j].second.second);
                j++;
            }
            j--;
            if(l>u){
                cout<<"NO"<<endl;
                goto end;
            }
            a.push_back(make_pair(arr[i].first, make_pair(l, u)));
        }
        n = a.size();
        current = make_pair(m, m);
        prevtime = 0;
        for(int i = 0;i<n;i++){
            pair<int, int> c = make_pair(current.first-a[i].first + prevtime, current.second+a[i].first - prevtime);
            c.first = max(c.first, a[i].second.first);
            c.second = min(c.second, a[i].second.second);
            if(c.first>c.second){
                cout<<"NO"<<endl;
                goto end;
            }
            current = c;
            prevtime = a[i].first;
        }
        cout<<"YES"<<endl;
        end:
        continue;
    }
}