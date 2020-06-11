#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
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
#define double long double
using namespace std;
int32_t main(){
    int n, m;
    cin>>n>>m;
    string s[n];
    string t[m];
    for(int i =0 ;i<n;i++) cin>>s[i];
    for(int i = 0;i<m;i++) cin>>t[i];
    int q;
    cin>>q;
    while(q--){
        int val;
        cin>>val;
        val--;
        int sind = val%n;
        int tind = val%m;
        cout<<(s[sind]+t[tind])<<endl;
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