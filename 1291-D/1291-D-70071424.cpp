#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <fstream>
#include <algorithm>
#include <set>
#define INF 10000000000000000
#define MOD 1000000007
#define mid(l, u) ((l+u)/2)
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
#define int long long
using namespace std;
string s;
/*void permute(string a, int l, int r)
{
    // Base case
    if (l == r) {
        int freq[26][2];
        bool found = false;
        for(int i = 0;i<26;i++) freq[i][0] = freq[i][1] = 0;
        for(int i = 0;i<(a.length()-1);i++){
            freq[a[i]-'a'][0]++;
            freq[s[i]-'a'][1]++;
            bool diff = false;
            for(int j = 0;j<26;j++){
                if(freq[j][0]!=freq[j][1]) diff = true;
            }
            if(!diff){
                found = true;
            }
        }
        if(found) cout<<"SAME"<<endl;
        else cout<<"NOT SAME"<<endl;
    }
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {

            // Swapping done
            swap(a[l], a[i]);

            // Recursion called
            permute(a, l+1, r);

            //backtrack
            swap(a[l], a[i]);
        }
    }
}*/

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    //permute(s, 0, s.length()-1);
    int freq[s.length()+1][26];
    for(int i = 0;i<26;i++) freq[0][i] = 0;
    for(int i = 1;i<=s.length();i++){
        for(int j = 0;j<26;j++){
            freq[i][j] = freq[i-1][j];
        }
        freq[i][s[i-1]-'a']++;
    }
    int q;
    cin>>q;
    while(q--){
        int l, r;
        cin>>l>>r;
        if(l==r){
            cout<<"Yes"<<endl;
            continue;
        }
        int f[26];
        for(int i = 0;i<26;i++) f[i] = freq[r][i] - freq[l-1][i];
        bool f1 = false;
        bool f2 = false;
        bool f3 = false;
        for(int i = 0;i<26;i++){
            if(f[i]>0){
                if(f2) f3 = true;
                if(f1) f2 = true;
                f1 = true;
            }
        }
        if(f3) cout<<"Yes"<<endl;
        else if(f2 && (s[r-1]!=s[l-1])) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
//1 1 2 3 2 1