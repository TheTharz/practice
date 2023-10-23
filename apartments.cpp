#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> applicants(n);
    vector<int> apartments(m);

    for (int i = 0; i < n; i++) {
        cin >> applicants[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> apartments[i];
    }

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int applicantsAllocated = 0;
    int apartmentIndex = 0;

    for (int i = 0; i < n; i++) {
        int applicantSize = applicants[i];

        while (apartmentIndex < m && apartments[apartmentIndex] + k < applicantSize) {
            apartmentIndex++;
        }

        if (apartmentIndex < m && abs(applicantSize - apartments[apartmentIndex]) <= k) {
            applicantsAllocated++;
            apartmentIndex++;
        }
    }

    cout << applicantsAllocated << endl;

    return 0;
}
