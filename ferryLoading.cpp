#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main(){
  int n;
  cin >> n;
  while(n--){
    int ferryLength;
    cin >> ferryLength;
    ferryLength *= 100;
    int cars;
    cin >> cars;
    queue<int> left;
    queue<int> right;
    while(cars--){
      int length;
      string bank;
      cin >> length >> bank;
      if(bank=="left"){
        left.push(length);
      }else{
        right.push(length);
      }
    }
    int turn = 0;
    bool atleft =true;
    while(!left.empty() || !right.empty()){
      int loaded =0;
      if(atleft){
        while(!left.empty() && loaded+left.front()<=ferryLength){
          loaded += left.front();
          left.pop();
        }
      }else{
        while(!right.empty() && loaded+right.front()<=ferryLength){
          loaded += right.front();
          right.pop();
        }
      }

      atleft = !atleft;
      turn++;
    }
    cout << turn << endl;
  }
}