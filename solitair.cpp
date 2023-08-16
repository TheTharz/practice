#include <iostream>
#include <vector>

using namespace std;
int main () {
  int n;
  cin >> n;

  vector<int> array;
  vector<int> remaining;

  for(int i=0;i<n;i++){
    int card;
    cin >> card;
    array.push_back(card);
  }

  for(int card:array){
    if(!remaining.empty() && ((remaining.back() + card )%2==0)){
        remaining.pop_back();
      }else{
        remaining.push_back(card);
      }
  }

  cout << remaining.size() << endl;
}