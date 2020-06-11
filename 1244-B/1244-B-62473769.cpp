#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v;
        int count = 0;
        string s;
        cin>>s;
        for(int i =0;i<s.length();i++){
            if(s[i]=='1'){
                v.push_back(i);
                count++;
            }
        }
        int ans = n + count;
        int ans1 = -10000;
        if(v.size()){
            ans1 = max((v[v.size()-1]+1)*2, (n - v[0])*2);
        }
        cout<<max(ans, ans1)<<endl;
    }
    return 0;
}