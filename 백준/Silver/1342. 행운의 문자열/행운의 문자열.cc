#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

bool checked(string str){

    for(int i=1; i<str.size(); i++){
        if(str[i-1]==str[i]) return false; // 연속적으로 같으면 행운의 문자열이 아님
    }

    return true;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string str;

    cin >> str;
    sort(str.begin(), str.end());
    int cnt =0;
  //  set<string> l_str; // 중복되는 문자열이 나오기 때문에 set 사용
    
    do{ // 순열 생성을 통해 해당 문자열의 문자들을 통해 나올 수 있는 모든 경우 만들기
        if(checked(str)){ // 행운의 문자열이면 set에 저장 
          //  l_str.insert(str);
          cnt ++;
        }

    }while(next_permutation(str.begin(), str.end()));
    
    cout <<cnt ; 

    return 0;
}