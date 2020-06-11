#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>
#define double long double
#define mid(l, u) ((l+u)/2)
#define lchild(i) (i*2+  1)
#define rchild(i) (i*2 + 2)
#define INF -100000000
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<pair<int, int>> good;
    for(int i  = 1;i<n;i++){
        good.push_back(make_pair(i, i+1));
    }
    if(n<6) cout<<-1<<endl;
    else{
        cout<<1<<" "<<2<<endl;
        cout<<1<<" "<<3<<endl;
        cout<<1<<" "<<4<<endl;

        for(int j = 5;j<=n;j++){
            cout<<2<<" "<<j<<endl;
        }
    }
    for(pair<int, int> j: good){
        cout<<j.first<<" "<<j.second<<endl;
    }
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