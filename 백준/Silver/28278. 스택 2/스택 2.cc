#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;
/*
1 X: 정수 X를 스택에 넣는다. (1 ≤ X ≤ 100,000)
2: 스택에 정수가 있다면 맨 위의 정수를 빼고 출력한다. 
없다면 -1을 대신 출력한다.
3: 스택에 들어있는 정수의 개수를 출력한다.
4: 스택이 비어있으면 1, 아니면 0을 출력한다.
5: 스택에 정수가 있다면 맨 위의 정수를 출력한다. 
없다면 -1을 대신 출력한다.
*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    stack<int> s;
    int tc ;

    cin >> tc;

    int cmd;

    for(int i=0; i<tc; i++){
        cin >> cmd;

        if(cmd == 1) {
            int num;
            cin >> num;
            s.push(num);

        }else if(cmd == 2){
            if(s.empty()) cout << -1 <<"\n";
            else{
                 cout << s.top() <<"\n";
                 s.pop();
            } 
        }else if(cmd ==3 ){
            cout << s.size() << "\n";
        }else if(cmd==4){
            if(s.empty()) cout << 1 <<"\n";
            else cout << 0 << "\n";
        }else if(cmd == 5){
            if(s.empty()) cout << -1 <<"\n";
            else cout << s.top() <<"\n";
        }   


    }
    return 0;
}