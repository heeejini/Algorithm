#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

// 회문 검사 함수
bool is_palindrome(const string &str, int left, int right) {
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
// 유사 회문 검사 함수
bool is_semipalindrome(string str) {
    int left = 0;
    int right = str.size() - 1;
    int cnt = 0;

    while (left < right) {
        if (str[left] == str[right]) {
            left++;
            right--;
        } else {
            return is_palindrome(str, left+1, right) || is_palindrome(str, left, right-1); // 한 개의 문자열을 넘기고 회문인지 체크
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++) {
        string str;
        cin >> str;

        if (is_palindrome(str, 0, str.size() - 1)) {
            cout << 0 << endl;
        } else if (is_semipalindrome(str)) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }

    return 0;
}
