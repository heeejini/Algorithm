#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    
    vector<int> tree(n);
    
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
    }
    
    sort(tree.rbegin(), tree.rend()); 

    int gcd = tree[0] - tree[1];
    
    for (int i = 1; i < n - 1; i++) {
        int dist = tree[i] - tree[i + 1];
        gcd = __gcd(gcd, dist);
    }
    
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        int dist = tree[i] - tree[i + 1];
        cnt += (dist / gcd) - 1; 
    }

    cout << cnt ;

    return 0;
}
