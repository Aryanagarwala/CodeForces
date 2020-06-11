#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#define int long long
using namespace std;
int32_t main(){
    vector<int> adj[26];
    bool there[26];
    int inc[26];
    for(int i = 0;i<26;i++) inc[i] =there[i] = 0;
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        int included = 0;
        vector<int> characters;
        for(int j = 0;j<s.length();j++){
            int mask = pow(2, (s[j]-'a'));
            if(mask&included) continue;
            characters.push_back(s[j]-'a');
            included|=mask;
        }
        for(int j: characters){
            there[j] = true;
            for(int k: characters){
                if(j==k) continue;
                int mask = pow(2, k);
                if(inc[j]&mask) continue;
                adj[j].push_back(k);
                inc[j]|=mask;
            }
        }
    }
    bool visited[26];
    for(int i = 0;i<26;i++) visited[i] = false;
    int count = 0;
    for(int i = 0;i<26;i++){
        if(visited[i]) continue;
        if(!there[i]) continue;
        count++;
        visited[i] = true;
        queue<int> bfs;
        bfs.push(i);
        while(!bfs.empty()){
            int node = bfs.front();
            bfs.pop();
            for(int j: adj[node]){
                if(visited[j]) continue;
                visited[j] = true;
                bfs.push(j);
            }
        }
    }
    cout<<count<<endl;
}