#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> ticketPrices(n);
    for (int i = 0; i < n; i++) {
        cin >> ticketPrices[i];
    }

    sort(ticketPrices.begin(), ticketPrices.end());

    vector<int> results(m);

    for (int i = 0; i < m; i++) {
        int maxPrice;
        cin >> maxPrice;

        int ticketIndex = lower_bound(ticketPrices.begin(), ticketPrices.end(), maxPrice) - ticketPrices.begin();

        if (ticketIndex < n && ticketPrices[ticketIndex] <= maxPrice) {
            results[i] = ticketPrices[ticketIndex];
            ticketPrices.erase(ticketPrices.begin() + ticketIndex);
        } else {
            results[i] = -1;
        }
    }

    for (int i = 0; i < m; i++) {
        cout << results[i] << endl;
    }

    return 0;
}
