#include <iostream>
#include <cmath>
#include <fstream>
#include <unordered_map>
using namespace std;
int main() {
    int n;
    cin>>n;
    long long ans = 0;
    unordered_map<string, int> mp;
    mp["Icosahedron"] = 20;
    mp["Dodecahedron"] = 12;
    mp["Octahedron"] = 8;
    mp["Cube"] = 6;
    mp["Tetrahedron"] = 4;
    for(int i =0 ;i<n;i++){
        string s;
        cin>>s;
        ans+=mp[s];
    }
    cout<<ans<<endl;
}