#include<bits/stdc++.h>
using namespace std;
char a[20][30];
bool vis[10][10];
int dis[10][10];
vector<pair<int, int>>d={{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=n) return false;
    return true;
}

void bfs(int si, int sj){
  queue<pair<int, int>>q;
  q.push({si, sj});
  vis[si][sj] =true;
  dis[si][sj] =0;

  while(!q.empty()){
    pair<int, int>par=q.front();
    q.pop();
    cout<<par.first<<" "<<par.second<<endl;
   for(int i; i<4; i++){
     int ci=par.first + d[i].first;
     int cj=par.second + d[i].second;
     if(valid(ci, cj)==true && vis[ci, cj]==false){
       q.push({ci, cj});
       vis[ci] [cj] = true;
       dis[ci][cj] = dis[par.first][par.second]+1;

     }
   } 
  }
};
 
int main(){
    int n, m;
     cin>>n>>m;
    for(int i; i<n; i++){
        for(int j; j<m; j++){
            cin>>a[i][j];
        }
    };
  
    int si, sj;
    cin>>si>>sj;
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    bfs(si, sj);
    return 0;
}