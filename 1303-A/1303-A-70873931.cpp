#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#define int long long
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int mini = s.length() + 5, maxi = -1;
        for(int i = 0;i<s.length();i++){
            if(s[i]=='0') continue;
            mini = min(i, mini);
            maxi = max(maxi, i);
        }
        int count = 0;
        for(int i = mini;i<=maxi && i<s.length();i++){
            if(s[i]=='0') count++;
        }
        cout<<count<<endl;
    }
}