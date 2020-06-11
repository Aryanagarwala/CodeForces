#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#define int long long
#define double long double
#define mid(l, u) ((l+u)/2)
#define lchild(i) (i*2+  1)
#define rchild(i) (i*2 + 2)
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(s[i]=='P') continue;
            int j = i+1;
            for(;j<n && s[j]=='P';j++);
            int count = j - (i+1);
            ans = max(ans, count);
        }
        cout<<ans<<endl;
    }
}
//2 1

//3 10
//0 4 7
/*
 1 3
2 11
4 8
5 7
6 10
9 12
 */