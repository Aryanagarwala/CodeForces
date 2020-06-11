#include <bits/stdc++.h>
#define int long long
#define INF 1000000000000
using namespace std;
int n, m;
char mat[1000][1000];
int final[1000], final1[1000];
int dnc(int lvl, vector<int> &s, int base){
    //cout<<lvl<<" "<<base<<endl;
    if(s.empty()) return (base-1);
    if(lvl>=n){
        for(int k: s){
            final[k] = base;
        }
        return base;
    }
    vector<int> l, e, mo;
    for(int i: s){
        if(mat[lvl][i]=='>') l.push_back(i);
        else if(mat[lvl][i]=='<') mo.push_back(i);
        else e.push_back(i);
    }
    //cout<<lvl<<" calling "<<(lvl+1)<<" "<<base<<" for smaller part with size "<<l.size()<<endl;
    int nbase = dnc(lvl+1, l, base) + 1;
    for(int k: e){
        final[k] = nbase;
    }
    nbase++;
    //cout<<lvl<<" calling "<<(lvl+1)<<" "<<nbase<<" for bigger part with size "<<mo.size()<<endl;
    nbase = dnc(lvl+1, mo, nbase);
    return nbase;
}
signed main(){
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        for(int j = 0;j<m;j++){
            mat[i][j] = s[j];
        }
    }
    vector<int> temp;
    for(int i = 0;i<m;i++) temp.push_back(i);
    dnc(0, temp, 1);
    bool possible = true;
    for(int i = 0;i<n;i++){
        int curr = 1;
        for(int j = 0;j<m;j++){
            if(mat[i][j]=='>') curr = max(curr, final[j]+1);
            if(mat[i][j]=='=') curr = final[j];
            if(mat[i][j]=='<') curr = min(curr, final[j]-1);
        }
        for(int j = 0;j<m;j++){
            //cout<<mat[i][j]<<" "<<" "<<final[j]<<" "<<curr<<endl;
            if(mat[i][j]=='>' && curr<=final[j]) possible = false;
            if(mat[i][j]=='<' && curr>=final[j]) possible = false;
            if(mat[i][j]=='=' && curr!=final[j]) possible = false;
        }
        final1[i] = curr;
    }
    if(!possible){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    set<int> s;
    for(int i = 0;i<n;i++) s.insert(final1[i]);
    for(int i = 0;i<m;i++) s.insert(final[i]);
    map<int, int> val;
    int cval = 1;
    for(int j: s){
        val[j] = cval++;
    }
    for(int i = 0;i<n;i++) cout<<val[final1[i]]<<" ";
    cout<<endl;
    for(int i = 0;i<m;i++) cout<<val[final[i]]<<" ";
    cout<<endl;
}