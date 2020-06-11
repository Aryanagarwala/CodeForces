#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define int long long
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); //FAST IO
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        int arr[n];
        int distinct = 0;
        unordered_map<int, int> firstocc;
        unordered_map<int, int> lastocc;
        unordered_map<int, int> count;
        unordered_map<int, int> tail;
        vector<int> v;
        vector<int> v1;
        for(int i =0 ;i<n;i++){
            cin>>arr[i];
            if(!count[arr[i]]){
                firstocc[arr[i]] = i;
                distinct++;
                v1.push_back(arr[i]);
            }
            lastocc[arr[i]] = i;
            count[arr[i]]++;
            tail[arr[i]] = 1;
        }
        sort(v1.begin(), v1.end());
        int maxi = 1;
        for(int i = 0;i<v1.size();i++){
            maxi = max(tail[v1[i]], maxi);
            if((i+1!=v1.size()) && lastocc[v1[i]]<firstocc[v1[i+1]]){
                tail[v1[i+1]]+=tail[v1[i]];
            }
        }
        cout<<(distinct - maxi)<<endl;
    }
}