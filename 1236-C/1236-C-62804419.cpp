#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin>>n;
    int gtype[n][n];
    int type = pow(n, 2);
    for(int i = 0;i<n;i++){
        int yo = i;
        for(int j = 0;j<n;j+=2){
            gtype[i][j] = type-yo;
            if((type-yo)!=(1+yo)) gtype[i][j+1] = 1 + yo;
            else j--;
            yo+=n;
        }
    }
    for(int i =0 ;i<n;i++){
        for(int j = 0;j<n;j++) cout<<gtype[i][j]<<" ";
        cout<<endl;
    }
}