#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

vector<int> root;

void initialize(int n) {
    root.resize(n+1);
    for (int i = 1; i <= n; ++i) {
        root[i] = i;  // 각 노드는 자기 자신이 부모이다.
    }
}

// find 함수 (경로 압축 적용)
int find(int x) {
    if (root[x] == x) {
        return x;
    } else {
        return root[x] = find(root[x]); 
    }
}

// union 함수
void unionNodes(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA != rootB) {
         root[rootA] = rootB;  // 한 쪽의 루트를 다른 쪽의 루트로 변경
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;

    cin >> n >> m ;
    
    root.resize(n+1);

    initialize(n); // 노드 초기화 

    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        if(find(a)==find(b)){
            cout << i <<"\n";
            return 0;
        }
        else unionNodes(a, b);
    }

    cout << 0 << "\n";
  

    return 0;
}
