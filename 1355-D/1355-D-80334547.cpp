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
signed main(){
    int n, s;
    cin>>n>>s;
    if(n<=(s/2)){
        cout<<"YES"<<endl;
        for(int i = 0;i<(n-1);i++){
            cout<<2<<" ";
            s-=2;
        }
        cout<<s<<endl;
        cout<<1<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
//b k
//1 3
//