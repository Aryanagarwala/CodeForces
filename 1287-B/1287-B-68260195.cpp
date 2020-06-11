#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#define int long long
#define double long double
#define mid(l, u) ((l+u)/2)
#define lchild(i) (i*2+  1)
#define rchild(i) (i*2 + 2)
#define INF 1000000000000000
using namespace std;
char left(char a, char b){
    if(a>b) swap(a, b);
    pair<char, char> s = make_pair(a, b);
    if(s==make_pair('E', 'S')) return 'T';
    if(s==make_pair('E', 'T')) return 'S';
    if(s==make_pair('S', 'T')) return 'E';
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<string, int> cnt;
    int n, k;
    cin>>n>>k;
    string arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    for(int i = 1;i<n;i++){
        cnt[arr[i]]++;
    }
    int ans = 0;
    for(int i = 1;i<n;i++){
        cnt[arr[i]]--;
        for(int j = 0;j<i;j++){
            string f = "";
            for(int l = 0;l<k;l++){
                if(arr[i][l]==arr[j][l]) f+=arr[i][l];
                else f+=left(arr[i][l], arr[j][l]);
            }
            ans+=cnt[f];
        }
    }
    cout<<ans<<endl;
}
//2 1

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