#include <bits/stdc++.h>

using namespace std;

#define MAX 200005
#define N 505
#define int long long
vector<bool> isPrime(MAX);
int mat[N][N];
int Next[MAX]; //next[i] stores the first prime >= i
void precompute(){
    for(int z=2;z<MAX;z++){
        if(!isPrime[z]) continue;
        Next[z] = z;
        for(int x=2*z;x<MAX;x+=z) isPrime[x] = false;
    }
}
int findnext(int i){
    if(Next[i]==i) return i;
    return Next[i] = findnext(i+1);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m; cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> mat[i][j];
    }
    for(int i=0;i<MAX;i++) isPrime[i] = true;
    for(int i=0;i<MAX;i++) Next[i] = i+1;
    precompute();
    int ans = 1e16;
    for(int i = 0;i<n;i++){
        int cost = 0;
        for(int j = 0;j<m;j++){
            cost+= findnext(mat[i][j]) - mat[i][j];
        }
        ans = min(ans, cost);
    }
    for(int j = 0;j<m;j++){
        int cost = 0;
        for(int i = 0;i<n;i++){
            cost+= findnext(mat[i][j]) - mat[i][j];
        }
        ans = min(ans, cost);
    }
    cout<<ans<<endl;
}