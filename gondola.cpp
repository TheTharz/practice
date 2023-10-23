#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n,x;
  cin >> n >> x;
  vector<int> weight;
  for(int i=0;i<n;i++){
    int w;
        cin >> w;
        weight.push_back(w);
  }

  sort(weight.begin(), weight.end());
  int left = 0;
  int right = n-1;
  int count = 0;

  while(left <= right){
    if((weight[left] + weight[right]) <= x){
      left++;
      right--;
    }else{
      right--;
    }
    count++;
  }
  cout << count << endl;
}