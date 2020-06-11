#include<iostream>
#include<algorithm>
#include <vector>
#include <queue>
#include <set>
#include<deque>
#include <map>
#define int long long
#define INF 10000000000000000
#define mir(i) (n-1-i)
#define mid(l, u) ((l+u)/2)
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
using namespace std;
int32_t main(){
    int n;
    cin>>n;
    int vals[n];
    for(int i = 0;i<n;i++) cin>>vals[i];
    map<int, int> maxseen;
    int maxval = 0;
    for(int i = n-1;i>=0;i--){
        int temp = maxseen[vals[i]-i] + vals[i];
        maxval = max(maxval, temp);
        maxseen[vals[i]-i] = temp;
    }
    cout<<maxval<<endl;
 }