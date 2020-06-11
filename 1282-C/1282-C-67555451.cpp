#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <fstream>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <map>
#define int long long
#define mid(l, u) ((l+u)/2)
#define rchild(i) (i*2 + 2)
#define lchild(i) (i*2 + 1)
#define INF -10000000000
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin>>m;
    while(m--){
        int n, t, a, b;
        cin>>n>>t>>a>>b;
        int cnta = 0;
        int cntb = 0;
        pair<int, pair<int, int>> ex[n+1];
        for(int i =0 ;i<n;i++){
            ex[i] = make_pair(0, make_pair(0, 0));
            int val;
            cin>>val;
            if(val){
                cntb++;
                ex[i].second.second = 1;
            }
            else{
                cnta++;
                ex[i].second.first = 1;
            }
        }
        for(int i =0 ;i<n;i++){
            int time;
            cin>>time;
            ex[i].first = time;
        }
        ex[n] = make_pair(t+1, make_pair(cnta, cntb));
        sort(ex, ex+n);
        for(int i = 1;i<n;i++){
            ex[i].second.first+=ex[i-1].second.first;
            ex[i].second.second+=ex[i-1].second.second;
        }
        /*for(int i = 0;i<n;i++){
            cout<<ex[i].first<<" "<<ex[i].second.first<<" "<<ex[i].second.second<<endl;
        }*/
        bool possible = true;
        int ans = 0;
        pair<int, int> prevtaken = make_pair(0, 0);
        for(int i = 0;i<n;i++){
            int timewehave = ex[i+1].first-1;
            int timeneeded = ex[i].second.first*a + ex[i].second.second*b;
            //cout<<(i+1)<<" "<<timewehave<<" "<<timeneeded<<endl;
            if(timewehave>=timeneeded) ans = max(ans, ex[i].second.first + ex[i].second.second);
            int timerem = (ex[i].first - 1) - (prevtaken.first*a + prevtaken.second*b);
            //cout<<"REMAINTIME "<<timerem<<" "<<cnta<<" "<<prevtaken.first<<endl;
            if(timerem>0) {
                int atobuy = max(min(timerem / a, cnta - prevtaken.first), (int) 0);
                timerem -= a * atobuy;
                int btobuy = min(timerem / b, cntb - prevtaken.second);
                int othercase = prevtaken.first + prevtaken.second + btobuy + atobuy;
                //cout << (i + 1) << " " << atobuy << " " << btobuy << endl;
                ans = max(ans, othercase);
            }
            prevtaken = make_pair(ex[i].second.first, ex[i].second.second);
        }
        cout<<ans<<endl;
    }
}
//3 10
//0 4 7
/*
 1 3
2 11
4 8
5 7
6 10
9 12
 */