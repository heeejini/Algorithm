#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

// 초기화 부분
vector<int> root;
vector<int> money;
vector<int> minMoney;
// n은 노드의 개수
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
// 경로 압축
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

    int n, m, k; // 친구 수, 친구 관계 수, 가지고 있는 돈 
    cin >> n >> m >> k;

    money.resize(n+1);
    minMoney.resize(n+1, 1e6);

    for (int i = 1; i <= n; i++) {
        cin >> money[i];
    }

    initialize(n); // 노드 초기화 

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        unionNodes(a, b);
    }

    for (int i = 1; i <= n; i++) {
       // cout << find(i) << " ";
        int idx = find(i);
        minMoney[idx]=min(minMoney[idx], money[i]);    
    }

    int sum=0;
    for(int i=1; i<=n; i++){
        if(minMoney[i]!=1e6){
            sum += minMoney[i];
        }
    }

    if(sum <= k){
        cout << sum <<"\n";
    }
    else cout << "Oh no\n";

    return 0;
}
