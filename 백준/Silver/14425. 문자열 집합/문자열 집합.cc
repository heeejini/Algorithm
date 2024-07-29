#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;
// 문자열 집합 / 실버 4

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    unordered_set<string> set;


    cin >> n >> m;

    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;
        set.insert(temp);
    }

    int cnt =0;
    for(int i=0; i<m; i++){
        string temp;
        cin >> temp;

        if(set.find(temp) != set.end()){
            cnt ++;
        }
    }


    cout << cnt ;
    
    return 0;
}