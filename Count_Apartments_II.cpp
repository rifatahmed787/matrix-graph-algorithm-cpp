#include <bits/stdc++.h>
using namespace std;

char graph[1001][1001]; 
bool visited[1001][1001];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n, m;

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && graph[x][y] == '.' && !visited[x][y]);
}

int dfs(int x, int y) {
    visited[x][y] = true;
    int count = 1;

    for (int i = 0; i < 4; i++) {
        int nX = x + dx[i];
        int nY = y + dy[i];

        if (isValid(nX, nY)) {
            count += dfs(nX, nY);
        }
    }

    return count;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> rooms;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == '.' && !visited[i][j]) {
                int roomCount = dfs(i, j);
                rooms.push_back(roomCount);
            }
        }
    }

    if (rooms.empty()) {
        cout << 0 << endl;
    } else {
        sort(rooms.begin(), rooms.end());
        for (int count : rooms) {
            cout << count << " ";
        }
        cout << endl;
    }

    return 0;
}