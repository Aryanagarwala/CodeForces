#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> even, odd;
        int cnt[] = {0, 0};
        for(int i = 0;i<n;i++){
            string s;
            cin>>s;
            for(int j = 0;j<s.length();j++){
                cnt[s[j]-'0']++;
            }
            if(s.length()%2) odd.push_back(s.length());
            else even.push_back(s.length());
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        int ans = 0;
        for(int j: even){
            int takefrom0 = (cnt[0]/2)*2;
            int takefrom1 = j - takefrom0;
            if(cnt[1]>=takefrom1 && cnt[0]>=takefrom0 && (takefrom0+takefrom1)==j){
                cnt[1]-=takefrom1;
                cnt[0]-=takefrom0;
                ans++;
            }
        }
        for(int j: odd){
            ans++;
        }
        cout<<ans<<endl;
    }
}