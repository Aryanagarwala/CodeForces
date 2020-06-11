#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <map>
#define MOD 1000000007
#define mid(l, u) ((l+u)/2)
#define int long long
#define double long double
#define child(i) (i*2 + 1)
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.length();
        vector<int> ans;
        int cnt = 0;
        for(int i =0;i<(n-2);i++){
            string t = "";
            for(int j = i;j<=(i+2);j++) t+= s[j];
            string k = "";
            if(i<(n-4)){
                for(int l = i;l<=(i+4);l++) k+= s[l];
            }
            if(k=="twone"){
                ans.push_back(i+3);
                s[i+2] = 'x';
            }
            else if(t=="one"){
                ans.push_back(i+2);
                s[i+1] = 'x';
            }
            else if(t=="two"){
                ans.push_back(i+2);
                s[i+1] = 'x';
            }
            else{
                //cout<<t<<endl;
            }
        }
        cout<<ans.size()<<endl;
        for(int j: ans) cout<<j<<" ";
        cout<<endl;
    }
}