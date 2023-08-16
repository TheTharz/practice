#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  string s ;
  getline(cin, s);
  int c = 0;
  vector<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
  for(int i=0;i<vowels.size();i++){
    char check = vowels[i];
    c += count(s.begin(),s.end(),check);
  }
  cout << c << endl;
}