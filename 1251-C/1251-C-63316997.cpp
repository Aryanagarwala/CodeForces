#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.length();
        int a[n];
        vector<int> even;
        vector<int> odd;
        for(int i =0 ;i<n;i++){
            a[i] = s[i]-48;
            if(a[i]%2) odd.push_back(a[i]);
            else even.push_back(a[i]);
        }
        int index = 0;
        int i = 0, j = 0;
        while(i<even.size() && j<odd.size()){
            if(even[i]<odd[j]){
                a[index] = even[i];
                i++;
            }
            else{
                a[index] = odd[j];
                j++;
            }
            index++;
        }
        while(i<even.size()){
            a[index] = even[i];
            i++;
            index++;
        }
        while(j<odd.size()){
            a[index] = odd[j];
            j++;
            index++;
        }
        for(int k = 0;k<n;k++){
            cout<<a[k];
        }
        cout<<endl;
    }
}