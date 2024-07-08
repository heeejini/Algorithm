#include <iostream>
#include <vector>
/*
10 3
1 2 2 2 1 2 1 2 2 1
*/
using namespace std;
int len, n;
vector<int> lion;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> len >> n;

	int temp = 0;
	int idx = 0;
	for (int i = 0; i < len; i++) {
		cin >> temp;
		if (temp == 1) {
			lion.push_back(i);
		}
	}

	if (lion.size() < n) {
		cout << "-1" << "\n";
		return 0; // -1 출력 후 종료 
	}
		// 슬라이딩 윈도우 알고리즘 사용 
	int ans = 1000001;
	int start = 0; // 시작 인덱스 
	int end = start + n - 1; // 끝 인덱스


	for (int i = 0; i <= lion.size() - n; i++)
	{
		// 인덱스 배열의 시작부터, K를 조사한다.
		// 가장 큰 인덱스와, 가장 작은 인덱스 차를 계산하여 ans를 갱신한다.
		ans = min(ans, lion[i + n - 1] - lion[i] + 1);
	}
	cout << ans;
	
	return 0;
}