#include <bits/stdc++.h>
using namespace std;

string solve(int n, int m) {
    unordered_map<int, int> results;
    string result;

    // 정수 부분 계산
    int integer_part = n / m;
    result += to_string(integer_part) + ".";
    
    // 소수점 이하 부분 계산
    int remainder = n % m;

    vector<int> decimal_part; // 소수의 각 자리 수 저장 
    while (remainder != 0 && results.find(remainder) == results.end()) {
        // 순환 소수 판별하기 , 이전에 나왔는 지 판별하기 위해서 
        results[remainder] = decimal_part.size(); // 현재 나머지가 등장한 소수부분의 위치를 저장해준다
        remainder *= 10; // 다음소수의 자릿수 계싼하기 
        decimal_part.push_back(remainder / m);
        remainder %= m; // 나머지값 갱신
    }

    // 순환 소수 형식으로 변환
    if (remainder == 0) {
        for (int digit : decimal_part) {
            result += to_string(digit);
        }
        result += "(0)";
    } else {
        for (int i = 0; i < results[remainder]; ++i) { // 순환부분이 아닌거 출력 
            result += to_string(decimal_part[i]);
        }
        result += "(";
        for (int i = results[remainder]; i < decimal_part.size(); ++i) {
            result += to_string(decimal_part[i]);
        }
        result += ")";
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        cout << solve(n, m) << endl;
    }

    return 0;
}
