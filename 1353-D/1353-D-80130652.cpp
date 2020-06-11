#include <iostream>
#include <vector>
#include <queue>
#define int long long
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
#define mid(l, u) ((l+u)/2)
using namespace std;
pair<int, int> seg[800005];
int lazy[800005], n;
pair<int, int> merge(pair<int, int> a, pair<int, int> b){
    if(a.first>b.first) return a;
    if(b.first>a.first) return b;
    if(a.second<b.second) return a;
    return b;
}
pair<int, int> build(int l, int u, int i){
    lazy[i] = 0;
    if(l==u){
        return seg[i] = make_pair(n-l+1, l);
    }
    return seg[i] = merge(build(l, mid(l, u), lchild(i)), build(mid(l, u)+1, u, rchild(i)));
}
pair<int, int> query(){
    return seg[0];
}
void update(int l, int u, int i, int ll, int uu, int upval){
    if(lazy[i]){
        seg[i].first-=lazy[i];
        if(l!=u){
            lazy[lchild(i)]+=lazy[i];
            lazy[rchild(i)  ]+=lazy[i];
        }
        lazy[i] = 0;
    }
    if(l>=ll && u<=uu){
        seg[i].first -= upval;
        if(l!=u){
            lazy[lchild(i)] += upval;
            lazy[rchild(i)] += upval;
        }
        return;
    }
    if(l>uu || u<ll) return;
    update(l, mid(l, u), lchild(i), ll, uu, upval);
    update(mid(l, u)+1, u, rchild(i), ll, uu, upval);
    seg[i] = merge(seg[lchild(i)], seg[rchild(i)]);
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n+1];
        build(1, n, 0);
        for(int i = 1;i<=n;i++){
            pair<int, int> q = query();
            //cout<<"ROUND "<<i<<" "<<q.first<<" "<<q.second<<endl;
            int ind;
            if(q.first%2==0){
                ind = ((q.second + (q.second+q.first-1) - 1)/2);
            }
            else{
                ind = ((q.second + (q.second+q.first-1))/2);
            }
            //cout<<"IND: "<<ind<<endl;
            arr[ind] = i;
            update(1, n, 0, q.second, ind, q.second+q.first - ind);
        }
        for(int i = 1;i<=n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}
//b k
//1 3
//