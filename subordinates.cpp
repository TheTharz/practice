#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 200005;  // Adjust this value as needed, it should be larger than 2 times the maximum number of employees.

int n;  // Number of employees
vector<int> boss[MAXN];  // An adjacency list to represent the hierarchy
int subordinates[MAXN];  // To store the number of subordinates for each employee

void dfs(int node) {
    // Initialize the number of subordinates for the current employee to 1 (the employee itself)
    subordinates[node] = 1;
    
    // Recursively calculate the number of subordinates for each subordinate of the current employee
    for (int i = 0; i < boss[node].size(); i++) {
        int subordinate = boss[node][i];
        dfs(subordinate);
        
        // Add the number of subordinates of this subordinate to the current employee's count
        subordinates[node] += subordinates[subordinate];
    }
}

int main() {
    cin >> n;
    
    // Initialize the adjacency list for the hierarchy
    for (int i = 2; i <= n; i++) {
        int boss_of_i;
        cin >> boss_of_i;
        boss[boss_of_i].push_back(i);
    }
    
    // Calculate the number of subordinates for each employee using depth-first search
    dfs(1);  // Start from the general director (employee 1)
    
    // Output the results
    for (int i = 1; i <= n; i++) {
        cout << subordinates[i] - 1 << " ";  // Subtract 1 to exclude the employee itself
    }
    cout << endl;
    
    return 0;
}
