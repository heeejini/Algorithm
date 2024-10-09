#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int arr[1001] = {0,};
    int dp[1001] = {0,};
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] < arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // dp 배열에서 최대값 출력
    cout << *max_element(dp, dp + n + 1) + 1;

    return 0;
}
