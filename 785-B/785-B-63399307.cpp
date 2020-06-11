#include <iostream>
#include <cmath>
#include <fstream>
#include <unordered_map>
using namespace std;
int main() {
    int n, m, l, r;
    cin>>n;
    int maxl1 = 0, maxl2 = 0;
    int minr1 = 1e9 + 5, minr2 = 1e9 + 5;
    for(int i =0 ;i<n;i++){
        cin>>l>>r;
        maxl1 = max(maxl1, l);
        minr1 = min(minr1, r);
    }
    cin>>m;
    for(int i = 0;i<m;i++){
        cin>>l>>r;
        maxl2 = max(maxl2, l);
        minr2 = min(minr2, r);
    }
    cout<<max(0, max(maxl2 - minr1, maxl1 - minr2))<<endl;
}