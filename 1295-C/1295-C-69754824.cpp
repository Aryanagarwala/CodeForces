#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <fstream>
#include <algorithm>
#include <set>
#define INF 10000000000000000
#define MOD 1000000007
#define mid(l, u) ((l+u)/2)
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    while(test--){
        string s, t;
        cin>>s>>t;
        vector<int> occ[26];
        for(int i = 0;i<s.length();i++){
            occ[s[i] - 'a'].push_back(i);
            //cout<<i<<endl;
        }
        int count = 0;
        bool found = true;
        for(int i = 0;i<t.length();i++){
            if(occ[t[i]-'a'].size()==0){
                found = false;
                break;
            }
            int start = occ[t[i]-'a'][0];
            int j = i+1;
            for(;j<t.length();j++){
                if(start==s.length()-1) break;
                auto ind = upper_bound(occ[t[j]-'a'].begin(), occ[t[j]-'a'].end(), start);
                if(ind == occ[t[j]-'a'].end()) break;
                start = *ind;
            }
            count++;
            i = j-1;
        }
        if(found) cout<<count<<endl;
        else cout<<-1<<endl;
    }
}
//1 1 2 3 2 1