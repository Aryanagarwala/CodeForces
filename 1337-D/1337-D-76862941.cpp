#include <bits/stdc++.h>
#define int long long
#define mid(l, u) ((l+u)/2)
#define test(a) tryCombination(a);
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
using namespace std;
int el;
const int N = 3e18;
int sq(int a){
    return a*a;
}
int compute(int a ,int b, int c){
    int sum = 0;
    sum+=sq(c-a);
    sum+=sq(b-a);
    sum+=sq(c-b);
    return sum;
}
int bigger(int a, vector<int> &ab){
    auto it = lower_bound(ab.begin(), ab.end(), a);
    if(it==ab.end()) return -1;
    return (*it);
}
int smaller(int a, vector<int> &ab){
    auto it = upper_bound(ab.begin(), ab.end(), a);
    if(it==ab.begin()) return -1;
    it--;
    return (*it);
}
int mini;
vector<int> a1, a2, a3;
void check(int curr, int pivot){
    int a = bigger(pivot, a2);
    int b = smaller(pivot, a2);
    int c = bigger(pivot, a3);
    int d = smaller(pivot, a3);
    if(a!=-1 && c!=-1) mini = min(mini, compute(curr, a, c));
    if(b!=-1 && d!=-1) mini = min(mini, compute(curr, b, d));
    if(a!=-1 && d!=-1) mini = min(mini, compute(curr, a, d));
    if(b!=-1 && c!=-1) mini = min(mini, compute(curr, b, c));
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n1, n2, n3;
        cin>>n1>>n2>>n3;
        mini = N;
        a1.clear();
        a2.clear();
        a3.clear();
        for(int i = 0;i<n1;i++){
            cin>>el;
            a1.push_back(el);
        }
        for(int i = 0;i<n2;i++){
            cin>>el;
            a2.push_back(el);
        }
        for(int i = 0;i<n3;i++){
            cin>>el;
            a3.push_back(el);
        }
        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end());
        sort(a3.begin(), a3.end());
        for(int i = 0;i<n1;i++){
            int curr = a1[i];
            check(curr, curr);
            //checking bigger
            if(bigger(curr, a2)!=-1 && bigger(curr, a3)!=-1) {
                int lol = max(bigger(curr, a2), bigger(curr, a3));
                lol = mid(lol, curr);
                check(curr, lol);
            }
            //checking smaller
            if(smaller(curr, a2)!=-1 && smaller(curr, a3)!=-1) {
                int lol = min(smaller(curr, a2), smaller(curr, a3));
                lol = mid(lol, curr);
                check(curr, lol);
            }
        }
        cout<<mini<<endl;
    }
}