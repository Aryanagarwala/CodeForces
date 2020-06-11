#include <iostream>
#include <algorithm>
using namespace std;
int32_t main(){
    int n;
    cin>>n;
    string names[n];
    for(int i = 0;i<n;i++) cin>>names[i];
    int status[26][26];
    bool taken[26];
    for(int i =0 ;i<26;i++){
        for(int j = 0;j<26;j++){
            status[i][j] = 0;
            taken[i] = false;
        }
    }
    for(int i = 1;i<n;i++){
        for(int j = 0;j<i;j++){
            int diff = -1;
            for(int k = 0;k<names[i].length() && k<names[j].length();k++){
                if(names[i][k]!=names[j][k]){
                    diff = k;
                    goto done;
                }
            }
            done:
            if(diff==-1){
                if(names[j].length()>names[i].length()){
                    cout<<"Impossible"<<endl;
                    return 0;
                }
                continue;
            }
            else{
                 if(status[names[i][diff]-'a'][names[j][diff] - 'a']==1){
                     cout<<"Impossible"<<endl;
                     return 0;
                 }
                status[names[i][diff]-'a'][names[j][diff] - 'a']=2;
                status[names[j][diff]-'a'][names[i][diff] - 'a']=1;
                for(int k = 0;k<26;k++){
                    if(status[names[j][diff]-'a'][k] == 2){
                        if(status[names[i][diff]-'a'][k]==1){
                            cout<<"Impossible"<<endl;
                            return 0;
                        }
                        status[names[i][diff]-'a'][k]=2;
                        status[k][names[i][diff]-'a']=1;
                    }
                }
            }
        }
    }
    char rank[26]; int current = 25;
    while(current>=0) {
        for (int i = 0; i < 26; i++) {
            if(taken[i]) continue;
            bool valid = true;
            for (int j = 0; j < 26; j++) {
                if (taken[j] || j==i) continue;
                if(status[i][j]==1) valid = false;
            }
            if(valid){
                taken[i] = true;
                rank[current--] = (char)('a' + i);
                goto here;
            }
        }
        here:
        continue;
    }
    for(int i = 0;i<26;i++) cout<<rank[i];
    cout<<endl;
}