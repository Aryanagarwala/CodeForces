#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define int long long
#define double long double
using namespace std;
int32_t main(){
    int n;
    cin>>n;
    vector<pair<int, int>> mm;
    int ans = 0;
    int funcn = n;
    int ind = -1;
    bool lolol = false;
    while(n--){
        int l;
        cin>>l;
        int arr[l];
        for(int j = 0;j<l;j++) cin>>arr[j];
        ind++;
        mm.push_back(make_pair(1e9, -1));
        lolol = true;
        for(int j = 0;j<l && lolol;j++){
            int num = arr[j];
            if(mm[ind].first<num){
                ans+=((--funcn)*2) + 1;
                mm.pop_back();
                ind--;
                lolol = false;
            }
            else {
                mm[ind].first = min(mm[ind].first, num);
                mm[ind].second = max(mm[ind].second, num);
            }
        }
    }
    sort(mm.begin(), mm.end());
    for(int i = 0;i<mm.size();i++){
        int toadd = upper_bound(mm.begin(), mm.end(), make_pair(mm[i].second-1, (int)1e9)) - mm.begin();
        //cout<<toadd<<" "<<mm[toadd].first<<" "<<mm[toadd].second<<endl;
        //if(toadd>i) toadd--;
        //cout<<"Adding "<<toadd<<endl;
        ans+=toadd;
    }
    cout<<ans<<endl;
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