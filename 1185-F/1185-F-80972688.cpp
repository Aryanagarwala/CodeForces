#include <bits/stdc++.h>
#define INF 10000000000000000
#define MOD 1000000017
#define mid(l, u) ((l+u)/2)
#define rchild(i) (i*2 + 2)
#define lchild(i) (i*2 + 1)
#define rr mt_rand()
#define int long long
using namespace std;
int cnt = 0;
bool inp(int l, int u){
    cout<<l<<" "<<u<<endl;
    string s;
    cin>>s;
    if(s=="Yes") return true;
    return false;
}
signed main(){
    mt19937 mt_rand(time(0));
    int n, m;
    cin>>n>>m;
    int freq[1024], cnt[1024];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> price[1024];
    pair<int, pair<int, int>> lol[1024];
    for(int i = 0;i<1024;i++){
        freq[i] = 0;
        cnt[i] = 0;
        lol[i] = {INF, {-1, -1}};
    }
    for(int i = 0;i<n;i++){
        int f;
        cin>>f;
        int curr = 0;
        for(int j = 0;j<f;j++){
            int num;
            cin>>num;
            curr|=((int)pow(2, num-1));
        }
        freq[curr]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i = 0;i<m;i++){
        int c, f;
        cin>>c>>f;
        int curr = 0;
        for(int j = 0;j<f;j++){
            int num;
            cin>>num;
            curr|=((int)pow(2, num-1));
        }
        cnt[curr]++;
        pq.push(make_pair(c, i+1));
        price[curr].push(make_pair(c, i+1));
    }
    pair<int, int> ans = {1, 2};
    for(int i = 0;i<1024;i++){
        if(cnt[i]==0) continue;
        for(int j = 0;j<1024;j++){
            if(cnt[j]==0) continue;
            if(i==j && cnt[i]==1) continue;
            int comb = i|j;
            if(i==j){
                pair<int, int> temp = price[i].top();
                price[i].pop();
                pair<int,int> temp1 = price[i].top();
                price[i].push(temp);
                if(lol[comb].first<(temp.first + temp1.first)) continue;
                lol[comb] = make_pair(temp.first + temp1.first, make_pair(temp.second, temp1.second));
            }
            else{
                pair<int, int> temp = price[i].top();
                pair<int, int> temp1 = price[j].top();
                if(lol[comb].first<(temp.first + temp1.first)) continue;
                lol[comb] = make_pair(temp.first + temp1.first, make_pair(temp.second, temp1.second));
            }
        }
    }
    int tans = 0;
    int cost = INF;
    for(int i =0 ;i<1024;i++){
        if(lol[i].first>=INF) continue;
        //cout<<i<<" "<<lol[i].first<<" "<<lol[i].second.first<<" "<<lol[i].second.second<<endl;
        int count = 0;
        for(int j = 0;j<1024;j++){
            if((i&j)==j) count+=freq[j];
        }
        //cout<<count<<endl;
        if(count>tans || (count==tans && lol[i].first<cost)){
            tans = count;
            cost = lol[i].first;
            ans = lol[i].second;
        }
    }
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}
//l, mid(l, r) || l+1, r
//