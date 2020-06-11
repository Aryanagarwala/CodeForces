#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    long a[n];
    for(int i = 0;i<n;i++) cin>>a[i];
    int times = 0;
    double arr[] = {-0.5, 0.5};
    long long sum = 0;
    for(int i = 0;i<n;i++){
        if(a[i]%2) a[i] = ((((long double)a[i])/2.0) + arr[(times++)%2]);
        else a[i]/=2;
        cout<<a[i]<<endl;
        sum+=a[i];
    }
}