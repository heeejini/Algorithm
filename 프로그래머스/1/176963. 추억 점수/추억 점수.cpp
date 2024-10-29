#include <string>
#include <vector>
#include <unordered_map>

#include <iostream>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    unordered_map<string, int> friends ;
    
    for(int i=0; i<name.size(); i++){
        friends[name[i]] = yearning[i];
    }
    
    

    for(int i =0; i<photo.size(); i++ ){
        int sum =0 ;
        
        for(int j=0; j<photo[i].size(); j++){
            if(friends[photo[i][j]]!=0){
                sum+=friends[photo[i][j]];
             }
        }
        answer.push_back(sum);
    }
    
    return answer;
}