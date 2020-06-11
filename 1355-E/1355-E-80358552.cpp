#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define int long long
#define lchild(i) (i*2 + 1)
#define INF 1000000000000000000
#define rchild(i) (i*2 + 2)
#define mid(l, u) ((l+u)/2)
using namespace std;
int n, a, r, m;
int pref[100005];
int h[100005];
int f(int x){
    auto it = upper_bound(h+1, h+n+1, x);
    int smol = it - (h);
    if(smol>n){
        smol = -1;
    }
    else smol--;
    int lastless = (lower_bound(h+1, h+n+1, x) - h) - 1;
    if(lastless<1){
        lastless = -1;
    }
    int add = 0, remove = 0;
    if(lastless!=-1){
        add = (((lastless)*x) - pref[lastless]);
    }
    if(smol!=-1){
        remove = (pref[n] - pref[smol]) - ((n-smol)*x);
    }
    int cost = min(add, remove)*m;
    int tr = min(add, remove);
    add-=tr;
    remove-=tr;
    cost+=a*add;
    cost+=r*remove;
    return cost;
}
signed main(){
    cin>>n>>a>>r>>m;
    for(int i = 1;i<=n;i++){
        cin>>h[i];
    }
    m = min(m, a+r);
    sort(h+1, h+n+1);
    pref[0] = 0;
    for(int i = 1;i<=n;i++){
        pref[i] = h[i] + pref[i-1];
    }
    int mincost = INF;
    for(int i = 1;i<=n;i++){
        mincost = min(mincost, f(h[i]));
    }
    int final = pref[n]/n;
    mincost = min(mincost, f(final+1));
    mincost = min(mincost, f(final));
    cout<<mincost<<endl;
}
//b k
//1 3
//