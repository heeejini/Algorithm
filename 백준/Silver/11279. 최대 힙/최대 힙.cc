#include<iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

   /*
   1. 배열에 자연수 x를 넣는다 
   2. 배열에서 가장 큰 값을 출력하고, 그 값을 배열에서 제거한다. 
    x가 자연수라면 배열에 x라는 값을 넣는 연산이고, x가 0이라면 
    배열에서 가장 큰 값을 출력하고 그 값을 배열에서 제거

   */

  int n;
  priority_queue<int, vector<int>, less<int>> pq;

  cin >> n;

  for(int i=0; i<n; i++){
        int num;
        cin >> num;

        if(num==0){
            // 배열이 비어있다면 0 출력 
            if(pq.empty()) cout << 0 << "\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        // 출력 갯수-> 0의 갯수만큼 (0이 들어왔을 때의 최대 값을 출력하기)
        else{
            // 자연수가 들어올 경우 x에 넣어주기 
            pq.push(num);
        }
  } 
}