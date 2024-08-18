#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define x first
#define y second 

using namespace std;

pii p1, p2, p3, p4;

void solve() {
    // 공통 부분이 없을 경우
    if (p2.x < p3.x || p4.x < p1.x || p2.y < p3.y || p4.y < p1.y) {
        cout << "d\n";
    } 
    // 점일 경우
    else if ((p2.x == p3.x && p2.y == p3.y) || 
             (p1.x == p4.x && p1.y == p4.y) || 
             (p2.x == p3.x && p1.y == p4.y) || 
             (p1.x == p4.x && p2.y == p3.y)) {
        cout << "c\n";
    } 
    // 선분일 경우
    else if (p2.x == p3.x || p1.x == p4.x || p2.y == p3.y || p1.y == p4.y) {
        cout << "b\n";
    } 
    // 직사각형일 경우
    else {
        cout << "a\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    for(int i = 0; i < 4; i++) {
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
        solve();
    }
    return 0;
}
