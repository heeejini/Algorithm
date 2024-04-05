#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;
string result;

void solve(int num, int start, int end){
    //base condition
    if(end - start <3) return ;
    if (num==0) result.append("-");

    // 중간 부분 삭제 
    int len = (end - start)/3;
    for(int i= start+len; i<start +(len*2); i++){
        result[i]=' ';
    }

    solve(num,start,start+len); //1번째
    solve(num,start+(len*2),end); //3번째

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // 칸토어 집합 - 시작/ 끝 길이로 
    int num;

    while(cin >> num){
        // 입력이 몇갠지 모름
        result = string(pow(3,num), '-'); // 문자열을 '-'로 초기화
        solve(num, 0, pow(3,num));
        cout << result << "\n";
        result.clear();
    }
    
    return 0;
}