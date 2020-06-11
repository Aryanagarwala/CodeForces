#include <bits/stdc++.h>
#define INF 10000000000000000
#define MOD 1000000017
#define mid(l, u) ((l+u)/2)
#define rchild(i) (i*2 + 2)
#define lchild(i) (i*2 + 1)
#define rr mt_rand()
#define int long long
int vis[100005];
int p[100005];
using namespace std;
void func(int i, vector<int> &v){
    if(vis[i]==1){
        return;
    }
    vis[i] = 1;
    v.push_back(i);
    func(p[i], v);
    vis[i] = 2;
}
signed main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>p[i];
    bool f = false;
    vector<int> piv;
    for(int i = 1;i<=n;i++){
        if(p[i]==i){
            cout<<"YES"<<endl;
            for(int j = 1;j<=n;j++){
                if(i==j) continue;
                cout<<i<<" "<<j<<endl;
            }
            return 0;
        }
    }
    for(int i = 1;i<=n;i++){
        vis[i] = 0;
        if(p[p[i]]==i){
            f = true;
            piv = {i, p[i]};
            vis[i] = 2;
            vis[p[i]] = 2;
            break;
        }
    }
    if(!f){
        cout<<"NO"<<endl;
        return 0;
    }
    bool odd = false;
    vector<pair<int, int>> e;
    e.push_back({piv[0], piv[1]});
    for(int i = 1;i<=n;i++){
        vector<int> v;
        if(vis[i]!=0) continue;
        func(i, v);
        if(v.size()%2==1){
            odd = true;
            break;
        }
        for(int j = 0;j<v.size();j++){
            e.push_back({v[j], piv[j%2]});
        }
    }
    if(odd){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(pair<int, int> k: e){
        cout<<k.first<<" "<<k.second<<endl;
    }
}
//l, mid(l, r) || l+1, r
//