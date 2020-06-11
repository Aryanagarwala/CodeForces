#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#define int long long
using namespace std;
int root[100];
int findroot(int i){
    ///cout<<i<<" "<<root[i]<<endl;
    if(i==100 || root[i]==i) return i;
    else return root[i] = findroot(root[i]);
}
int32_t main(){
    int pow2[64];
    pow2[0] = 1;
    for(int i = 1;i<64;i++) pow2[i] = pow2[i-1]*2;
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int arr[m];
        int sum = 0;
        for(int i =0 ;i<m;i++) cin>>arr[i];
        for(int i =0 ;i<m;i++) sum+=arr[i];
        if(sum<n){
            cout<<-1<<endl;
            continue;
        }
        int powf[100];
        for(int i =0 ;i<100;i++) powf[i] = 0;
        for(int i = 0;i<m;i++){
            powf[(int)log2(arr[i])]++;
        }
        for(int i =0 ;i<100;i++){
            if(powf[i]==0) root[i] = i+1;
            else root[i] = i;
            //cout<<i<<" "<<root[i]<<endl;
        }
        int count = 0;
        int surplus = 0;
        for(int i = 0;i<64;i++){
            surplus+=powf[i]*pow2[i];
            if(pow2[i]&n){
                if(surplus>=pow2[i]){
                    surplus-=pow2[i];
                    continue;
                }
                int totake = findroot(i);
                count+=(totake-i);
                surplus+=pow2[totake]-pow2[i];
                powf[totake]--;
                if(powf[totake]==0) root[totake]++;
            }
        }
        cout<<count<<endl;
    }
}