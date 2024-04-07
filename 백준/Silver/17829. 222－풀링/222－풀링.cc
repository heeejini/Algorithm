#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

vector<vector<int>> m;

int solve(int size, int x, int y){
    if(size == 2) {
      vector<int> arr;

      for(int i=x; i<x+size; i++){
        for(int j=y; j<y+size; j++){
          arr.push_back(m[i][j]);
        }
      }
      sort(arr.begin(), arr.end());
      return arr[2];
    }
    else{
      size = size/2;
      vector<int> arr;
      arr.push_back(solve(size, x,y));
      arr.push_back(solve(size, x+size, y));
      arr.push_back(solve(size, x, y+size));
      arr.push_back(solve(size, x+size, y+size));

      sort(arr.begin(), arr.end());
      return arr[2];
    }

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int n;

  cin >> n;
  // m 벡터의 크기를 n x n으로 초기화
  m.resize(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {        
           cin >> m[i][j];
        } 
  }
  
  cout <<  solve(n, 0, 0);
  return 0;
}