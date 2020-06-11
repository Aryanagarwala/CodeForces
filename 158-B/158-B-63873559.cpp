#include <iostream>
#include <algorithm>
using namespace std;
int32_t main(){
    int n;
    cin>>n;
    int cnt[n];
    for(int i = 0;i<n;i++) cin>>cnt[i];
    sort(cnt, cnt+n);
    int j = 0;
    int count = 0;
    for(int i = n-1;i>=j;i--){
        int sum = cnt[i];
        while(i>j && sum+cnt[j]<=4) sum+=cnt[j++];
        count++;
    }
    cout<<count<<endl;
}