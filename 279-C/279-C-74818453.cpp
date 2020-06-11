#include <bits/stdc++.h>
#define int long long
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
#define mid(l, u) ((l+u)/2)
#define MOD 1000000007
using namespace std;
const int N = 100000;
int seg[4*N];
int arr[N];
//1->inc
//2->dec
//3->eq
//4->ind,dec
//5->non ladder
int merge(int a, int b, int l1, int r1, int l2, int r2){
    //cout<<"merge "<<a<<" "<<b<<" "<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
    if(a==5 || b==5) return 5;
    if(a==3 && b==3 && arr[r1]==arr[l2]) return 3;
    if((a==2||a==3) && (b==2||b==3) && arr[r1]>=arr[l2]) return 2;
    if((a==1||a==3) && (b==1||b==3) && arr[r1]<=arr[l2]) return 1;
    if((a==1||a==3) && b==4 && arr[r1]<=arr[l2]) return 4;
    if(a==4 && (b==2||b==3) && arr[r1]>=arr[l2]) return 4;
    if(a==1 && b==3 && arr[l2]<arr[r1]) return 4;
    if(a==3 && b==2 && arr[l2]>arr[r1]) return 4;
    if(a==1 && b==2) return 4;
    return 5;
}
int build(int l, int u, int i){
    if(l==u){
        return seg[i] = 3;
    }
    return seg[i] = merge(build(l, mid(l, u), lchild(i)),  build(mid(l, u)+1, u, rchild(i)), l, mid(l, u), mid(l, u)+1, u);
}
int query(int l, int u, int i, int ll, int uu){
    if(l>=ll && u<=uu) return seg[i];
    if(ll>u || l>uu) return -1;
    if(uu<=mid(l, u)) return query(l, mid(l, u), lchild(i), ll, uu);
    if(ll>mid(l, u)) return query(mid(l, u)+1, u, rchild(i), ll, uu);
    return merge(query(l, mid(l, u), lchild(i), ll, uu), query(mid(l, u)+1, u, rchild(i), ll, uu), -5, mid(l, u), mid(l, u)+1, -5);
}
signed main(){
    int n, m;
    cin>>n>>m;
    for(int i = 0;i<n;i++) cin>>arr[i];
    build(0, n-1, 0);
    while(m--){
        int l, r;
        cin>>l>>r;
        int ans = query(0, n-1, 0, l-1, r-1);
        //cout<<ans<<endl;
        if(ans==5){
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
    }
    return 0;
}