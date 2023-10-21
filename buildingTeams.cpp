#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9; // A large constant to represent infinity

int n, m; // Number of pupils and friendships
vector<vector<int>> graph; // Adjacency list to represent friendships
vector<int> team; // To assign pupils to teams

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    team[start] = 1; // Start by assigning the first pupil to team 1

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int f : graph[current]) {
            if (team[f] == team[current]) {
                return false; // Friends are in the same team, impossible
            }

            if (team[f] == 0) {
                team[f] = 3 - team[current]; // Assign the friend to the other team
                q.push(f);
            }
        }
    }

    return true;
}

int main() {
    cin >> n >> m;
    graph.resize(n + 1);
    team.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // If the graph is undirected
    }

    for (int i = 1; i <= n; i++) {
        if (team[i] == 0 && !bfs(i)) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << team[i] << ' '; // Assign pupils to teams
    }
    cout << '\n';

    return 0;
}
