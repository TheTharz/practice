#include <iostream>
#include <algorithm>
using namespace std;
int main (){
  int n;
  cin >> n;
  int *array = new int[n];
  for(int i = 0; i < n; i++){
    cin >> array[i];
  }
  int alice = 0;
  int bob = 0;
  sort(array, array+n);

  for(int i=0;i<n;i++){
    if(i%2==0){
      alice+=array[n-i-1];
    }
    else{
      bob+=array[n-i-1];
    }
  }

  cout << alice << " " << bob << endl;
}