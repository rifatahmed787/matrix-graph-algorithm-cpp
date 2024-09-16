#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n, e;
    cin>>n >> e;
    vector<int>mat[n];
    while(e--){
        int a, b;
        cin>>a>>b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }

    for(int x:mat[4]){
        cout<<x<<" "<<endl;
    }
    // another format for output
    for(int i; i<mat[4].size(); i++){
        cout<<mat[0][i]<<" "<<endl;
    }
    return 0;
}