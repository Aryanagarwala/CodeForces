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
string reverse(string a){
    string t = "";
    for(int i = a.length()-1;i>=0;i--){
        t+=a[i];
    }
    return t;
}
int valid(int c00, int c11, int c01, int c10){
    if((c10 - c01)>1) return 0;
    if((c01 - c10)>1) return 1;
    return 2;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s[n];
        unordered_map<string, bool> cnt;
        int end[] = {0, 0};
        int start[] = {0, 0};
        char lol[] = {'0', '1'};
        bool rev[n];
        int c11 = 0, c00 = 0, c01 = 0, c10 = 0;
        for(int i =0 ;i<n;i++){
            cin>>s[i];
            int beg = 0;
            int end = s[i].length()-1;
            if(s[i][beg]=='0'){
                if(s[i][end]=='1') c01++;
                else c00++;
            }
            else{
                if(s[i][end]=='0') c10++;
                else c11++;
            }
            cnt[s[i]] = true;
            rev[i] = false;
        }
        //cout<<c01<<" "<<c10<<" "<<c11<<" "<<c00<<endl;
        if((c00&&c11) && !(c01||c10)){
            cout<<-1<<endl;
            continue;
        }
        vector<int> ans;
        int sd;
        for(int i = 0;i<n && ((sd = valid(c00, c11, c01, c10))!=2);i++){
            if(s[i][0]==lol[sd^1] && s[i][s[i].length()-1]==lol[sd]){
                if(!cnt[reverse(s[i])]){
                    ans.push_back(i+1);
                    if(sd==0){
                        c01++;
                        c10--;
                    }
                    else{
                        c10++;
                        c01--;
                    }
                }
            }
        }
        if(valid(c00, c11, c01, c10)!=2){
            cout<<-1<<endl;
            continue;
        }
        cout<<ans.size()<<endl;
        for(int i: ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}