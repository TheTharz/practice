#include <iostream>
using namespace std;
int main(){
  int n;
  cin>>n;

  int days = 0;
  int printers = 1;
  while(printers < n){
    printers *= 2;
    days++;
  }

  cout << days+1 << endl;
}