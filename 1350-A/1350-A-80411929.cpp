#include <iostream>
#include <vector>
#include <queue>
#define int long long
using namespace std;
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int num = 1;
        for(int i = 2;i<=n;i++){
            if(n%i==0){
                num = i;
                break;
            }
        }
        n+=num;
        n+=((k-1)*2);
        cout<<n<<endl;
    }
}
//b k
//1 3
//