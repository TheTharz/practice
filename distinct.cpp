#include <iostream>
#include<set>
using namespace std;
int main(){
  int n;
  cin >> n;
  set<int> set;
  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    set.insert(a);
  }
  cout << set.size() << endl;
}