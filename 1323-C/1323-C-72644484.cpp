#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>
#define double long double
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
#define mid(l, u) ((l+u)/2)
#define int long long
using namespace std;
int32_t main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int arr[n];
    int lol = 0;
    for(int i = 0;i<n;i++){
        if(s[i]=='(') arr[i]=1;
        else arr[i]=-1;
        lol+=arr[i];
    }
    if(lol!=0){
        cout<<-1<<endl;
        return 0;
    }
    int sum = 0;
    int ans = 0;
    for(int i = 0;i<n;i++){
        sum+=arr[i];
        if(sum>=0) continue;
        int j = i+1;
        while(j<n && sum!=0){
            sum+=arr[j++];
        }
        ans+=(j-i);
        //cout<<i<<" "<<j<<endl;
        i = j-1;
    }
    cout<<ans<<endl;
}