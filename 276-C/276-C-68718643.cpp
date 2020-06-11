#include <iostream>
#include <vector>
#include <queue>
#define INF 10000000000000000
#define int long long
using namespace std;
int32_t main() {
    int n, q;
    cin>>n>>q;
    priority_queue<int> num;
    int arr[n+2];
    for(int i =0 ;i<n;i++){
        int lol;
        cin>>lol;
        num.push(lol);
        arr[i] = 0;
    }
    arr[n] = arr[n+1] = 0;
    while(q--){
        int u, v;
        cin>>u>>v;
        arr[u]++;
        arr[v+1]--;
    }
    priority_queue<int> coeff;
    int sum = 0;
    for(int i = 1;i<=n;i++){
        arr[i]+=arr[i-1];
        coeff.push(arr[i]);
    }
    while(!num.empty()){
        sum+=coeff.top()*num.top();
        coeff.pop();
        num.pop();
    }
    cout<<sum<<endl;
}