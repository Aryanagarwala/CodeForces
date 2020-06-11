#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>
#include <set>
#include <iomanip>
#include <unordered_map>
#define INF 1e16
#define int long long
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, s;
        cin>>n>>s;
        pair<int, int> inf[n];
        for(int i = 0;i<n;i++){
            cin>>inf[i].first>>inf[i].second;
        }
        sort(inf, inf+n);
        int u = s;
        int l = 1;
        int best = 1;
        while(u>=l){
            int m = (l+u)/2;
            //cout<<m<<endl;
            int i = 0;
            int j = n-1;
            int cost = 0;
            bool taken[n];
            for(int k = 0;k<n;k++){
                if(inf[k].second<m){
                    taken[k] = true;
                    cost+=inf[k].first;
                    i++;
                }
                else{
                    taken[k] = false;
                }
            }
            for(int k = 0;k<n;k++){
                if(inf[k].first>m){
                    cost+=inf[k].first;
                    taken[k] = true;
                    j++;
                }
            }
            vector<int> temp;
            for(int k = 0;k<n;k++){
                if(!taken[k]) temp.push_back(inf[k].first);
            }
            if(i>(n/2)){
                //cout<<"TOO MANY ARE TOO LOW"<<endl;
                u = m-1;
                continue;
            }
            for(int k: temp){
                if(i<(n/2)){
                    cost+=k;
                    i++;
                }
                else{
                    cost+=m;
                }
            }
            if(cost>s){
                //cout<<"TOO EXPENSIVE! "<<cost<<endl;
                u = m-1;
                continue;
            }
            l = m+1;
            //cout<<"IT'S POSSIBLE"<<endl;
            best = max(best, m);
            continue;
        }
        cout<<best<<endl;
    }
}
//1 3
//2 6
//