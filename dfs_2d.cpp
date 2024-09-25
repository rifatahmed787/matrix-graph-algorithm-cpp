#include<bits/stdc++.h>
using namespace std;

char a[20][30];
bool vis[20][20];
vector<pair<int, int>>d={{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=n) return false;
    return true;
}
void dfs(int si, int sj){
   cout<<si<<" "<<sj<<endl;
   vis[si][sj]=true;

   for(int i; i<4; i++){
     int ci=si + d[i].first;
     int cj=sj + d[i].second;
     if(valid(ci, cj)==true && vis[ci, cj]==false){
        dfs(ci, cj);
     }
   }
};
 
int main(){
    
    cin>>n>>m;
    for(int i; i<n; i++){
        for(int j; j<m; j++){
            cin>>a[i][j];
        }
    };

    int si, sj;
    dfs(si, sj);
    return 0;
}