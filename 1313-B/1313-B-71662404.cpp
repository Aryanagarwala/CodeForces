#include <iostream>
    #include <queue>

#include <algorithm>
#include <fstream>
#include <map>
#define eq 10000
#define int long long
#define MOD 1000000007
    using namespace std;
    int32_t main(){
        int t;
        cin>>t;
        while(t--){
            int n, x, y;
            cin>>n>>x>>y;
            if(x<y) swap(x, y);
            int ourscore = (x+y);
            int l = 1;
            int u = n;
            int ansmin = n+1, ansmax = 0;
            while(u>=l){
                int m = (l+u)/2;
                int peoplewhobeat = m-1;
                int peopletobeat = (x-1) - peoplewhobeat;
                if(peopletobeat<=0){
                    ansmin = min(ansmin, m);
                    u = m-1;
                    continue;
                }
                int bestscore = (x-1) + (n-(peopletobeat-1 - (y==n?1:0)));
                if((bestscore)<=ourscore){
                    l = m+1;
                    continue;
                }
                else{
                    ansmin = min(ansmin, m);
                    u = m-1;
                    continue;
                }
            }
            l = 1;
            u = n;
            while(u>=l){
                int m = (l+u)/2;
                int peoplewhobeat = m-1;
                int worstinx = (x<=(peoplewhobeat)?1:0) + peoplewhobeat;
                int bestinx = x==1?2:1;
                int worstiny = (y<=(peoplewhobeat)?1:0) + peoplewhobeat;
                int bestiny = y==1?2:1;
                int overallworst = max(worstinx + bestiny, bestinx + worstiny);
                if(overallworst>ourscore){
                    u = m-1;
                }
                else{
                    l = m+1;
                    ansmax = max(m, ansmax);
                }
            }
            cout<<ansmin<<" "<<ansmax<<endl;
        }
    }