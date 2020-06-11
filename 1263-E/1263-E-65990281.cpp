#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#define int long long
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
#define mid(l, u) ((l+u)/2)
#define INF (100000000)
using namespace std;
int query(int l, int u, int i, int tl, int tu, int segtree[], int lazy[], int segtreemax[], int lazymax[]){
    if(lazy[i]){
        segtree[i]+=lazy[i];
        if(l!=u){
            lazy[lchild(i)] += lazy[i];
            lazy[rchild(i)] += lazy[i];
        }
        lazy[i] = 0;
    }
    if(lazymax[i]){
        segtreemax[i]+=lazymax[i];
        if(l!=u){
            lazymax[lchild(i)] += lazymax[i];
            lazymax[rchild(i)] += lazymax[i];
        }
        lazymax[i] = 0;
    }
    if(l>=tl && u<=tu) return segtree[i];
    if(l>tu || u<tl) return INF;
    segtree[i] = min(query(l, mid(l, u), lchild(i), tl, tu, segtree, lazy, segtreemax, lazymax), query(mid(l, u)+1, u, rchild(i), tl, tu, segtree, lazy, segtreemax, lazymax));
    segtreemax[i] = max(segtreemax[lchild(i)], segtreemax[rchild(i)]);
}
void update(int l, int u, int i, int tl, int tu, int updt, int segtree[], int lazy[], int segtreemax[], int lazymax[]){
    //cout<<"UPDATING "<<l<<" "<<u<<" "<<i<<" "<<tl<<" "<<tu<<endl;
    if(lazy[i]){
        segtree[i]+=lazy[i];
        if(l!=u){
            lazy[lchild(i)] += lazy[i];
            lazy[rchild(i)] += lazy[i];
        }
        lazy[i] = 0;
    }
    if(lazymax[i]){
        segtreemax[i]+=lazymax[i];
        if(l!=u){
            lazymax[lchild(i)] += lazymax[i];
            lazymax[rchild(i)] += lazymax[i];
        }
        lazymax[i] = 0;
    }
    if(l>=tl && u<=tu){
        segtree[i]+=updt;
        segtreemax[i]+=updt;
        if(l!=u){
            lazy[lchild(i)] += updt;
            lazy[rchild(i)] += updt;
            lazymax[lchild(i)] += updt;
            lazymax[rchild(i)] += updt;
        }
        //cout<<l<<" CHANGING "<<u<<" "<<segtree[i]<<" "<<updt<<endl;
        return;
    }
    if(l>tu || u<tl) return;
    update(l, mid(l, u), lchild(i), tl, tu, updt, segtree, lazy, segtreemax, lazymax);
    update(mid(l, u)+1, u, rchild(i), tl, tu, updt, segtree, lazy, segtreemax, lazymax);
    segtree[i] = min(segtree[lchild(i)], segtree[rchild(i)]);
    segtreemax[i] = max(segtreemax[lchild(i)], segtreemax[rchild(i)]);
    //cout<<l<<" "<<u<<" "<<segtree[i]<<endl;
}
int32_t main(){
    int n;
    cin>>n;
    int size = pow(2, ceil(log2(n))+1);
    int lazy[size];
    int lazymax[size];
    int arr[n];
    int segtree[size];
    int segtreemax[size];
    for(int i = 0;i<size;i++){
        lazy[i]=segtree[i]=segtreemax[i]=lazymax[i]=0;
    }
    for(int i = 0;i<n;i++){
        arr[i] = 0;
    }
    string s;
    cin>>s;
    int pos = 0;
    int sum = 0;
    unordered_map<char, int> mp;
    mp['('] = 1;
    mp[')'] = -1;
    int diff;
    bool possible;
    for(char i = 'a';i<='z';i++){
        mp[i] = 0;
    }
    for(int i =0 ;i<n;i++){
        if(s[i]=='L'){
            pos = max((int)0, pos-1);
            goto end;
        }
        if(s[i]=='R'){
            pos++;
            goto end;
        }
        diff = mp[s[i]] - arr[pos];
        sum+=diff;
        arr[pos] = mp[s[i]];
        update(0, n-1, 0, pos, n-1, diff, segtree, lazy, segtreemax, lazymax);
        end:
        //cout<<"STATUS "<<query(0, n-1, 0, 0, n-1, segtree, lazy)<<endl;
        possible = (query(0, n-1, 0, 0, n-1, segtree, lazy, segtreemax, lazymax)>=0);
        possible = possible && (sum==0);
        if(possible) cout<<segtreemax[0]<<" ";
        else cout<<-1<<" ";
    }
    cout<<endl;
}