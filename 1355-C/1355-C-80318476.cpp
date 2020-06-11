#include <iostream>
#include <vector>
#include <queue>
#define int long long
#define lchild(i) (i*2 + 1)
#define INF 1000000000000000000
#define rchild(i) (i*2 + 2)
#define mid(l, u) ((l+u)/2)
using namespace std;
signed main(){
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    int pref[500005];
    int smalldiff = 1;
    int maxdiff = d-b+1;
    pref[0] = 0;
    for(int i = 1;i<=maxdiff;i++){
        int num = max((int)0, b-max(a, (i-1)+1)+1);
        //cout<<i<<" "<<num<<endl;
        pref[i]+=num;
        pref[i]+=pref[i-1];
    }
    int ans = 0;
    for(int z = c;z<=d;z++){
        int mindiff = z-c+1;
        int maxdiff = z-b+1;
        ans+=pref[maxdiff] - pref[mindiff-1];
        //cout<<z<<" "<<mindiff<<" "<<maxdiff<<" "<<(pref[maxdiff] - pref[mindiff-1])<<endl;
    }
    cout<<ans<<endl;

}
//b k
//1 3
//