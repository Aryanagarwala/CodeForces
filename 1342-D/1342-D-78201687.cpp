#include <bits/stdc++.h>
#define int long long
#define INF 1000000000000
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
#define mid(l, u) ((l+u)/2)
using namespace std;
int c[200005], freq[200005], last[200005];
vector<int> l;
int n, k;
int find(int taken){
    int lo = 1, hi = k;
    int lat = -1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(c[mid]>taken){
            lat = max(lat, mid);
            lo = mid+1;
        }
        else hi = mid-1;
    }
    return lat;
}
int findlast(int i){
    if(i<=0) return -1;
    if(last[i]==i) return i;
    return last[i] = findlast(last[i]);
}
signed main(){
    cin>>n>>k;
    int m[n];
    for(int i = 0;i<=k;i++){
        freq[i] = 0;
        last[i] = i-1;
    }
    for(int i = 0;i<n;i++){
        cin>>m[i];
        freq[m[i]]++;
        last[m[i]] = m[i];
    }
    sort(l.begin(), l.end());
    for(int i = 1;i<=k;i++) cin>>c[i];
    int f = 0;
    vector<vector<int>> sol;
    while(f<n){
        int taken = 0;
        bool go = true;
        int ind = sol.size();
        sol.push_back({});
        while(go){
            int latest = find(taken);
            if(latest==-1){
                go = false;
                continue;
            }
            int totake = findlast(latest);
            if(totake<=0){
                go = false;
                continue;
            }
            int cantake = c[totake] - taken;
            //cout<<ind<<" "<<latest<<" "<<totake<<" "<<taken<<" "<<f<<" "<<cantake<<" "<<freq[totake]<<endl;
            while(cantake-- && freq[totake]>0){
                f++;
                taken++;
                freq[totake]--;
                if(freq[totake]==0) last[totake] = totake - 1;
                sol[ind].push_back(totake);
            }
        }
    }
    cout<<sol.size()<<endl;
    for(vector<int> j: sol){
        cout<<j.size()<<" ";
        for(int lol: j){
            cout<<lol<<" ";
        }
        cout<<endl;
    }
}