#include <iostream>
using namespace std;

int find(long long x) {
    if (x == 0) {
        return 0;
    } else if (x == 1) {
        return 1;
    } else if (x % 2 == 0) {
        // x가 짝수인 경우
        return find(x / 2);
    } else {
        // x가 홀수인 경우
        return 1 - find(x / 2);
    }
}

int main() {
    long long x;
    cin >> x; 
    cout << find(x - 1); 
    return 0;
}
