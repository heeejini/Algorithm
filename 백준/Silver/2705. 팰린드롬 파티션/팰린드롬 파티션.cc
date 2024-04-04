#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;
// 펠린드롬 파티션 

int mem[1001] = {0,};

int solve(int n){
    // base condition
    
    if (mem[n] != 0) return mem[n]; // 저장되어있으면 바로 반환

    if(n<=2) {
        mem[n]=n; //memorization
        return n;
    }

    int cnt = 2; // 자기자신과 1로된 조합들 포함!

    // recursize 
    for(int i=2; i<=n/2; i++){
        cnt +=solve(i);
    }
    return mem[n]=cnt; //저장
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    
    int t, cnt; //테스트 갯수 
    cin >> t;

    for(int i=0; i<t; i++){
        int num;
        cin >> num;
        cnt = solve(num); // 펠린드롬 파티션을 해결할 함수 호출
        cout << cnt <<"\n";
    }

    return 0;
}