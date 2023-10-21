#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> graph;
vector<int> path;
set<int> visited;
int startCity;

void dfs(int currentCity) {
    visited.insert(currentCity);
    path.push_back(currentCity);

    for (int neighbor : graph[currentCity]) {
        if (neighbor == startCity && path.size() >= 3) {
            // Found a valid round trip
            path.push_back(neighbor);
            cout << path.size() << endl;
            for (int city : path) {
                cout << city << ' ';
            }
            cout << endl;
            exit(0);
        }
        if (!visited.count(neighbor)) {
            dfs(neighbor);
        }
    }

    visited.erase(currentCity);
    path.pop_back();
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // If the graph is undirected
    }

    for (int i = 1; i <= n; i++) {
        startCity = i;
        dfs(i);
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
