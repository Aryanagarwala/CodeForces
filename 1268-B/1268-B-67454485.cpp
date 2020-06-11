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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    for(int i =0 ;i<n;i++){
        cin>>arr[i];
    }
    int cnt[] = {0, 0};
    for(int i = 0;i<n;i++){
        if(i%2){
            cnt[0] += (arr[i]/2) + (arr[i]%2);
            cnt[1] += arr[i]/2;
        }
        else{
            cnt[0] += arr[i]/2;
            cnt[1] += (arr[i]/2) + (arr[i]%2);
        }
    }
    cout<<min(cnt[0], cnt[1])<<endl;
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