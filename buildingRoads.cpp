#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<vector<int>>& g, vector<bool>& visited);
void process_cc(int n, int& cc, vector<int>& lead, vector<vector<int>>& g, vector<bool>& visited);

int main() {
    int n, m;
    int cc = 0;
    vector<vector<int>> g; // Correctly defined as vector of vectors
    vector<bool> visited;
    vector<int> lead;

    cin >> n >> m;

    g.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); // If the graph is undirected
    }

    process_cc(n, cc, lead, g, visited);

    cout << cc - 1 << endl;
    if (cc > 1) {
        int u = lead[0];
        int v;
        for (int i = 1; i < cc; ++i) {
            v = lead[i];
            cout << u << " " << v << endl;
            u = v;
        }
    }

    return 0;
}

void dfs(int u, vector<vector<int>>& g, vector<bool>& visited) {
    visited[u] = true;
    for (auto v : g[u]) {
        if (!visited[v]) {
            dfs(v, g, visited);
        }
    }
}

void process_cc(int n, int& cc, vector<int>& lead, vector<vector<int>>& g, vector<bool>& visited) {
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            cc++;
            lead.push_back(i);
            dfs(i, g, visited);
        }
    }
}
