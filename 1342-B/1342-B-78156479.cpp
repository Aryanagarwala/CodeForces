#include <bits/stdc++.h>
#define int long long
#define INF 1000000000000
using namespace std;
signed main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        bool diff = false;
        for(int i = 1;i<s.length();i++){
            if(s[i]!=s[i-1]) diff = true;
        }
        if(!diff){
            cout<<s<<endl;
            continue;
        }
        for(int i = 0;i<s.length();i++){
            cout<<"10";
        }
        cout<<endl;
    }
}