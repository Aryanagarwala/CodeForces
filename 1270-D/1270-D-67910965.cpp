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
#define mid(l, u) ((l+u)/2)
#define rchild(i) (i*2 + 2)
#define lchild(i) (i*2 + 1)
#define INF -10000000000
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i =0 ;i<n;i++) arr[i] = -1;
    cout<<"? ";
    for(int i = 0;i<k;i++){
        cout<<(i+1)<<" ";
    }
    cout<<endl;
    cout.flush();
    int pos, val;
    cin>>pos>>val;
    pos--;
    arr[pos] = val;
    cout<<"? ";
    for(int i = 0;i<=k;i++){
        if(i==pos) continue;
        cout<<(i+1)<<" ";
    }
    cout<<endl;
    cout.flush();
    int p, v;
    cin>>p>>v;
    int back = 0;
    if(v>val) back = 1e9 + 5;
    else back = -2;
    for(int tr = 0;tr<k;tr++){
        if(tr==pos) continue;
        vector<int> q;
        for(int i = 0;i<k;i++){
            if(i==tr) continue;
            q.push_back(i+1);
        }
        q.push_back((k+1));
        cout<<"? ";
        for(int i: q){
            cout<<i<<" ";
        }
        cout<<endl;
        cout.flush();
        cin>>p>>v;
        if(v!=val){
            if(v>val) arr[tr] = -2;
            if(v<val) arr[tr] = 1e9 + 5;
        }
        else{
            arr[tr] = back;
        }
    }
    int cnt = 1;
    for(int i =0 ;i<k;i++) if(arr[i]==-2) cnt++;
    cout<<"! "<<cnt<<endl;
}
//3 10
//0 4 7
/*
 1 3
2 11
4 8
5 7
6 10
9 12
 */