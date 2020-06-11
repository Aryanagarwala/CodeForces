#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mid(l, u) ((l+u)/2)
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
#define int long long
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> possible;
        for(int i =0 ;i<n;i++) possible.push_back(i);
        int currind = 0;
        string tomake = "";
        while(currind<n){
            char smol = 'z';
            for(int j: possible){
                if((currind+j)>=n){
                    if((n-j)%2==1){
                        smol = min(smol, s[j-1-(currind + j - n)]);
                    }
                    else smol = min(smol, s[currind+j-n]);
                }
                else smol = min(smol, s[currind + j]);
            }
            vector<int> lol;
            for(int j: possible){
                if((currind+j)>=n){
                    if(((n-j)%2==1) && s[j-1-(currind - (n-j))]==smol){
                        lol.push_back(j);
                    }
                    else if((n-j)%2==0 && s[currind+j-n]==smol) lol.push_back(j);
                }
                else if(s[currind+j] == smol) lol.push_back(j);
            }
            possible.clear();
            for(int j: lol) possible.push_back(j);
            currind++;
            tomake+=smol;
        }
        cout<<tomake<<endl;
        sort(possible.begin(), possible.end());
        cout<<(possible[0]+1)<<endl;
    }
}