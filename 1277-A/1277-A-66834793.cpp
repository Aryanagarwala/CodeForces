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
#define MOD 1000000007
#define mid(l, u) ((l+u)/2)
#define int long long
#define double long double
#define child(i) (i*2 + 1)
using namespace std;
int32_t main(){
    int basic[10][11];
    for(int i = 1 ;i<=9;i++) basic[i][1] = i;
    for(int j = 2;j<=10;j++){
        for(int i = 1;i<=9;i++){
            basic[i][j] = basic[i][j-1]*10 + i;
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int count = 0;
        for(int i = 1;i<=9;i++){
            for(int j = 1;j<=10;j++){
                if(basic[i][j]<=n){
                    //cout<<basic[i][j]<<endl;
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
}