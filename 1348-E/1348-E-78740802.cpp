#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k;
pair<int, int> arr[505];
int f(){
    int extraa = 0;
    int extrab = 0;
    int base = 0;
    int cangivea = 0;
    for(int i = 0;i<n;i++){
        int a = arr[i].first, b = arr[i].second;
        int sum = (a+b);
        base+=(sum/k);
        int extra = sum%k;
        int aextra = min(a, extra);
        extraa+=aextra;
        base+=(extraa/k);
        extraa%=k;
        extra -= aextra;
        int bextra = min(b, extra);
        extrab+=bextra;
        int remb = b - bextra;
        base+=(extrab/k);
        extrab%=k;
        cangivea += min(aextra, remb);
    }
    if(cangivea>=(k-extrab) && (k-extrab)<=extraa) base++;
    return base;
}
int f1(){
    int suma = 0, sumb = 0;
    for(int i = 0;i<n;i++) suma+=arr[i].first;
    for(int i = 0;i<n;i++) sumb+=arr[i].second;
    int base = (suma/k) + (sumb/k);
    suma%=k; sumb%=k;
    bool found = false;
    if(suma+sumb<k) return base;
    for(int i = 0;i<n;i++){
        int cantake = min(suma, arr[i].first);
        int cantakeb = min(sumb, arr[i].second);
        if(cantake + cantakeb>=k) found = true;
    }
    if(found) base++;
    return base;
}
signed main(){
    cin>>n>>k;
    for(int i = 0;i<n;i++) cin>>arr[i].first>>arr[i].second;
    cout<<max(f(), f1())<<endl;
    return 0;
}
//acdabcd