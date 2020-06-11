#include <iostream>
#include <algorithm>
#define MOD ((long long)1e9 + 7)
using namespace std;
int n;
int main(){
    string s;
    cin>>s;
    n = s.length();
    long long DP[n];
    DP[0] = 1;
    for(int i = 0;i<n;i++){
        if(s[i]=='w' || s[i]=='m'){
            cout<<0<<endl;
            return 0;
        }
    }
    for(int i = 1;i<n;i++){
        if((s[i]=='n' && s[i-1]=='n')||(s[i]=='u' && s[i-1]=='u')){
            if(i>1){
                DP[i] = DP[i-2] + DP[i-1];
            }
            else{
                DP[i] = 2;
            }
        }
        else{
            DP[i] = DP[i-1];
        }
        DP[i]%=MOD;
    }
    cout<<DP[n-1]<<endl;
}