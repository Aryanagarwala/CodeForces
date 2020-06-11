#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i =0 ;i<n;i++) cin>>a[i];
    vector<int> cnt;
    for(int i = 0;i<n;i++){
        int j = i+1;
        while(j<n && a[j]==a[i]) j++;
        cnt.push_back(j-i);
        i = j-1;
    }
    int maxcount = 0;
    for(int i = 1;i<cnt.size();i++){
        maxcount = max(maxcount, min(cnt[i], cnt[i-1]));
    }
    cout<<(maxcount*2)<<endl;
}