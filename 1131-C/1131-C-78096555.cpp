#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++) cin>>arr[i];
    sort(arr, arr+n);
    int final[n];
    int find = 0;
    final[0] = arr[0];
    find++;
    for(int i = 1;i<n;i+=2, find++) final[find] = arr[i];
    find = n-1;
    for(int i = 2;i<n;i+=2, find--) final[find] = arr[i];
    for(int i = 0;i<n;i++){
        cout<<final[i]<<" ";
    }
    cout<<endl;
}