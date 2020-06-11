#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
//find an unused prince such that his index is lower than the used one
//now, the prince actually used by that princess will go unused and a princess after her can use it.
//this ripple effect has to continue until we find someone that did not use a prince and can now use
//dp?
int n;
bool taken[1000000];
int used[1000000];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        queue<int> p[n];
        for(int i = 0;i<n;i++){
            int k;
            cin>>k;
            for(int j = 0;j<k;j++){
                int pr;
                cin>>pr;
                p[i].push(pr);
            }
        }
        for(int i = 0;i<=n;i++) taken[i] = false;
        int index = -1;
        for(int i = 0;i<n;i++){
            while(!p[i].empty() && taken[p[i].front()]){
                p[i].pop();
            }
            if(p[i].empty()){
                index = i+1;
                continue;
            }
            taken[p[i].front()] = true;
        }
        int unused =0;
        for(int i = 1;i<=n;i++){
            if(!taken[i]) unused = i;
        }
        if(index==-1){
            cout<<"OPTIMAL\n";
            continue;
        }
        cout<<"IMPROVE\n";
        cout<<index<<" "<<unused<<"\n";
    }
    return 0;
}