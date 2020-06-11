#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.length();
        unordered_map<char, bool> mp;
        for(int i = 0;i<n;i++){
            int j = i+1;
            while(j<n && s[j]==s[i]) j++;
            int count = j-i;
            if(count%2) mp[s[i]] = true;
            i = j - 1;
        }
        string ans = "";
        for(char i = 'a';i<='z';i++){
            if(mp[i]) ans+=i;
        }
        cout<<ans<<endl;
    }
}