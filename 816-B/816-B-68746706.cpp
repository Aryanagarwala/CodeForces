#include <iostream>
#include <vector>
#include <queue>
#define INF 10000000000000000
#define int long long
using namespace std;
const int N = 2e5 + 5;
int32_t main() {
    int n, k, q;
    cin>>n>>k>>q;
    int arr[N];
    for(int i = 0;i<N;i++){
        arr[i] = 0;
    }
    while(n--){
        int u, v;
        cin>>u>>v;
        arr[u]++;
        arr[v+1]--;
    }
    for(int i = 1;i<N;i++){
        arr[i]+=arr[i-1];
    }
    for(int i = 1;i<N;i++){
        if(arr[i]<k) arr[i] = 0;
        else arr[i] = 1;
        arr[i]+=arr[i-1];
    }
    while(q--){
        int u, v;
        cin>>u>>v;
        cout<<(arr[v] - arr[u-1])<<endl;
    }
}