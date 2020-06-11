#include <iostream>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
long double a[(int)(1e5 + 10)];
int n;
int distance(int i, int j){
    if(j<i) return (n-i) + j;
    else return (j-i);
}
int main() {
    cin>>n;
    long double maxi = -1;
    long double mini = 1e10;
    for(int i = 0;i<n;i++){
        cin>>a[i];
        maxi = max(maxi, a[i]);
        mini = min(mini, a[i]);
    }
    if(mini>=(maxi/2.0)){
        for(int i = 0;i<n;i++) cout<<-1<<" ";
        cout<<endl;
        return 0;
    }
    bool vis[n];
    for(int i = 0;i<n;i++) vis[i] = false;
    int ans[n];
    deque<pair<long double, pair<int, int>>> st;
    st.push_front(make_pair(a[0], make_pair(0,  0)));
    for(int j = 1;j<(3*n + (5));j++){
        int i = (j%n);
        while(!st.empty() && (a[i]<(st.back().first/2.0))){
            for(int k = st.back().second.first, lol = 0;lol <= distance(st.back().second.first, st.back().second.second);(++k%n), lol++){
                k%=n;
                ans[k] = distance(k, st.back().second.second) + distance(st.back().second.second, i);
            }
            st.pop_back();
        }
        int count = 1;
        while(!st.empty() && (a[i]>(st.front().first))){
            count+= (st.front().second.second - st.front().second.first+1);
            st.pop_front();
        }
        st.push_front(make_pair(a[i], make_pair((i-count+1+n)%n, i)));
    }
    for(int i = 0;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}