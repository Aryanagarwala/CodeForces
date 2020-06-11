#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <fstream>
#include <algorithm>
#include <set>
#define INF 10000000000000000
#define MOD 1000000007
#define mid(l, u) ((l+u)/2)
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
#define int long long
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        string final = "";
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if((s[i]-'0')%2==0) continue;
            if(cnt>=2) continue;
            cnt++;
            final+=s[i];
        }
        if(cnt<2){
            cout<<-1<<endl;
            continue;
        }
        cout<<final<<endl;
    }
}
//1 1 2 3 2 1