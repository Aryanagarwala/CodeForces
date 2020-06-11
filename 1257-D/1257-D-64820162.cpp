#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i<n;i++) cin>>a[i];
        int m;
        cin>>m;
        vector<pair<int, int>> h;
        int maxi[m];
        for(int i = 0;i<m;i++){
            pair<int, int> temp;
            cin>>temp.first>>temp.second;
            h.push_back(temp);
        }
        sort(h.begin(), h.end());
        maxi[m-1] = h[m-1].second;
        for(int i = m-2;i>=0;i--){
            maxi[i] = max(maxi[i+1], h[i].second);
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            int currentmax = a[i];
            int j = i;
            while(j<n){
                currentmax = max(currentmax, a[j]);
                int index = lower_bound(h.begin(), h.end(), make_pair(currentmax, 0)) - h.begin();
                if(index==m) goto outer;
                if(maxi[index]<(j-i+1)) goto outer;
                j++;
            }
            outer:
            if(j==i){
                goto failed;
            }
            ans++;
            i = j-1;
        }
        cout<<ans<<endl;
        continue;
        failed:
        cout<<-1<<endl;
    }
}