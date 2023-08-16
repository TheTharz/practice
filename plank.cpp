#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> ways(n+1,0);
  ways[0]=1;
  for(int i=1;i<n+1;i++){
    if(i>=1){
      ways[i]+=ways[i-1];
    }
    if(i>=2){
      ways[i]+=ways[i-2];
    }
    if(i>=3){
      ways[i]+=ways[i-3];
    }
  }
  cout << ways[n] << endl;
}