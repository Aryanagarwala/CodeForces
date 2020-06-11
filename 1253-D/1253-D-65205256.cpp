#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>
#include <set>
#include <iomanip>
#include <unordered_map>
#define INF 1e16
#define int long long
using namespace std;
int root[(int)(2*1e5 + 5)];
int ranks[(int)(2*1e5 + 5)];
int maxi[(int)(2*1e5 + 5)];
int findroot(int i){
    if(i==root[i]) return i;
    else return root[i] = findroot(root[i]);
}
int UNION(int i, int j){
    int r1 = findroot(i);
    int r2 = findroot(j);
    if(r1==r2) return 0;
    if(ranks[r1]<ranks[r2]){
        root[r1] = r2;
        ranks[r2] += ranks[r1];
        maxi[r2] = max(maxi[r2], maxi[r1]);
        maxi[r1] = maxi[r2];
    }
    else{
        root[r2] = r1;
        ranks[r1]+=ranks[r2];
        maxi[r1]=max(maxi[r1], maxi[r2]);
        maxi[r2] = maxi[r1];
    }
    return 1;
}
int32_t main(){
    int n, m;
    cin>>n>>m;
    for(int i =0 ;i<n;i++){
        root[i] = i;
        ranks[i] = 1;
        maxi[i] = i;
    }
    for(int i =0 ;i<m;i++){
        int u, v;
        cin>>u>>v;
        UNION(u-1, v-1);
    }
    int count = 0;
    for(int i = 0;i<n;i++){
        int j = i;
        while(j<n && j<maxi[findroot(i)]){
            count+=UNION(i, j++);
        }
        i = j;
    }
    cout<<count<<endl;
}
//1 3
//2 6
//