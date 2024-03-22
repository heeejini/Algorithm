#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    cin.ignore();
    unordered_map<string, int> book_sales;
    string book;
    int max_sales = 0;
    vector<string> bestsellers;

    for (int i = 0; i < N; i++) {
        getline(cin, book);
        // 책의 판매량 증가
        book_sales[book]++;
        // 가장 많이 팔린 책의 판매량 업데이트
        if (book_sales[book] > max_sales) {
            max_sales = book_sales[book];
            bestsellers.clear(); // 최대 판매량이 업데이트 되면 리스트를 비움
            bestsellers.push_back(book);
        } else if (book_sales[book] == max_sales) {
            // 같은 판매량의 책이 있으면 리스트에 추가
            bestsellers.push_back(book);
        }
    }

    // 사전순으로 정렬하여 가장 앞서는 제목 출력
    sort(bestsellers.begin(), bestsellers.end());
    cout << bestsellers.front() << "\n";

    return 0;
}
