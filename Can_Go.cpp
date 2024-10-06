#include <bits/stdc++.h>
using namespace std;

char graph[1001][1001];
bool visited[1001][1001];
int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && (graph[x][y] == '.' || graph[x][y] == 'B') && !visited[x][y]);
}

bool bfs(int sX, int sY, int eX, int eY) {
    queue<pair<int, int>> q;

    memset(visited, false, sizeof(visited));

    q.push({sX, sY});
    visited[sX][sY] = true;

    while (!q.empty()) {
        pair<int,int> parent = q.front();
        int x = parent.first;
        int y = parent.second;
        q.pop();

        if (x == eX && y == eY) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nX = x + dx[i];
            int nY = y + dy[i];

            if (isValid(nX, nY)) {
                visited[nX][nY] = true;
                q.push({nX, nY});
            }
        }
    }

    return false;
}

int main() {
    cin >> n >> m;

    pair<int, int> start, end;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];

            if (graph[i][j] == 'A') {
                start = {i, j};
            } else if (graph[i][j] == 'B') {
                end = {i, j};
            }
        }
    }

    if (bfs(start.first, start.second, end.first, end.second)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}