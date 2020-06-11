#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <map>
#define int long long
#define pb push_back
#define mp make_pair
#define ll long long
#define MOD 1000000007
#define mid(l, u) (l+u)/2
#define rchild(i) (i*2)
#define lchild(i) (i*2 + 1)
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    if(n == 1 && m == 1){
        cout<<0<<endl;
        return 0;
    }
    int ra[n+1],ca[m+1];
    if(n <=m ){
        for(int i =1;i<=n;i++){
            ra[i] = i;
        }
        for(int i= 1;i<=m;i++) ca[i] = i + n;

    }
    else{
        for(int i =1;i<=m;i++) ca[i] =i;
        for(int i= 1;i<=n;i++) ra[i] = i +m;
    }

    for(int i =1;i<=n;i++){
        for(int j =1;j<=m;j++){
            cout << (ra[i]*ca[j]) << " ";
        }
        cout << endl;
    }
}