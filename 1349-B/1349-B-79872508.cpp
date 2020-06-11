#include <iostream>
#define int long long
using namespace std;
void reset(int &diff, bool &havek, int &sz){
    diff = 0;
    havek = false;
    sz = 0;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        bool suck = false;
        int a[n];
        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            if(num==k){
                suck = true;
            }
            if(num>=k) a[i] = 1;
            else a[i] = -1;
        }
        if(n==1 && suck){
            cout<<"Yes\n";
            continue;
        }
        if(!suck){
            cout<<"No\n"<<endl;
            continue;
        }
        int sz = 0;
        int csum = 0;
        int maxsum = 0;
        for(int i = 0;i<n;i++){
            csum+=a[i];
            sz++;
            if(sz>=2) maxsum = max(csum, maxsum);
            if(csum<0){
                csum = 0;
                sz = 0;
            }
        }
        if(maxsum>=1) cout<<"Yes\n";
        else cout<<"No\n";
    }
}
//b k
//1 3
//