#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    deque<int> dq;

    // fifo first in first out  1 2 3 4 5  -> 5 부터 나감 # 큐

    // fiLo first input last out 1 2 3 4 5 -> 1
    
    // 덱 : 앞 뒤로 다 뺄 수 있음
    int n, t;
    cin >> n >> t;

    int temp;
    for(int i=0; i<2*n; i++){
        cin >> temp;
        dq.push_back(temp);
    }

    vector<int> num;
    // 교선이가 부르는 수
    num.resize(t,0);
    int kosun;
    for(int i=0; i<t; i++){
        cin >> num[i];
    }

    for(int i=0; i<t; i++){
        // 게임 진행 
        for (int j = 0; j < num[i] - 1; j++) {
            int bottom = dq.front();
            dq.pop_front();
            dq.push_back(bottom);
        }

        // b[i]번째에서 맨 아래 손이 패배
        int loser = dq.front();
        cout << loser << " ";
    }
    return 0;
}