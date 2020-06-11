#include <iostream>
#include <queue>
#include <algorithm>
#include <fstream>
#include <map>
#define eq 10000
#define int long long
#define MOD 1000000007
using namespace std;
int32_t main(){
    int n;
    cin>>n;
    pair<int, int> arr[n];
    for(int i = 0;i<n;i++) cin>>arr[i].first;
    for(int i =0 ;i<n;i++) cin>>arr[i].second;
    sort(arr, arr+n);
    int currnum = 0;
    priority_queue<int> pq;
    int ans = 0;
    int toadd = 0;
    for(int i = 0;i<n;i++){
        int difference = arr[i].first - currnum;
        for(int j = 0;j<difference && !pq.empty();j++){
            toadd -= pq.top();
            ans+=toadd;
            pq.pop();
        }
        pq.push(arr[i].second);
        toadd+=arr[i].second;
        currnum = arr[i].first;
        int j = i+1;
        while(j<n && arr[j].first==arr[i].first){
            toadd+=arr[j].second;
            pq.push(arr[j].second);
            j++;
        }
        toadd-=pq.top();
        pq.pop();
        ans+=toadd;
        currnum++;
        i = j-1;
    }
    while(!pq.empty()){
        toadd -= pq.top();
        ans+=toadd;
        pq.pop();
    }
    cout<<ans<<endl;
}