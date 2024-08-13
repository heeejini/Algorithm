#include <bits/stdc++.h>
#define ll long long
#define pii pair<string, int>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int tc;

    cin >> tc;

    vector<pii> commands;
    string result = ""; // 결과를 입력 받을 string
    for(int i=0; i<tc; i++){
        string cmd; // 명령어 입력 받기 

        cin >> cmd;

        if(cmd == "type"){
            string s;
            int num;
            cin >> s>>num;
            result += s;
            commands.push_back({result, num});
        }
        else if(cmd =="undo"){
            int t1,t2;
            cin >> t1 >> t2; // 3 5 -> 5초일때 지난 3초간 일들을 무효화 시킨다, 2초부터 싹 무효화 
            
            int time = t2-t1;
            
            bool flag = false;

            for(int i=commands.size()-1; i>=0; i--){
                if(commands[i].second < time){
                    result = commands[i].first; // 1초에 있던 'a'값을 5에 저장해주기
                    flag = true;
                    break;
                }
            }

            if (!flag)
                result = "";
            commands.push_back({result, t2});
        }



    }
    cout << result << "\n";
    
    return 0;
}