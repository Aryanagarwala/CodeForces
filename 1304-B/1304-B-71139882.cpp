#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#define int long long
using namespace std;
string rev(string a){
    string b = "";
    for(int i = a.length()-1;i>=0;i--){
        b+=a[i];
    }
    return b;
}
int32_t main(){
    int n, m;
    cin>>n>>m;
    string arr[n];
    bool av[n];
    for(int i = 0;i<n;i++) av[i] = true;
    for(int i = 0;i<n;i++) cin>>arr[i];
    string front = "";
    string end = "";
    for(int i = 0;i<n;i++){
        if(!av[i]) continue;
        for(int j = i+1;j<n;j++){
            if(!av[j]) continue;
            if(arr[i]==rev(arr[j])){
                front+=arr[i];
                end = arr[j]+end;
                av[i] = av[j] = false;
                goto outer;
            }
        }
        outer:
        continue;
    }
    bool found = false;
    for(int i = 0;i<n && !found;i++){
        if(!av[i]) continue;
        if(arr[i]==rev(arr[i])){
            found = true;
            front+=arr[i];
        }
    }
    string ans = front+end;
    cout<<ans.length()<<endl;
    cout<<ans<<endl;
}