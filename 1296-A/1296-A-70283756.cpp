#include <iostream>
#include <queue>
#define int long long
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        bool b[] = {false, false};
        for(int i = 0;i<n;i++){
            cin>>a[i];
            b[a[i]%2] = true;
        }
        if(n%2==0){
            cout<<((b[0]&&b[1])?"YES":"NO")<<endl;
            continue;
        }
        cout<<(b[1]?"YES":"NO")<<endl;
    }
}