#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>
#include <set>
#include <iomanip>
#define INF 1e16
#define int long long
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        int b[n];
        for(int i = 0;i<n;i++) cin>>a[i];
        for(int i = 0;i<n;i++) cin>>b[i];
        bool started = false;
        bool ended = false;
        int difference = 0;
        bool possible = true;
        for(int i = 0;i<n;i++){
            if(a[i]>b[i]) possible = false;
            else if(a[i]!=b[i]){
                if(!started){
                    started = true;
                    difference = b[i]-a[i];
                }
                else{
                    if(ended){
                        possible = false;
                    }
                    if(b[i]-a[i]!=difference){
                        possible = false;
                    }
                }
            }
            else{
                if(started) ended = true;
            }
        }
        if(!possible){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }

}