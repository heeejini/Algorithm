#include <iostream>
using namespace std;

int findGenerator(int N) {
    // N의 생성자를 찾기 위해 1부터 N까지 반복
    for (int i = 1; i < N; i++) {
        int sum = i; // sum은 현재 숫자 i와 i의 각 자리수의 합

        // i의 각 자리수의 합을 구함
        int temp = i;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }

        // 만약 현재 i가 N의 생성자라면 반환
        if (sum == N) {
            return i;
        }
    }
    // 생성자가 없는 경우 0을 반환
    return 0;
}

int main() {
    int N;
    cin >> N;

    // N의 가장 작은 생성자를 출력
    cout << findGenerator(N) << endl;

    return 0;
}
