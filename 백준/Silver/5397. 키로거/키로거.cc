#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;


void keylog(string pw) {
    stack<char> right;
    stack<char> left;

    for (const char& c : pw) {
        if (isalpha(c) || isdigit(c)) {
            //문자열일때
            left.push(c);
        }
        else if (c == '>' && !right.empty()) {
            // 오른쪽의 마지막을 왼쪽 마지막에 붙임
            char top = right.top();
            right.pop();
            left.push(top);
        }
        else if (c == '<' && !left.empty()) {
            // 왼쪽 마지막을 오른쪽 마지막에 붙임
            char top = left.top();
            left.pop();
            right.push(top);

        }
        else if (c == '-' && !left.empty()) {
            left.pop();
        }
    }
    int size = left.size();
    int size2 = right.size();
    string result, result2;
    for (int i = size; i > 0; i--) {
        result += left.top();
        left.pop();
    }
    for (int i = size2; i > 0; i--)
    {
        result2 += right.top(); right.pop();
    }
 //   cout << result2 << "\n";
    reverse(result.begin(), result.end());
//    reverse(result2.begin(), result2.end());

    cout << result + "" + result2 << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tot;
    cin >> tot;
    cin.ignore();

    string pw, result;
    for (int i = 0; i < tot; i++) {
        getline(cin, pw);
        keylog(pw);
    }
}