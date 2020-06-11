#include <iostream>
#include <vector>
#include <queue>
#define int long long
#define lchild(i) (i*2 + 1)
#define INF 1000000000000000000
#define rchild(i) (i*2 + 2)
#define mid(l, u) ((l+u)/2)
using namespace std;
int maxdig(int a){
    int maxi = -1;
    while(a!=0){
        maxi = max(maxi, (int) a%10);
        a/=10;
    }
    return maxi;
}
int mindig(int a){
    int mini = 10;
    while(a!=0){
        mini = min(mini, (int)a%10);
        a/=10;
    }
    return mini;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int a, k;
        cin>>a>>k;
        if(k==1) cout<<a<<endl;
        else{
            int diff;
            diff = 5;
            k-=1;
            while(diff!=0 && k--){
                diff = (maxdig(a) * mindig(a));
                a+=diff;
            }
            cout<<a<<endl;
        }

    }
}
//b k
//1 3
//