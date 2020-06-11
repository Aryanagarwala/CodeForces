#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <iomanip>
#include <cmath>
#include <vector>
#define int long long
#define double long double
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int ind = 0;
        string s[2];
        cin>>s[0]>>s[1];
        unordered_map<char, int> freq;
        vector<pair<int, int>> ans;
        for(int i =0 ;i<n;i++){
            freq[s[0][i]]++;
            freq[s[1][i]]++;
        }
        for(char i = 'a';i<='z';i++){
            if(freq[i]%2!=0){
                goto no;
            }
        }
        cout<<"Yes"<<endl;
        for(int i = 0;i<n;i++){
            if(s[0][i]==s[1][i]) continue;
            for(int j = i+1;j<n;j++){
                if(s[0][i]==s[0][j]){
                    ans.push_back(make_pair(j, i));
                    s[0][j] = s[1][i];
                    s[1][i] = s[0][i];
                    goto end;
                }
                else if(s[0][i] == s[1][j]){
                    ans.push_back(make_pair(i+1, j));
                    s[1][j] = s[0][i+1];
                    s[0][i+1] = s[0][i];
                    ans.push_back(make_pair(i+1, i));
                    s[0][i+1] = s[1][i];
                    s[1][i] = s[0][i];
                    goto end;
                }
            }
            end:
            continue;
        }
        cout<<ans.size()<<endl;
        for(pair<int, int> lol: ans){
            cout<<(lol.first+1)<<" "<<(lol.second+1)<<endl;
        }
        continue;
        no:
        cout<<"No"<<endl;
        continue;
    }
}
//89
//69
//83