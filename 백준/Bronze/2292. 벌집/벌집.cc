#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    

    int n;
    cin >> n;

    int _bee =1 ;// 벌집의 갯수, 1개부터 시작 

    int cnt = 1 ;
    while(n > _bee){
        _bee+=6*cnt; // 벌집이 6의 배수로 증가 
        cnt ++; 
    }
    
    cout << cnt <<endl;
    return 0;
}