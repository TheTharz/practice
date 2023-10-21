#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m; // Height and width of the map
vector<string> labyrinth; // Labyrinth map
vector<vector<bool>> visited; // Keep track of visited cells
vector<vector<pair<int, int>> > parent; // Store the parent cell for each cell
string directions; // Store the path as a string

// Define the four possible directions (up, down, left, right)
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const char dir[] = {'U', 'D', 'L', 'R'};

bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && labyrinth[x][y] != '#' && !visited[x][y];
}

void bfs(int start_x, int start_y) {
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        int x = current.first;
        int y = current.second;

        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (is_valid(new_x, new_y)) {
                visited[new_x][new_y] = true;
                parent[new_x][new_y] = {x, y};
                q.push({new_x, new_y});

                if (labyrinth[new_x][new_y] == 'B') {
                    // We reached the end, construct the path
                    directions = "";
                    while (new_x != start_x || new_y != start_y) {
                        int px = parent[new_x][new_y].first;
                        int py = parent[new_x][new_y].second;

                        for (int j = 0; j < 4; j++) {
                            if (px + dx[j] == new_x && py + dy[j] == new_y) {
                                directions = dir[j] + directions;
                                break;
                            }
                        }

                        new_x = px;
                        new_y = py;
                    }
                    return;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    labyrinth.resize(n);
    visited.assign(n, vector<bool>(m, false));
    parent.assign(n, vector<pair<int, int>>(m, {-1, -1}));

    for (int i = 0; i < n; i++) {
        cin >> labyrinth[i];
    }

    int start_x, start_y;

    // Find the starting position (A)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (labyrinth[i][j] == 'A') {
                start_x = i;
                start_y = j;
                break;
            }
        }
    }

    bfs(start_x, start_y);

    if (!directions.empty()) {
        cout << "YES\n";
        cout << directions.size() << '\n' << directions << '\n';
    } else {
        cout << "NO\n";
    }

    return 0;
}
