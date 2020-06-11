#include <iostream>
#define int long long
using namespace std;
int32_t main() {
    int a, b;
    cin>>a>>b;
    if(a-b==0){
        cout<<a<<"0 "<<b<<"1"<<endl;
    }
    else if((b-a)==1){
        cout<<a<<"9 "<<b<<"0"<<endl;
    }
    else if((a==9)&&(b==1)){
        cout<<a<<" 10"<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}