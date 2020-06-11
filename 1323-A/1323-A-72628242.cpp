#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>
#define double long double
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
#define mid(l, u) ((l+u)/2)
using namespace std;
int32_t main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int a[n];
        int e = 0;
        for(int i = 0;i<n;i++){
            cin>>a[i];
            if(a[i]%2==0) e = (i+1);
        }
        if(e!=0){
            cout<<"1\n"<<e<<endl;
            continue;
        }
        if(n==1){
            cout<<"-1"<<endl;
            continue;
        }
        cout<<2<<endl;
        cout<<1<<" "<<2<<endl;
    }
}