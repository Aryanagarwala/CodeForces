#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define int long long
#define double long double
using namespace std;
int32_t main(){
    int n, m;
    cin>>n>>m;
    int fact[n+5];
    fact[0] = 1;
    for(int i = 1;i<=n;i++){
        fact[i]=i*fact[i-1];
        fact[i]%=m;
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        //cout<<(i+1)<<" "<<(n-(i+1))<<" "<<(n-i)<<endl;
        ans+= (((((fact[i+1]*fact[n-(i+1)])%m)*(n-i))%m)*(n-i))%m;
        ans%=m;
    }
    cout<<ans<<endl;
}
//2 1

//3 10
//0 4 7
/*
 1 3
2 11
4 8
5 7
6 10
9 12
 */