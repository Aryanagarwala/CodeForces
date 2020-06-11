#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        int amt = abs(a-b);
        int ans = 0;
        ans+=amt/5;
        amt%=5;
        ans+=amt/2;
        amt%=2;
        ans+=amt;
        cout<<ans<<endl;
    }
}