#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int from, to, weight;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    vector<long long> dist(n, LLONG_MIN);

//this is a comment
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }

    dist[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (const Edge& edge : edges) {
            if (dist[edge.from - 1] != LLONG_MIN) {
                dist[edge.to - 1] = max(dist[edge.to - 1], dist[edge.from - 1] + edge.weight);
            }
        }
    }

    if (dist[n - 1] == LLONG_MIN) {
        cout << -1 << endl; // If it's not possible to reach room n, print -1.
    } else {
        cout << dist[n - 1] << endl; // Otherwise, print the maximum score achievable.
    }

    return 0;
}
