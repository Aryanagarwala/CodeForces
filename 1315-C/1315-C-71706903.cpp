#include <iostream>
#include <queue>
#include <algorithm>
#include <fstream>
#include <map>
#define eq 10000
#define int long long
#define MOD 1000000007
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool used[(2*n)+1];
        for(int i = 1;i<=(2*n);i++) used[i] = false;
        int b[n+1];
        for(int i = 1;i<=n;i++) cin>>b[i];
        int a[(2*n)+1];
        for(int i = 1;i<=n;i++){
            a[(2*i)-1] = b[i];
            if(used[b[i]]){
                cout<<-1<<endl;
                goto end;
            }
            used[b[i]] = true;
        }
        for(int i = 2;i<=(2*n);i+=2){
            int found = 0;
            for(int j = a[i-1];j<=(2*n);j++){
                if(!used[j]){
                    found = j;
                    break;
                }
            }
            if(found==0){
                cout<<-1<<endl;
                goto end;
            }
            a[i] = found;
            used[found] = true;
        }
        for(int i = 1;i<=2*n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        end:
        continue;
    }

}