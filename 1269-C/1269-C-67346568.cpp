#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <fstream>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <map>
#define int long long
using namespace std;
int n, k;
bool big(string s, string s1){
    bool big = false;
    for(int i = 0;i<n;i++){
        if(s1[i]>s[i]) big = true;
        if(s1[i]<s[i] && !big) return false;
    }
    return true;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    string s;
    cin>>s;
    string s1 = s.substr(0, k);
    for(int i = k;i<n;i++){
        s1+=s1[i-k];
    }
    if(big(s, s1)){
        cout<<n<<endl;
        cout<<s1<<endl;
        return 0;
    }
    int ind = k-1;
    while(ind>0 && s[ind]=='9'){
        s[ind] = '0';
        ind--;
    }
    s[ind] = s[ind]+1;
    for(int i = k;i<n;i++){
        s[i] = s[i-k];
    }
    cout<<n<<endl;
    cout<<s<<endl;
}
/*
 1 3
2 11
4 8
5 7
6 10
9 12
 */