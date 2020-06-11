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
            int arr[3];
            cin>>arr[0]>>arr[1]>>arr[2];
            sort(arr, arr+3);
            int a = arr[2], b=arr[1], c = arr[0];
            int count = 0;

            if(a){
                a--;
                count++;
            }
            if(b){
                b--;
                count++;
            }
            if(c){
                c--;
                count++;
            }
            if(a&&b){
                a--;b--;
                count++;
            }
            if(a&&c){
                a--;
                c--;
                count++;
            }
            if(c&&b){
                b--;c--;
                count++;
            }
            if(a&&b&&c){
                a--;
                b--;
                c--;
                count++;
            }
            cout<<count<<endl;
        }
    }