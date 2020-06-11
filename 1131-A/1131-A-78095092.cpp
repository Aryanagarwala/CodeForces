#include <bits/stdc++.h>
using namespace std;
int main(){
    int w1, h1, w2, h2;
    cin>>w1>>h1>>w2>>h2;
    int ans = w1+(h1*2)+w2+(h2*2)+4+(w1 - w2);
    cout<<ans<<endl;
}