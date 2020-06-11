#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>
#include <set>
#include <iomanip>
#include <unordered_map>
#define INF 1e16
#define int long long
using namespace std;
int32_t main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i<n;i++) cin>>a[i];
    vector<int> info;
    int days = 0;
    bool poss = true;
    int count = 0;
    for(int i = 0;i<n;i++){
        count = 0;
        days++;
        unordered_map<int, bool> entered;
        unordered_map<int, bool> left;
        int j = i;
        while(j<n){
            if(a[j]>0){
                if(entered[a[j]]) goto failed;
                entered[a[j]] = true;
                count++;
            }
            else{
                if(!entered[-a[j]] || left[-a[j]]) goto failed;
                left[-a[j]] = true;
                count--;
            }
            //cout<<j<<" "<<count<<endl;
            if(count==0) goto done;
            j++;
        }
        done:
        if(j==n) goto failed;
        info.push_back(j-i+1);
        i = j;
    }
    cout<<days<<endl;
    for(int i: info) cout<<i<<" ";
    cout<<endl;
    return 0;
    failed:
    cout<<-1<<endl;
}