#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <map>
#define int long long
#define pb push_back
#define mp make_pair
#define ll long long
#define MOD 1000000007
#define mid(l, u) (l+u)/2
#define rchild(i) (i*2)
#define lchild(i) (i*2 + 1)
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        bool zerofound = false;
        int cnteven = 0;
        int sum =0 ;
        for(int i = 0;i<s.length();i++){
            if(s[i]=='0') zerofound = true;
            sum+=(s[i]-'0');
            if((s[i]-'0')%2==0) cnteven++;
        }
        if(zerofound&&(sum%3==0)&&(cnteven>1)) cout<<"red"<<endl;
        else cout<<"cyan"<<endl;
    }
}