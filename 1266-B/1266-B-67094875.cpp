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
    int pipes[] = {1, 2, 3, 4, 5, 6};
    int opp[] = {6,5, 4, 3, 2, 1};
    vector<int> removable;
    for(int i =0 ;i<6;i++){
        for(int j = 0;j<6;j++){
            removable.push_back(pipes[i] + pipes[j] + opp[i]);
        }
    }
    sort(removable.begin(), removable.end());
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(min(n, ((n%14)+14))>=15 && min(n, ((n%14)+14))<=20) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}