#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	vector<long long> a(3);
	long long sum = 0;

	for (long long& s : a) {
		cin >> s;
		sum += s;
	}

	cout << sum << "\n";
	return 0;
}