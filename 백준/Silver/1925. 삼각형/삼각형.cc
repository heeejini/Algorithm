#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

vector<pii> points(3);

int distance(pii p1, pii p2) {
    return pow((p2.first-p1.first),2) + pow((p2.second-p1.second),2);
}

int ccw(pii p1, pii p2, pii p3) {
    int s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

    if (s > 0) return 1;
    else if (s == 0) return 0;
    else return -1; 
}

void solve() {
    // 세 점이 일직선 위에 있을 떄
    if(ccw(points[0], points[1], points[2])==0){
        cout << "X";return ;
    }
    // 각 변의 길이 계산
    vector<int> dist(3);
    dist[0] = distance(points[1], points[2]);
    dist[1] = distance(points[2], points[0]);
    dist[2] = distance(points[0], points[1]);

    // 변의 길이 정렬
    sort(dist.begin(), dist.end());

    int lo = dist[0];  // 가장 짧은 변의 제곱
    int mid = dist[1]; // 중간 길이 변의 제곱
    int hi = dist[2];  // 가장 긴 변의 제곱

    // 세 변의 길이가 같으면 정삼각형
    if (lo == mid && mid == hi) {
        cout << "JungTriangle";
    }
    // 두 변의 길이가 같으면
    else if (lo == mid || mid == hi) {
        if (hi > lo + mid) {
            cout << "Dunkak2Triangle";  // 둔각 이등변 삼각형
        } else if (hi == lo + mid) {
            cout << "Jikkak2Triangle";  // 직각 이등변 삼각형
        } else {
            cout << "Yeahkak2Triangle"; // 예각 이등변 삼각형
        }
    }
    // 세 변의 길이가 모두 다르면
    else {
        if (hi > lo + mid) {
            cout << "DunkakTriangle";   // 둔각 삼각형
        } else if (hi == lo + mid) {
            cout << "JikkakTriangle";   // 직각 삼각형
        } else {
            cout << "YeahkakTriangle";  // 예각 삼각형
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(int i = 0; i < 3; i++) {
        cin >> points[i].first >> points[i].second;
    }

    solve();
    return 0;
}
