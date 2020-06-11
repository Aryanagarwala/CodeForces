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
        int n, m, k;
        cin>>n>>m>>k;
        for(int i = 0;i<k;i++) {
            int a;
            cin >> a >> a;
        }
        for(int i = 0;i<k;i++){
            int a;
            cin>>a>>a;
        }
        string ans = "";
        for(int i = 0;i<(n-1);i++){
            ans+="U";
        }
        for(int i = 0;i<(m-1);i++){
            ans+="R";
        }
        for(int i = 0;i<m;i++){
            if(i%2==0){
                for(int j = 0;j<(n-1);j++){
                    ans+="D";
                }
            }
            else{
                for(int j = 0;j<(n-1);j++){
                    ans+="U";
                }
            }
            ans+="L";
        }
        cout<<ans.length()<<endl;
        cout<<ans<<endl;
    return 0;
}