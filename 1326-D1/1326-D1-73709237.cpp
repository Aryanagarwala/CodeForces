#include<bits/stdc++.h>
    #define int long long
#define MOD 998244353
    using namespace std;
    int32_t main(){
        int t;
        cin>>t;
        while(t--){
            string s;
            cin>>s;
            int n = s.length();
            int odd[n];
            int currlen = 1;
            int startind = 0;
            int endind = n;
            int fronlen = 0;
            for(int i =0 ;i<n;i++){
                int j = i-1;
                int k = i+1;
                while(j>=0 && k<n && s[j]==s[k]){
                    j--;
                    k++;
                }
                odd[i] = 2*(i - j - 1) + 1;
                if((j<0 || k>=n) && odd[i]>currlen){
                    currlen = odd[i];
                    if(j<0){
                        startind = k-1;
                        endind = n;
                    }
                    else{
                        startind = -1;
                        endind = j+1;
                    }
                }
            }
            int even[n];
            for(int i = 0;i<(n-1);i++){
                if(s[i]!=s[i+1]){
                    even[i] = 0;
                    continue;
                }
                int j = i-1;
                int k = i+2;
                while(j>=0 && k<n && s[j]==s[k]){
                    j--;
                    k++;
                }
                even[i] = 2*(i - j - 1) + 2;
                if((j<0 || k>=n) && even[i]>currlen){
                    currlen = even[i];
                    if(j<0){
                        startind = k-1;
                        endind = n;
                    }
                    else{
                        startind = -1;
                        endind = j+1;
                    }
                }
            }
            for(int i = 0;i<n;i++){
                fronlen = i+1;
                //start ending at i
                int backlen = 1;
                for(int j = n-1;j>i && backlen;j--){
                    //end ends at j
                    int frontind = (n - j - 1);
                    if(backlen<=fronlen){
                        if(s[frontind]!=s[j]){
                            //cout<<"gah "<<j<<" "<<frontind<<" "<<s[frontind]<<" "<<s[j]<<endl;
                            goto end;
                        }
                    }
                    if(backlen==fronlen){
                        if(fronlen+backlen > currlen){
                            startind = i;
                            endind = j;
                        }
                    }
                    else if(backlen<fronlen){
                        int diff = fronlen - backlen;
                        int midp;
                        if(diff%2){
                            midp = (diff/2) + backlen;
                            if(odd[midp]>=diff){
                                if(fronlen+backlen > currlen){
                                    startind = i;
                                    endind = j;
                                }
                            }
                        }
                        else{
                            midp = (diff/2) + backlen - 1;
                            if(even[midp]>=diff){
                                if(fronlen+backlen > currlen){
                                    startind = i;
                                    endind = j;
                                }
                            }
                        }
                    }
                    else{
                        //cout<<"HEY"<<endl;
                        int diff = fronlen - backlen;
                        diff*=-1;
                        int midp;
                        if(diff%2){
                            midp = (diff/2) + fronlen;
                            midp = n-1 - midp;
                            //cout<<midp<<" "<<odd[midp]<<endl;
                            if(odd[midp]>=diff){
                                if(fronlen+backlen > currlen){
                                    startind = i;
                                    endind = j;
                                }
                            }
                        }
                        else{
                            midp = (diff/2) + fronlen;
                            midp = n-1-midp;
                            if(even[midp]>=diff){
                                if(fronlen+backlen > currlen){
                                    startind = i;
                                    endind = j;
                                }
                            }
                        }
                    }
                   // cout<<i<<" "<<j<<" "<<backlen<<" "<<currlen<<endl;
                    backlen++;
                    currlen = (startind+1) + (n-endind);
                }
                end:
                continue;
            }
            if(currlen==1){
                cout<<s[0]<<endl;
                continue;
            }
            for(int i = 0;i<=startind;i++) cout<<s[i];
            for(int i = endind;i<n;i++) cout<<s[i];
            cout<<endl;
        }
    }
    //(((2^90)%998244353)*512)%998244353