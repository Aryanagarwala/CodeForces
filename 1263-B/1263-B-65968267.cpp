#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <vector>
#include <queue>
#define int long long
using namespace std;
int count = 0;
int n;
string pins[10];
bool overlap(string a){
    for(int i = 0;i<n;i++){
        if(pins[i]==a) return true;
    }
    return false;
}
void makechange(int i, int j){
    string temp = pins[i];
    for(char k = '0';k<='9';k++){
        temp[0] = k;
        if(overlap(temp)) continue;
        pins[i] = temp;
        return;
    }
}
bool overlap(){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(i==j) continue;
            if(pins[i]==pins[j]){
                makechange(i, j);
                return true;
            }
        }
    }
    return false;
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i =0 ;i<n;i++){
            cin>>pins[i];
        }
        int count = 0;
        while(overlap()){
            count++;
        }
        cout<<count<<endl;
        for(int i =0 ;i<n;i++){
            cout<<pins[i]<<endl;
        }
    }
}