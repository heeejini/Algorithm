/*
9 8
CCTGGATTG
2 0 1 1
답 : 0
*/

#include <iostream>
#include <cstring>
using namespace std;
int num[4] = { 0, };
int myArr[4] = { 0, };
int checkSecret = 0;

void add(char s) {
	switch (s) {
	case 'A':
		myArr[0]++;
		// {‘A’, ‘C’, ‘G’, ‘T’} 의
		if (myArr[0] == num[0]) {
			checkSecret++;
		}
		break;

	case 'C':
		myArr[1]++;
		if (myArr[1] == num[1]) {
			checkSecret++;
		}
		break;
	case 'G':
		myArr[2]++;
		if (myArr[2] == num[2]) {
			checkSecret++;
		}
		break;
	case 'T':
		myArr[3]++;
		if (myArr[3] == num[3]) {
			checkSecret++;
		}
		break;
	}

}

void deleted(char s) {
	switch (s) {
	case 'A':
		// {‘A’, ‘C’, ‘G’, ‘T’} 의
		if (myArr[0] == num[0]) {
			checkSecret--;
		}
		myArr[0]--;
		break;

	case 'C':
		if (myArr[1] == num[1]) {
			checkSecret--;
		}
		myArr[1]--;
		break;
	case 'G':
		if (myArr[2] == num[2]) {
			checkSecret--;
		}
		myArr[2]--;
		break;
	case 'T':
		if (myArr[3] == num[3]) {
			checkSecret--;
		}
		myArr[3]--;
		break;
	}

}
int main() {
	int len, window;
	// window 슬라이딩 윈도우의 크기
	cin >> len >> window;
	string s;
	cin >> s;
	int cnt = 0;

	//int checkSecret = 0;//몇개의 문자에 대해 조건을 충족했는 지 저장해주는 변수 
	for (int i = 0; i < 4; i++) {
		cin >> num[i];
		if (num[i] == 0) {
			checkSecret++; // 0개면 해당 문자에 대해 만족했으니까 count를 올려준다. 
		}

	}

	// 슬라이딩 윈도우 - 초기 배열에 대해 확인
	for (int i = 0; i < window; i++) {
		add(s[i]);
	}

	if (checkSecret ==4 ) {// 초기 배열 내에서 결과가 만족 할 시에 
		cnt++;
	}

	for (int i = window; i < len; i++) {
		int j = i - window;
		add(s[i]);
		deleted(s[j]);

		if (checkSecret == 4) {// 초기 배열 내에서 결과가 만족 할 시에 
			cnt++;
		}
	}

	cout << cnt << "\n";


	return 0;
}