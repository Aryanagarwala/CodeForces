#include <iostream>
    #include <queue>
    #include <algorithm>
    #include <cmath>
    #include <map>
    #include <vector>
    #include <set>
    #include <unordered_map>
    #define um unordered_map
    #define mid(l, u) (l+u)/2
    #define rchild(i) (i*2 + 2)
    #define lchild(i) (i*2 + 1)
    #define int long long
    using namespace std;
    int32_t main(){
        string s;
        map<char, int> freq;
        map<string, int> freq1;
        cin>>s;
        int ans = 1;
        for(int i = 0;i<s.length();i++){
            for(char j = 'a';j<='z';j++){
                string s1 = to_string(s[i]) + to_string(j);
                freq1[s1]+=freq[j];
                if(freq1[s1]>ans){
                    //cout<<s1<<" "<<freq1[s1]<<endl;
                }
                ans = max(ans, freq1[s1]);
            }
            freq[s[i]]++;
        }
        for(char i = 'a';i<='z';i++) ans = max(ans, freq[i]);
        cout<<ans<<endl;
        return 0;
    }