#include <bits/stdc++.h>
#define INF 10000000000000000
#define MOD 1000000017
#define mid(l, u) ((l+u)/2)
#define rchild(i) (i*2 + 2)
#define lchild(i) (i*2 + 1)
#define int long long
using namespace std;
int seg[10][100000];
int query(int i, int j, int l, int u, int ll, int uu){
    if(l>=ll && u<=uu) return seg[i][j];
    if(l>uu || u<ll) return 0;
    return query(i, lchild(j), l, mid(l, u), ll, uu) + query(i, rchild(j), mid(l, u)+1, u, ll, uu);
}
int update(int i, int j, int l, int u, int ll, int val){
    if(l>=ll && u<=ll) return seg[i][j] = val;
    if(l>ll || u<ll) return seg[i][j];
    return seg[i][j] = update(i, lchild(j), l, mid(l, u), ll, val) + update(i, rchild(j), mid(l, u)+1, u, ll, val);
}
signed main(){
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<char> c;
    for(int i = 0;i<s.length();i++) c.push_back(s[i]);
    sort(c.begin(), c.end());
    int count = 0;
    int weight = 0;
    bool taken = false;
    char prev = 'a';
    int ind = 0;
    while(ind<c.size() && count<k){
        if(taken){
            if((c[ind]-prev)<=1){
                ind++;
                continue;
            }
        }
        taken = true;
        prev = c[ind];
        weight+=(c[ind] - 'a' + 1);
        ind++;
        count++;
    }
    if(count<k) cout<<-1<<endl;
    else cout<<weight<<endl;

}
//l, mid(l, r) || l+1, r
//