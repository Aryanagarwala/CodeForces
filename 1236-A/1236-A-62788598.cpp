#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int a, b, c;
        cin>>a>>b>>c;
        int stones = 0;
        while(b>0 && c>1){
            stones+=3;
            b--;
            c-=2;
        }
        while(a>0 && b>1){
            stones+=3;
            a--;
            b-=2;
        }
        cout<<stones<<endl;
    }
}