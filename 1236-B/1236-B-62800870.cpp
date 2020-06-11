#include <iostream>
using namespace std;
long long MOD = 1e9 + 7;
long long fastpower(long long base, long long power){
    if(power==0) return 1;
    if(power==1){
        return base;
    }
    if(power==2){
        return (base*base)%MOD;
    }
    else{
        long long val = (fastpower(base, power/2))%MOD;
        val*=val;
        val%=MOD;
        if(power%2){
            val*=base;
            val%=MOD;
        }
        return val;
    }
}
int main() {
    long long n, m;
    cin>>n>>m;
    long long choicepertype = (fastpower(2, m) - 1 + MOD)%MOD;
    long long answer = fastpower(choicepertype, n)%MOD;
    cout<<(answer%MOD)<<endl;
}