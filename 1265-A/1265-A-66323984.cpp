#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <cstdlib>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char arr[] = {'a', 'b', 'c', '?'};
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        for(int i =0;i<s.length();i++){
            vector<char> taken;
            if(s[i]=='?'){
                if(i>0) taken.push_back(s[i-1]);
                if(i<(s.length()-1)) taken.push_back(s[i+1]);
                for(int j = 0;j<4;j++){
                    bool found = false;
                    for(char k: taken) if(k==arr[j]) found = true;
                    if(!found){
                        s[i] = arr[j];
                        goto next;
                    }
                }
                next:
                continue;
            }
        }
        bool valid = true;
        for(int i = 1;i<s.length();i++){
            if(s[i]==s[i-1]) valid = false;
        }
        if(valid) cout<<s<<endl;
        else cout<<-1<<endl;
    }
}