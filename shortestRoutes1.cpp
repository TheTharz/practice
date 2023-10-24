#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
const long long INF = LLONG_MAX;
int main(){
  int n,m;
  cin >>n >> m;

  vector<vector<pair<int,int>>> graph(n+1);

  for(int i=0;i<m;i++){
    int a,b,c;
    cin >>a >>b >>c;
    graph[a].push_back({b,c});
  }

  vector<long long> shortestPath(n+1,INF);
  shortestPath[1] = 0;

  priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;

  pq.push({0,1});

  while(!pq.empty()) {
    long long dist = pq.top().first;
    int city = pq.top().second;
    pq.pop();

    if(dist < shortestPath[city]){
      continue;
    }

    for(pair<int,int> flight: graph[city]){
      int neighbor = flight.first;
      int flightLength = flight.second;

      if(shortestPath[city] + flightLength < shortestPath[neighbor]){
        shortestPath[neighbor] = shortestPath[city] + flightLength;
        pq.push({shortestPath[neighbor], neighbor});
      }
    }
  }

  for(int i = 1; i <= n; i++){
    cout << shortestPath[i] << " ";
  }


}