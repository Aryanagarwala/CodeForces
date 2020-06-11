#include <bits/stdc++.h>
#define int long long
#define INF 10000000000000000
#define mid(l, u) ((l+u)/2)
#define rchild(i) (i*2 + 2)
#define lchild(i) (i*2 + 1)
const int rlim = 2e5 + 5;
using namespace std;
signed main() {
    string s;
    cin>>s;
    s = "1*" + s + "*1";
    int n = s.length();
    int val[n][n];
    pair<int, int> lol[n];
    pair<int, int> lol1[n];
    for(int i = 0;i<1;i++){
        int cval = 0;
        int ctem = 0;
        bool newterm = true;
        for(int j = i;j<n;j+=2){
            if(newterm) ctem = (s[j] - '0');
            else ctem *= (s[j]-'0');
            val[i][j] = cval + ctem;
            lol[j] = make_pair(cval, ctem);
            //cout<<j<<" "<<cval<<endl;
            if(j+1<n && s[j+1]=='+'){
                newterm = true;
                cval+=ctem;
                ctem = 0;
            }
            else{
                newterm = false;
            }
        }
    }
    for(int i = n-1;i>=n-1;i--){
        int cval = 0;
        int ctem = 0;
        bool newterm = true;
        for(int j = i;j>=0;j-=2){
            if(newterm) ctem = (s[j] - '0');
            else ctem *= (s[j]-'0');
            val[i][j] = cval + ctem;
            lol1[j] = make_pair(cval, ctem);
            if(j-1>=0 && s[j-1]=='+'){
                newterm = true;
                cval+=ctem;
                ctem = 0;
            }
            else{
                newterm = false;
            }
        }
    }
    for(int i = 0;i<n;i+=2){
        int cval = 0;
        int ctem = 0;
        bool newterm = true;
        for(int j = i;j<n;j+=2){
            if(newterm) ctem = (s[j] - '0');
            else ctem *= (s[j]-'0');
            val[i][j] = cval + ctem;
            if(j+1<n && s[j+1]=='+'){
                newterm = true;
                cval+=ctem;
                ctem = 0;
            }
            else{
                newterm = false;
            }
        }
    }
    int ans = val[0][n-1];
    for(int i = 2;i<(n-1);i+=2){
        for(int j = i+2;j<(n-1);j+=2){
            if(s[i-1]!='*' || s[j+1]!='*') continue;
            int term = val[i][j];
            int pt = val[i-2][i-2];
            int ppt = val[j+2][j+2];
            int pppt = (i-4)>=0?(val[0][i-4]):0;
            int ppppt = (j+4)<n?val[j+4][n-1]:0;
            char sb = (i-3)>=0?s[i-3]:'+';
            char sbb = (j+3)<n?s[j+3]:'+';
            int temp = term*lol[i-2].second*lol1[j+2].second + lol[i-2].first + lol1[j+2].first;
            //cout<<i<<" "<<j<<" "<<temp<<endl;
            //cout<<lol[i-2].second<<" "<<lol1[j+2].second<<" "<<lol[i-2].first<<" "<<lol1[j+2].first<<endl;
            ans = max(ans, temp);
        }
    }
    cout<<ans<<endl;
}
//1*9*8+7*6+5*4+3*2+1*1