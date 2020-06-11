#include<bits/stdc++.h>
    #define int long long
    using namespace std;
    int32_t main(){
        int t;
        cin>>t;
        while(t--){
            int n;
            cin>>n;
            if(n==1){
                cout<<-1<<endl;
                continue;
            }
            string num = "2";
            for(int i =1 ;i<n;i++){
                num+="3";
            }
            cout<<num<<endl;
        }
    }
    //(((2^90)%998244353)*512)%998244353