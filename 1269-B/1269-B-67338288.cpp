#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <fstream>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <map>
#define int long long
using namespace std;
int n, m;
bool perm(int a[], int b[], int x){
    set<int> sa;
    unordered_map<int, int> freq;
    for(int i =0 ;i<n;i++){
        freq[b[i]]++;
        sa.insert(b[i]);
    }
    for(int i = 0;i<n;i++){
        freq[(a[i]+x)%m]--;
    }
    for(int j: sa){
        if(freq[j]!=0){
            //cout<<j<<" "<<freq[j]<<endl;
            return false;
        }
    }
    return true;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int a[n];
    int b[n];
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    for(int i = 0;i<n;i++){
        cin>>b[i];
    }
    int ans = 10000000000;
    for(int i = 0;i<n;i++){
        int tochange;
        if(a[0]>b[i]){
            tochange = (m+b[i]) - a[0];
        }
        else tochange = (b[i]-a[0]);
        //cout<<i<<" TOCHANGE : "<<tochange<<endl;
        if(perm(a, b, tochange)) ans = min(ans, tochange);
    }
    cout<<ans<<endl;
}
/*
 1 3
2 11
4 8
5 7
6 10
9 12
 */