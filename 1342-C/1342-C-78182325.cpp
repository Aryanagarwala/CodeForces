#include <bits/stdc++.h>
#define int long long
#define INF 1000000000000
using namespace std;
int lthan(int l, int phi, int a, int b){
    int np = l/a;
    int amt = (np/phi) + ((np%phi)>0);
    amt*=a;
    if((l - (l%a))%b==0) amt+= ((l%a)+1);
    return  amt;
}
int gcd(int a, int b){
    if(a==0) return b;
    return gcd(b%a, a);
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int a, b, q;
        cin>>a>>b>>q;
        if(a<b) swap(a, b);
        //cout<<a<<" "<<b<<endl;
        int phi = ((a*b)/gcd(a, b))/a;
        //cout<<phi<<endl;
        while(q--){
            int l, r;
            cin>>l>>r;
            int total = lthan(r, phi, a, b) - lthan(l-1, phi, a, b);
            //cout<<total<<endl;
            total = (r-l+1) - total;
            cout<<total<<" ";
        }
        cout<<endl;
    }
}