#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9; // A large constant to represent infinity

int n, m; // Number of computers and connections
vector<vector<int>> graph; // Adjacency list to represent connections
vector<int> dist; // Renamed from "distance" to avoid ambiguity
vector<int> parent; // To reconstruct the route

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    parent[start] = -1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current]) {
            if (dist[neighbor] == INF) {
                dist[neighbor] = dist[current] + 1;
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    graph.resize(n + 1);
    dist.assign(n + 1, INF);
    parent.assign(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // If the graph is undirected
    }

    bfs(1); // Start BFS from Uolevi's computer (computer 1)

    if (dist[n] == INF) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << dist[n] + 1 << '\n'; // Minimum number of computers on the route

        vector<int> route;
        int current = n;
        while (current != -1) {
            route.push_back(current);
            current = parent[current];
        }

        for (int i = route.size() - 1; i >= 0; i--) {
            cout << route[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
