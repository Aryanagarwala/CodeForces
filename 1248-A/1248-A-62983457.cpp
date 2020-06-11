#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long oddeven[] = {0, 0};
        long long oddeven1[] = {0, 0};
        for(int i =0;i<n;i++){
            int num; cin>>num;
            oddeven[num%2]++;
        }
        cin>>n;
        for(int i = 0;i<n;i++){
            int num; cin>>num;
            oddeven1[num%2]++;
        }
        long long ans = oddeven[0]*oddeven1[0] + oddeven[1]*oddeven1[1];
        cout<<ans<<endl;
    }
}