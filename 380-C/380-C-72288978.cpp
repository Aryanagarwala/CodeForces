#include <iostream>
#define mid(l, u) ((l+u)/2)
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
using namespace std;
int MOD = 1e9 + 7;
string s;
struct node{
    int a, b, c;
};
node seg[4000000];
void build(int l, int u, int i){
    if(l==u){
        seg[i] = {0, ((s[l-1]=='(')?1:0), ((s[l-1]==')')?1:0)};
        return;
    }
    build(l, mid(l, u), lchild(i));
    build(mid(l, u)+1, u, rchild(i));
    int toadd = min(seg[lchild(i)].b, seg[rchild(i)].c);
    seg[i] = {seg[lchild(i)].a + seg[rchild(i)].a + (toadd*2), seg[lchild(i)].b + seg[rchild(i)].b - toadd, seg[lchild(i)].c + seg[rchild(i)].c - toadd};
}
node query(int l, int u, int i, int ll, int uu){
    if(l>=ll && u<=uu){
        return seg[i];
    }
    if(l>uu || u<ll) return {0, 0, 0};
    node lq = query(l, mid(l, u), lchild(i), ll, uu), rq = query(mid(l, u)+1, u, rchild(i), ll, uu);
    int toadd = min(lq.b, rq.c);
    return {lq.a + rq.a + (toadd*2), lq.b + rq.b - toadd, lq.c + rq.c - toadd};
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>s;
    build(1, s.length(), 0);
    int q;
    cin>>q;
    while(q--){
        int l, u;
        cin>>l>>u;
        cout<<(query(1, s.length(), 0, l, u).a)<<endl;
    }
    return 0;
}