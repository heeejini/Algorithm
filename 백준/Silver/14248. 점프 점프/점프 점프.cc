#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

vector<int> bridges;
vector<int> vis;

void solve(int n, int loc){

    queue<int> Q;
    Q.push(loc);
    vis[loc]=1;
    int cnt = 1;  // 출발 지점도 포함하므로 1로 초기화

    while(!Q.empty()){
        int cur = Q.front(); Q.pop();

        int right = cur + (bridges[cur] * 1);
        if(right >= 1 && right <= n && vis[right] != 1){
            vis[right] = 1;
            Q.push(right);
            cnt++;
        }

        int left = cur + (bridges[cur] * -1);
        if(left >= 1 && left <= n && vis[left] != 1){
            vis[left] = 1;
            Q.push(left);
            cnt++;
        }
    }

    cout << cnt;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;

    bridges.resize(n+1);
    vis.resize(n+1, 0);  // 방문 배열을 0으로 초기화

    for(int i = 1; i <= n; i++){
        cin >> bridges[i];
    }
    
    int loc;
    cin >> loc; // 현재 위치 입력 받기 

    solve(n, loc);
    
    return 0;
}
