#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

int n, m;
int parent[1000001];

// 부모 노드 찾기
int getParent(int x) {
    // 부모를 찾아주는 함수
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

// 두 부모 노드를 작은 것으로 합치는 함수
void unionParent(int x, int y) {
    // 합쳐주는 함수
    x = getParent(x);
    y = getParent(y);
    if (x > y) parent[x] = y;
    else parent[y] = x;
}

void findParent(int x, int y) {
    x = getParent(x);
    y = getParent(y);
    if (x == y) cout << "yes\n";
    else cout << "no\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m; // m은 입력으로 주어지는 연산의 개수 

    // parent 배열 초기화
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int calc; // 0 or 1
    int a, b;
    
    for (int i = 0; i < m; i++) {
        cin >> calc >> a >> b;
        if (calc == 0) {
            // 두 집합을 합친다.
            unionParent(a, b);
        } else {
            // 1일 때, 확인하기
            findParent(a, b);
        }
    }

    return 0;
}
