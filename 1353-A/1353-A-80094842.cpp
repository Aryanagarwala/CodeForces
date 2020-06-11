#include <iostream>
#include <vector>
#include <queue>
#define int long long
using namespace std;
signed main(){
    int t, n, m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        if(n==1){
            cout<<0<<endl;
        }
        else if(n==2){
            cout<<m<<endl;
        }
        else{
            cout<<(2*m)<<endl;
        }
    }
}
//b k
//1 3
//