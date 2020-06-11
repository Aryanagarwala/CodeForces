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
const int N = 1e5;
struct node{
    int val, big, bigf, sbig, sbigf;
};
node seg[4*N];
int lazy[4*N];
node merge(node a, node b){
    node tr;
    if(a.big>b.big){
        tr.big = a.big;
        tr.bigf = a.bigf;
        if(a.sbig>b.big){
            tr.sbig = a.sbig;
            tr.sbigf = a.sbigf;
        }
        else if(b.big>a.sbig){
            tr.sbig = b.big;
            tr.sbigf = b.bigf;
        }
        else{
            tr.sbig = b.big;
            tr.sbigf = b.bigf + a.sbigf;
        }
    }
    else if(b.big>a.big){
        tr.big = b.big;
        tr.bigf = b.bigf;
        if(b.sbig>a.big){
            tr.sbig = b.sbig;
            tr.sbigf = b.sbigf;
        }
        else if(a.big>b.sbig){
            tr.sbig = a.big;
            tr.sbigf = a.bigf;
        }
        else{
            tr.sbig = a.big;
            tr.sbigf = a.bigf + b.sbigf;
        }
    }
    else{
        tr.big = b.big;
        tr.bigf = b.bigf + a.bigf;
        if(b.sbig>a.sbig){
            tr.sbig = b.sbig;
            tr.sbigf = b.sbigf;
        }
        else if(a.sbig>b.sbig){
            tr.sbig = a.sbig;
            tr.sbigf = a.sbigf;
        }
        else{
            tr.sbig = a.sbig;
            tr.sbigf = a.sbigf + b.sbigf;
        }
    }
    tr.val = a.val + b.val;
    return tr;
}
void laz(int l, int u, int i){
    if(lazy[i]==-1) return;
    if((seg[i].big<lazy[i])){
        lazy[i] = -1;
        return;
    }
    if(l!=u){
        lazy[lchild(i)] = lazy[rchild(i)] = lazy[i];
    }
    seg[i].val -= ((seg[i].bigf)*seg[i].big);
    seg[i].big = lazy[i];
    seg[i].val += ((seg[i].bigf)*seg[i].big);
    //cout<<l<<" "<<u<<" "<<seg[i].val<<" "<<lazy[i]<<endl;
    if(seg[i].big==0 && seg[i].sbig==0){
        seg[i].bigf+=seg[i].sbigf;
        seg[i].sbigf = 0;
    }
    lazy[i] = -1;
}
void build(int l ,int u, int i, int arr[]){
    lazy[i] = -1;
    if(l==u){
        seg[i] = {arr[l-1], arr[l-1], 1, 0, 0};
        return;
    }
    build(l, mid(l, u), lchild(i), arr);
    build(mid(l, u)+1, u, rchild(i), arr);
    seg[i] = merge(seg[lchild(i)], seg[rchild(i)]);
    //cout<<l<<" "<<u<<" "<<seg[i].val<<" "<<seg[i].big<<" "<<seg[i].bigf<<" "<<seg[i].sbig<<" "<<seg[i].sbigf<<endl;
}
int query(int l, int u, int i, int ll, int uu){
    laz(l, u, i);
    if(l>=ll && u<=uu) return seg[i].val;
    if(l>uu || u<ll) return 0;
    return query(l, mid(l, u), lchild(i), ll, uu) + query(mid(l, u)+1, u, rchild(i), ll, uu);
}
void upmod(int l, int u, int i, int ll, int uu, int x){
    laz(l, u, i);
    if(l>=ll && u<=uu && (((seg[i].big%x)>seg[i].sbig) || seg[i].sbig==0)){
        lazy[i] = seg[i].big%x;
        laz(l, u, i);
        return;
    }
    if(l>uu || u<ll) return;
    upmod(l, mid(l, u), lchild(i), ll, uu, x);
    upmod(mid(l, u)+1, u, rchild(i), ll, uu, x);
    seg[i] = merge(seg[lchild(i)], seg[rchild(i)]);
}
void updval(int l ,int u, int i, int uu, int upval){
    laz(l, u, i);
    if(l>=uu && u<=uu){
        seg[i] = {upval, upval, 1, 0, 0};
        return;
    }
    if(l>uu || u<uu) return;
    updval(l, mid(l, u), lchild(i), uu, upval);
    updval(mid(l, u)+1, u, rchild(i), uu, upval);
    seg[i] = merge(seg[lchild(i)], seg[rchild(i)]);
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin>>n>>m;
    int arr[n];
    for(int i = 0;i<n;i++) cin>>arr[i];
    build(1, n, 0, arr);
    //cout<<"HEY"<<endl;
    while(m--){
        int t;
        cin>>t;
        if(t==1){
            int l, r;
            cin>>l>>r;
            cout<<query(1, n, 0, l, r)<<endl;
        }
        else if(t==2){
            int l, r, x;
            cin>>l>>r>>x;
            upmod(1, n, 0, l, r, x);
        }
        else{
            int uu, x;
            cin>>uu>>x;
            updval(1, n, 0, uu, x);
        }
    }
}