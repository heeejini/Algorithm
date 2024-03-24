#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int num = 665;
    int cnt = 0;

    while (cnt != n) {
        num++;
       // cout << num << "\n";
        string result = to_string(num);
        if (result.find("666") != std::string::npos) { // 666이 있는 지 찾기 
            cnt++;
        }
    }

    std::cout << num << '\n';
    return 0;
}