#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
#define int long long
#define double long double
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int n1 = n;
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    vector<int> prime;
    int limit = sqrt(n);
    for(int i = 2;i<=limit;i++){
        if(n%i==0){
            prime.push_back(i);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) prime.push_back(n);
    int total = prime[0];
    if(prime.size()>1){
        total-=(n1-prime[1]);
    }
    cout<<max((int)1, total)<<endl;
}


//1 2
//4 5
//5 6


//89
//69
//83