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
    }
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        
        if (a == b) {
            cout << "YES" << endl;
        }
        else {
            bool found = false;
            for (int chi : graph[a]) {
                if (chi == b) {
                    found = true;
                    break;
                }
            }
            
            if (found) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    
    return 0;
}