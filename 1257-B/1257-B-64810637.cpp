#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int x, y;
        cin>>x>>y;
        if(x>=y){
            cout<<"YES"<<endl;
            continue;
        }
        if(x==0){
            cout<<"NO"<<endl;
            continue;
        }
        if(x<=3 && !(x==2 && y==3)){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
    }
}