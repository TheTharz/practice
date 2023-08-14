#include <iostream>
#include <string>

using namespace std;
int main(){
  string s;
  cin >> s;

  int occ = s.find_first_of('a');
  string ans = s.substr(occ, s.length() - occ);
  cout << ans << endl;

}