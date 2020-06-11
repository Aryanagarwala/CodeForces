#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    int a[n];
    for(int i = 0;i<n;i++) cin>>a[i];
    int freq[m+1];
    for(int i = 0;i<=m;i++) freq[i] = 0;
    for(int i = 0;i<n;i++){
        if(a[i]<=m) freq[a[i]]++;
    }
    int cnt[m+1];
    int l = 1;
    int maxi = 0;
    for(int i = 0;i<=m;i++) cnt[i] = 0;
    for(int i = 1;i<=m;i++){
        if(freq[i]==0) continue;
        for(int j = i;j<=m;j+=i){
            cnt[j]+=freq[i];
            if((cnt[j]>maxi) || (cnt[j]==maxi && j<l)){
                l = j;
                maxi = cnt[j];
            }
        }
    }
    cout<<l<<' '<<maxi<<'\n';
    for(int i = 0;i<n;i++){
        if(l%a[i]==0) cout<<(i+1)<<' ';
    }
    cout<<"\n";
    return 0;
}
//b k
//1 3
//