#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
/*
key point : lower_bound, upper_bound 함수의 활요 ㅇ
lower_bound : 주어진 값 이상인 값이 처음으로 나오는 위치(ex : n>=7)
upper_bound : 주어진 값보다 큰 값이 처음으로 나오는 위치 (ex : n > 7)
*/
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n;

    vector<int> card(n);

    for(int i = 0; i < n; i++){
        cin >> card[i];
    }

    cin >> m;

    vector<int> myCard(m);

    for(int i = 0; i < m; i++){
        cin >> myCard[i];
    }

    sort(card.begin(), card.end());
 //   sort(myCard.begin(), myCard.end());

    // for(int i=0; i<n; i++) cout << card[i] << " ";
    // cout << "\n";
    // for(int i=0; i<m; i++) cout << myCard[i] <<   " ";
    // cout << "\n";

    
    for(int i = 0; i < m; i++){
        auto it = upper_bound(card.begin(), card.end(), myCard[i]);
        auto lo = lower_bound(card.begin(), card.end(),myCard[i] );

        cout << it - lo <<  " ";
    }


    return 0;
}
