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
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    if(n%2==0){
        cout<<(n+4)<<" "<<4<<endl;
    }
    else{
        cout<<(n+9)<<" "<<9<<endl;
    }
}
/*
 1 3
2 11
4 8
5 7
6 10
9 12
 */