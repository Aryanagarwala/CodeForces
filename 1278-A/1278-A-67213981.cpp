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
    using namespace std;
int freq[26];
int cnt[26];
bool check(){
    bool tr = true;
    for(int i =0;i<26;i++){
        if(freq[i]!=cnt[i]) tr = false;
    }
    return tr;
}
    int32_t main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int t;
        cin>>t;
        while(t--){
            string p, h;
            cin>>p>>h;
            for(int i = 0;i<26;i++) cnt[i] = freq[i] = 0;
            for(int i =0 ;i<p.length();i++){
                freq[p[i]-'a']++;
            }
            for(int i =0 ;i<p.length() && i<h.length();i++){
                cnt[h[i]-'a']++;
            }
            bool found = check();
            for(int i = p.length();i<h.length() && !found;i++){
                cnt[h[i]-'a']++;
                cnt[h[i-p.length()]-'a']--;
                found = check();
            }
            cout<<(found?"YES":"NO")<<endl;
        }
    }