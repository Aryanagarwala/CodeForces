#include <iostream>
#include <algorithm>
#define int long long
#define double long double
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a, b, n, s;
        cin>>a>>b>>n>>s;
        bool possible = false;
        if((a*n)>=s){
            possible = (b>=(s%n));
        }
        else{
            possible = (b>=(s-(a*n)));
        }
        cout<<(possible?"YES":"NO")<<endl;
    }
}