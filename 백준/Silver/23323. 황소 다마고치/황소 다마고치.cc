#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

void solve() {
    ll health, feed;
    cin >> health >> feed;

    int days = 0;
    while(health !=0){ 
        health/=2;
        days++;
    }
    cout << days + feed << "\n"; // 먹이를 1개씩 주는 게 이득, 따라서 먹이 갯수만큼 더해주기
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int tc; // 테스트 케이스 
    cin >> tc;

    for (int i = 0; i < tc; i++) {
        solve();
    }
    
    return 0;
}
