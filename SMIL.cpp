#include <iostream>
#include <string>

using namespace std;
int main () {
  string s;
  getline(cin,s);
  for(int i = 0 ;i<s.length();i++) {
    if((s[i]==':'||s[i]==';') && (s[i+1]==')'||(s[i+1]=='-'&&s[i+2]==')'))){
      cout<<i<<endl;
    }
  }
}