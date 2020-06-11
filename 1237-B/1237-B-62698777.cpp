#include <iostream>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#define mid(l, r) ((l+r)/2)
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
using namespace std;
void build(int l, int r, int i, int segtree[]){
    if(l==r) segtree[i] = 0;
    else{
        build(l, mid(l, r), lchild(i), segtree);
        build(mid(l, r)+1, r, rchild(i), segtree);
        segtree[i] = 0;
    }
}
int query(int l, int r, int i, int tl, int tr, int segtree[]){
    if(l>=tl&&r<=tr) return segtree[i];
    if(l>tr || r<tl) return 0;
    return query(mid(l, r)+1, r, rchild(i), tl, tr, segtree) + query(l, mid(l, r), lchild(i), tl, tr, segtree);
}
int update(int l, int r, int i, int ti, int segtree[]){
    if(l>=ti && r<=ti) return segtree[i] = 1;
    if(l>ti || r<ti) return segtree[i];
    return segtree[i] = update(mid(l, r)+1, r, rchild(i), ti, segtree) + update(l, mid(l, r), lchild(i), ti, segtree);
}
int main() {
    int n;
    cin>>n;
    long a[n];
    unordered_map<int, int> id;
    for(int i = 0;i<n;i++){
        cin>>a[i];
        id[a[i]] = i;
    }
    int segtree[(int) (pow(2, ceil(log2(n)))*2 - 1)];
    build(0, n-1, 0, segtree);
    int count = 0;
    for(int i = 0;i<n;i++){
        int num;
        cin>>num;
        int alreadydone = query(0, n-1, 0, 0, id[num], segtree);
        if(alreadydone!=id[num]) count++;
        update(0, n-1, 0, id[num], segtree);
    }
    cout<<count<<endl;
}