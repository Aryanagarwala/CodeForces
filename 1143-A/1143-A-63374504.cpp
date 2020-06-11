#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n];
    int occ[] = {0, 0};
    for(int i =0 ;i<n;i++){
        cin>>arr[i];
        occ[arr[i]] = i;
    }
    cout<<(min(occ[0], occ[1])+1)<<endl;
}