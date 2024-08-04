#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

vector<int> result;

void parsing_number(const string& page, int num) {
    stringstream ss(page);
    string token;
    vector<int> numbers;

    while (getline(ss, token, '-')) {
        numbers.push_back(stoi(token));
    }

    if (numbers.size() == 2) {
        int _low = numbers[0];
        int _high = numbers[1];

        //cout << "맨처음 : " << _low << " " << _high <<" "<< num <<  "\n";
        if (_low > num && _high > num){
          //  cout << "기각";
            return;
        }// 범위를 벗어나면 처리하지 않음
        if (_low < 1) _low = 1; // 1보다 작은 값은 1로 처리
        if (_high > num) _high = num; // num보다 큰 값은 num으로 처리


     //   cout << _low <<" "<< _high << endl;
        for (int i = _low - 1; i < _high; i++) {
      //      cout << i << " ";
            result[i] = 1;
        }
    //    cout << "\n";
    } else if (numbers.size() == 1) {
        int index = numbers[0];
        if (index > 0 && index <= num) {
        result[index - 1] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    while (true) {
        int num;
        cin >> num;
        if (num == 0) break;
        cin.ignore();
        result.resize(num, 0); // 벡터를 num 크기로 초기화하고 0으로 채움

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<string> pages;
        string token;

        while (getline(ss, token, ',')) {
            pages.push_back(token);
        }

        for (const auto& page : pages) {
            parsing_number(page, num);
        }

        // 결과 출력
        int cnt =0;
        for (int i = 0; i < num; i++) {
         //   if (result[i] == 1) cout << (i + 1) << " ";
            if(result[i]==1) cnt ++;
        }
        cout << cnt<<"\n"; 

        result.clear();
    }
    
    return 0;
}
