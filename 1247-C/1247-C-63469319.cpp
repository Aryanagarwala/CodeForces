#include <iostream>
#include <unordered_map>
#define int long long
using namespace std;
bool countbits(int x, int y){
    int num = 1;
    int c = 1;
    int toreturn = 0;
    int bitcount = 0;
    while(num<=x){
        if(x&num){
            toreturn+=(c-1);
            bitcount++;
        }
        c++;
        num*=2;
    }
    if(bitcount<=y && bitcount+toreturn>=y) return false;
    return true;
}
int32_t main() {
    int n, p;
    cin>>n>>p;
    int times = 0;
    bool cont = true;
    bool found = false;
    while(cont && times<100000){
        n-=p;
        times++;
        cont = countbits(n, times);
        found = !cont;
    }
    if(found) cout<<times<<endl;
    else cout<<-1<<endl;
}