#include <bits/stdc++.h>
#define INF 10000000000000000
#define MOD 1000000017
#define mid(l, u) ((l+u)/2)
#define rchild(i) (i*2 + 2)
#define lchild(i) (i*2 + 1)
#define rr mt_rand()
#define int long long
using namespace std;
int cnt = 0;
bool inp(int l, int u){
    cout<<l<<" "<<u<<endl;
    string s;
    cin>>s;
    if(s=="Yes") return true;
    return false;
}
signed main(){
    mt19937 mt_rand(time(0));
    int n, k;
    cin>>n>>k;
    int l = 1;
    int u = n;
    int r;
    bool cont = true;
    while(cont) {
        while ((u - l + 1) > max((int)1, (4 * k))) {
            int m = min(u, mid(l, u) + 1);
            if (inp(m, u)) {
                if(m==u){
                    cont = false;
                    goto end;
                }
                l = m;
            } else {
                u = m - 1;
            }
            l-=k;
            l = max(l, (int)1);
            u+=k;
            u = min(u, n);
        }
        r = rr%(u-l+1);
        if(inp(l+r, l+r)){
            cont = false;
            goto end;
        }
        else{
            l-=k;
            l = max(l, (int)1);
            u+=k;
            u = min(u, n);
        }
    }
    end:
    return 0;
}
//l, mid(l, r) || l+1, r
//