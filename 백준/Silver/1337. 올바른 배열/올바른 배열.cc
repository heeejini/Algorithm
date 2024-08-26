#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

int n;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;
    arr.resize(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int ans = 4; // 최대 갯수는 4개가 된다.
    sort(arr.begin(), arr.end());

    for (int start = 0; start < n; start++) {
        int end = n - 1;

        while (start < end) {
            if (arr[end] - arr[start] > 4) {
                end -= 1;
            } else {
                int temp_answer = 4 - (end - start);
                ans = min(ans, temp_answer);
                break;
            }
        }
    }

    cout << ans;

    return 0;
}
