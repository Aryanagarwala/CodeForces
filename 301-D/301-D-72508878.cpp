#include <iostream>
#include <vector>
#include <algorithm>
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
#define mid(l, u) ((l+u)/2)
using namespace std;
void fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;

    number = 0;

    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}
const int N = 2e5 + 5;
int arr[N], seg[4*N], ind[N], p[N], ans[N];
vector<int> start[N];
vector<pair<int, int>> q[N];
void build(int l, int u, int i){
    if(l==u){
        seg[i] = arr[l];
        return;
    }
    build(l, mid(l, u), lchild(i));
    build(mid(l, u)+1, u, rchild(i));
    seg[i] = seg[lchild(i)] + seg[rchild(i)];
}
int query(int l, int u, int i, int ll, int uu){
    if(l>=ll && u<=uu) return seg[i];
    if(l>uu || u<ll) return 0;
    return query(l, mid(l, u), lchild(i), ll, uu) + query(mid(l, u)+1, u, rchild(i), ll, uu);
}
void update(int l, int u, int i, int uu, int upval){
    if(l>=uu && u<=uu){
        seg[i]+=upval;
        return;
    }
    if(l>uu || u<uu) return;
    update(l, mid(l, u), lchild(i), uu, upval);
    update(mid(l, u)+1, u, rchild(i), uu, upval);
    seg[i] = seg[lchild(i)] + seg[rchild(i)];
    return;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        cin>>p[i];
        ind[p[i]] = i;
    }
    for(int i = 1;i<=n;i++){
        for(int j = i;j<=n;j+=i){
            int a = ind[i]+1, b = ind[j]+1;
            if(a>b) swap(a, b);
            start[a].push_back(b);
            arr[b]++;
        }
    }
    build(1, n, 0);
    for(int i = 0;i<m;i++){
        int u, v;
        cin>>u>>v;
        q[u].push_back(make_pair(v, i));
    }
    int toremove = 1;
    for(int i = 1;i<=n;i++){
        while (toremove < i) {
            for (int j: start[toremove]) update(1, n, 0, j, -1);
            //cout<<"REMOVING "<<lol[toremove].first<<" "<<lol[toremove].second<<endl;
            toremove++;
        }
        for(pair<int, int> lol: q[i]) {
            //cout<<"QUERY "<<quer[i].first.first<<" "<<quer[i].first.second<<endl;
            ans[lol.second] = query(1, n, 0, i, lol.first);
        }
    }
    for(int i = 0;i<m;i++) cout<<ans[i]<<"\n";
    return 0;
}