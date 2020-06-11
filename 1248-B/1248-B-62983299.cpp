#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long a[n];
    long long sum2 = 0;
    for(int i =0 ;i<n;i++){
        cin>>a[i];
        sum2+=a[i];
    }
    sort(a, a+n);
    long long sum1 = 0;
    for(int i = 0;i<((n/2));i++){
        sum1+=a[i];
        sum2-=a[i];
    }
    long long ans = (sum1*sum1) + (sum2*sum2);
    cout<<ans<<endl;
}