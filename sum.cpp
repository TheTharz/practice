#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    unordered_map<int, int> seen;
    
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        
        int complement = x - a;
        
        if (seen.count(complement)) {
            cout << seen[complement] << " " << i << endl;
            return 0;
        }
        
        seen[a] = i;
    }
    
    cout << "IMPOSSIBLE" << endl;
    
    return 0;
}
