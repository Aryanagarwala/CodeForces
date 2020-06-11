#include <iostream>
#include <map>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int a, b, c, d, k;
        cin>>a>>b>>c>>d>>k;
        int required = (a/c) + (a%c>0) + (b/d) + (b%d>0);
        if(required>k) cout<<-1<<endl;
        else cout<<((a/c) + (a%c>0))<<" "<<((b/d) + (b%d>0))<<endl;
    }
    return 0;
}