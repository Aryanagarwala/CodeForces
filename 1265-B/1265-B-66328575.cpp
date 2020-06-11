#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <cstdlib>
using namespace std;
int findroot(int i, int roots[]){
    if(roots[i]==i) return i;
    else return roots[i] = findroot(roots[i], roots);
}
void UNION(int i, int j, int ranks[], int roots[]){
    int r1 = findroot(i, roots);
    int r2 = findroot(j, roots);
    if(r1==r2) return;
    else{
        if(ranks[r1]<ranks[r2]){
            roots[r1] = r2;
            ranks[r2]+=ranks[r1];
        }
        else{
            roots[r2] = r1;
            ranks[r1] += ranks[r2];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char arr[] = {'a', 'b', 'c', '?'};
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int index[n+1];
        int arr[n];
        int roots[n];
        int ranks[n];
        for(int i =0 ;i<n;i++){
            cin>>arr[i];
            index[arr[i]] = i;
            roots[i] = i;
            ranks[i] = 1;
        }
        for(int i = 1;i<=n;i++){
            if(index[i]>0){
                if(arr[index[i]-1]<=i) UNION(index[i], index[i] - 1, ranks, roots);
            }
            if(index[i]<(n-1)){
                if(arr[index[i]+1]<=i) UNION(index[i], index[i]+1, ranks, roots);
            }
            if(ranks[findroot(index[i], roots)]==i) cout<<1;
            else cout<<0;
        }
        cout<<endl;
    }
}