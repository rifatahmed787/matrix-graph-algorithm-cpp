#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<int>> graph(n);
    
    for (int i = 0; i < e; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y); 
        graph[y].push_back(x); 
    }
    
    int q;
    cin >> q;
  
    while (q--) {
        int x;
        cin >> x;
        

        if (graph[x].empty()) {
            cout << "-1" << endl;
        } else {

            sort(graph[x].begin(), graph[x].end(), greater<int>());

            for (int chi : graph[x]) {
                cout << chi << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}