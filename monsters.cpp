#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x, y;
};

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool canEscape(int n, int m, vector<string>& labyrinth) {
    vector<Point> monsters;
    Point start;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (labyrinth[i][j] == 'A') {
                start = {i, j};
            } else if (labyrinth[i][j] == 'M') {
                monsters.push_back({i, j});
            }
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<Point>> parent(n, vector<Point>(m, {0, 0}));
    queue<Point> q;

    q.push(start);
    visited[start.x][start.y] = true;

    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    string dirs = "DURL";

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        if (cur.x == 0 || cur.x == n - 1 || cur.y == 0 || cur.y == m - 1) {
            vector<char> path;
            while (cur.x != start.x || cur.y != start.y) {
                Point prev = parent[cur.x][cur.y];
                for (int d = 0; d < 4; d++) {
                    if (prev.x + dx[d] == cur.x && prev.y + dy[d] == cur.y) {
                        path.push_back(dirs[d]);
                        break;
                    }
                }
                cur = prev;
            }
            reverse(path.begin(), path.end());

            cout << "YES\n";
            cout << path.size() << "\n";
            for (char c : path) {
                cout << c;
            }
            cout << "\n";

            return true;
        }

        for (int d = 0; d < 4; d++) {
            int newx = cur.x + dx[d];
            int newy = cur.y + dy[d];

            if (isValid(newx, newy, n, m) && !visited[newx][newy] && labyrinth[newx][newy] == '.') {
                bool safe = true;

                for (Point& monster : monsters) {
                    if (monster.x == newx && monster.y == newy) {
                        safe = false;
                        break;
                    }
                }

                if (safe) {
                    q.push({newx, newy});
                    visited[newx][newy] = true;
                    parent[newx][newy] = cur;
                }
            }
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> labyrinth(n);
    for (int i = 0; i < n; i++) {
        cin >> labyrinth[i];
    }

    if (!canEscape(n, m, labyrinth)) {
        cout << "NO\n";
    }

    return 0;
}
