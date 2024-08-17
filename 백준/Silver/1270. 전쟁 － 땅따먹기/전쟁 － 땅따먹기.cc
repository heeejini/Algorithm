#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

int area;

void solve(vector<ll> arr, map<ll, int> army) {
    int max_count = 0;
    ll winner = -1;

    for (auto it = army.begin(); it != army.end(); ++it) {
        if (it->second > max_count) {
            max_count = it->second;
            winner = it->first;
        }
    }

    if (max_count > area / 2) {
        cout << winner;
    } else {
        cout << "SYJKGW";
    }

    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++) {
        cin >> area;

        vector<ll> arr(area);
        map<ll, int> army;
        for (int j = 0; j < area; j++) {
            cin >> arr[j];
            army[arr[j]]++;
        }

        solve(arr, army);
    }

    return 0;
}
