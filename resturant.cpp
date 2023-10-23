#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n;
  cin >> n;
  int temp;
  vector<pair<int,char>> events;
  for(int i=0; i<n; i++){
    cin>>temp;
    events.push_back({temp,'A'});
    cin >> temp;
    events.push_back({temp,'D'});
  }
  sort(events.begin(), events.end());

  int current = 0;
  int maxCustomer = 0;

  for(const auto& event : events){
    if(event.second == 'A'){
      current++;
    }else{
      current--;
    }
    maxCustomer = max(maxCustomer, current);
  }

  cout << maxCustomer << endl;
}