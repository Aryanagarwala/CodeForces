#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mid(l, u) ((l+u)/2)
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
#define int long long
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int count = 0;
    vector<int> ans;
    int currind = 0;
    queue<int> o, c;
    for(int i =0 ;i<s.length();i++){
        if(s[i]=='(') o.push(i+1);
    }
    for(int i = s.length()-1;i>=0;i--){
        if(s[i]==')') c.push(i+1);
    }
    while(!o.empty() && !c.empty() && o.front()<c.front()){
        ans.push_back(o.front());
        ans.push_back(c.front());
        o.pop();
        c.pop();
        count+=2;
        currind++;
    }
    if(currind==0){
        cout<<0<<endl;
        return 0;
    }
    cout<<1<<endl;
    cout<<count<<endl;
    sort(ans.begin(), ans.end());
    for(int j: ans) cout<<j<<" ";
    cout<<endl;
    return 0;
}