#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <cstdlib>
using namespace std;
string s = "";
void alternate(int total, char at, char bt){
    total*=2;
    for(int i = 0;i<total;i++){
        if(i%2==0) s+=at;
        else s+=bt;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    int dc = 0;
    bool addb = false, addc = false;
    int ab, cb;
    if(d>c){
        if(d-c==1 && a==0 && b==0){
            alternate(c, '3', '2');
            s+='3';
            goto printans;
        }
        cout<<"NO"<<endl;
        return 0;
    }
    dc = d;
    c-=d;
    d = 0;
    if(a>b){
        if(c==0 && d==0 && dc ==0 && a-b==1){
            alternate(b, '0', '1');
            s+='0';
            goto printans;
        }
        cout<<"NO"<<endl;
        return 0;
    }
    ab = a;
    b-=a;
    a = 0;

    cb = min(b, c);
    b-=cb;
    c-=cb;
    addc = false;
    addb = false;
    if(b--) addb = true;
    if(c--) addc = true;
    alternate(ab, '0', '1');
    alternate(cb, '2', '1');
    alternate(dc, '2', '3');
    if(addc) s+='2';
    if(addb) s= '1' + s;
    for(int i = 0;i<(s.length()-1);i++){
        if(abs(s[i+1]-s[i])!=1){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(a>0||b>0||c>0||d>0){
        cout<<"NO"<<endl;
        return 0;
    }
    printans:
    cout<<"YES"<<endl;
    for(int i = 0;i<s.length();i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}