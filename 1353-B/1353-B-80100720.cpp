#include <iostream>
#include <vector>
#include <queue>
#define int long long
using namespace std;
signed main(){
    int t, n, k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int a[n], b[n];
        for(int i = 0;i<n;i++) cin>>a[i];
        for(int i = 0;i<n;i++) cin>>b[i];
        priority_queue<int, vector<int>, greater<int>> mina;
        priority_queue<int> maxb;
        int sum = 0;
        for(int i = 0;i<n;i++){
            mina.push(a[i]);
            maxb.push(b[i]);
            sum+=a[i];
        }
        while(k-- && (mina.top()<maxb.top())){
            sum-=mina.top();
            maxb.push(mina.top());
            mina.pop();
            sum+=maxb.top();
            mina.push(maxb.top());
            maxb.pop();
            //cout<<sum<<endl;
        }
        cout<<sum<<endl;
    }
}
//b k
//1 3
//