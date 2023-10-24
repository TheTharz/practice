#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<pair<int,int>> time;
  for(int i = 0; i < n; i++){
    int a;
    int b;
    cin >> a >> b;
    time.push_back({b,a});
  }

  sort(time.begin(), time.end());

  int count = 0;
  int lastEndTime = -1;

  for(int i = 0; i < time.size();i++){
    if(time[i].second >= lastEndTime){
      count++;
      lastEndTime = time[i].first;
    }
  }

  cout << count << endl;


}