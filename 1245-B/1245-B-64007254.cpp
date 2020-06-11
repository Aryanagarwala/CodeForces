#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#define map unordered_map
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a, b, c;
        cin>>a>>b>>c;
        map<char, int> have;
        have['R'] = a;
        have['P'] = b;
        have['S'] = c;
        map<char, int> bob;
        map<char, char> attack;
        attack['P'] = 'S';
        attack['S'] = 'R';
        attack['R'] = 'P';
        string s;
        cin>>s;
        for(int i =0 ;i<n;i++) {
            bob[s[i]]++;
        }
        map<char, int> need;
        need['P'] = min(have['P'], bob['R']);
        need['S'] = min(have['S'], bob['P']);
        need['R'] = min(have['R'], bob['S']);
        if(need['P'] + need['S'] + need['R'] < (n/2 + (n%2))){
            cout<<"NO"<<endl;
            continue;
        }
        else{
            cout<<"YES"<<endl;
            bob['R'] = have['R'] - need['R'];
            bob['P'] = have['P'] - need['P'];
            bob['S'] = have['S'] - need['S'];
            for(int i = 0;i<n;i++){
                if(need[attack[s[i]]]){
                    cout<<attack[s[i]];
                    need[attack[s[i]]]--;
                }
                else{
                    if(bob['R']){
                        cout<<'R';
                        bob['R']--;
                    }
                    else if(bob['P']){
                        cout<<'P';
                        bob['P']--;
                    }
                    else{
                        cout<<'S';
                        bob['S']--;
                    }
                }
            }
            cout<<endl;
        }
    }
}