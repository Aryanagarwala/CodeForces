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
    int n, m, k;
    cin>>n>>m>>k;
    int a[n], b[m];
    int asum[n], bsum[m];
    for(int i =0 ;i<n;i++){
        cin>>a[i];
        asum[i] = a[i];
    }
    for(int i =0 ;i<m;i++){
        cin>>b[i];
        bsum[i] = b[i];
    }
    for(int i = 1;i<n;i++) asum[i]+=asum[i-1];
    for(int j = 1;j<m;j++) bsum[j]+=bsum[j-1];
    int lim = sqrt(k);
    vector<pair<int, int>> f;
    for(int i = 1;i<=lim;i++){
        if(k%i==0){
            f.push_back(make_pair(i, k/i));
            if(i!=(k/i)) f.push_back(make_pair(k/i, i));
        }
    }
    int f1[40005], f2[40005], s1[40005], s2[40005];
    for(int i = 0;i<40005;i++) f1[i] = f2[i] = s1[i] = s2[i] = 0;
    for(int i = 0;i<n;i++){
        if(a[i]!=1) continue;
        int j = i+1;
        while(j<n && a[j]==a[i]) j++;
        f1[(j-i)]++;
        s1[j-i]+=(j-i);
        i = j-1;
    }
    for(int i = 0;i<m;i++){
        if(b[i]!=1) continue;
        int j = i+1;
        while(j<m && b[j]==b[i]) j++;
        f2[(j-i)]++;
        s2[(j-i)]+=(j-i);
        i = j-1;
    }
    for(int i = 40003;i>=0;i--){
        f1[i]+=f1[i+1];
        f2[i]+=f2[i+1];
        s1[i]+=s1[i+1];
        s2[i]+=s2[i+1];
    }
    int count = 0;
    for(pair<int, int> j: f){
        if(j.first>40004 || j.second>40004) continue;
       // cout<<j.first<<" "<<j.second<<" "<<s1[j.first]<<" "<<f1[j.first]<<" "<<s2[j.first]<<" "<<f2[j.first]<<endl;
        int rsize = j.first, csize = j.second;
        int c1 = 0, c2 = 0;
        for(int i = rsize-1;i<n;i++){
            if((asum[i] - (((i-rsize)==-1)?0:asum[i-rsize]))==rsize) c1++;
        }
        for(int i = csize - 1;i<m;i++){
            if((bsum[i] - (((i-csize)==-1)?0:bsum[i-csize]))==csize) c2++;
        }
        count+=(c1*c2);
    }
    cout<<count<<endl;

}