#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string start,end, streaming_end;
    set<string> before ;
    set<string> after;
    
    cin >> start >> end >> streaming_end ;

    string time, id;

    while(cin >> time >> id){
        if(time <=start){
            // 개총 시작 전 
            before.insert(id);
        }
        else if( end <=time && time <=streaming_end){
            after.insert(id);
        }
    }

    int cnt =0;

    for(const string &n : before){
        if(after.find(n) != after.end() ){
            cnt++;
        }
    }

    cout << cnt ;

    return 0;
}