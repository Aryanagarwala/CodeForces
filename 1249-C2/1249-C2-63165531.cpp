#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#define MOD (1000000007)
using namespace std;
long long pow3[39];
int num[39];
int limit = 39;
void convert(long long n, int base){
    long long rem = n%pow3[base];
    num[base] = n/pow3[base];
    if(base==0) return;
    convert(rem, base-1);
}
int main() {
    pow3[0] = 1;
    for(int i = 1;i<limit;i++) pow3[i] = 3*pow3[i-1];
    int q;
    cin>>q;
    while(q--){
        long long n;
        cin>>n;
        for(int i = 0;i<limit;i++) num[i] = 0;
        convert(n, 38);
        for(int j = 0;j<limit;j++){
            if(num[j]>1){
                int i = j+1;
                while(num[i]>=1) i++;
                num[i] = 1;
                for(int k = i-1;k>=0;k--) num[k] = 0;
                j = i;
            }
        }
        long long finalnum =0 ;
        for(int i =0 ;i<limit;i++) finalnum+=(num[i]*pow3[i]);
        cout<<finalnum<<endl;
     }
}