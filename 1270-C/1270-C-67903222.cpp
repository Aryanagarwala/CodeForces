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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sum = 0;
        int xorr = 0;
        for(int i =0;i<n;i++){
            int num;
            cin>>num;
            sum+=num;
            xorr^=num;
        }
        int temp = (xorr+sum);
        cout<<2<<endl;
        cout<<xorr<<" "<<(xorr+sum)<<endl;
    }
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