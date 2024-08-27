#include <bits/stdc++.h>
using namespace std;

double grade_to_score(string _grade) {
    double score;
    if(_grade == "A+") score = 4.5;
    else if(_grade == "A0") score = 4.0;
    else if(_grade == "B+") score = 3.5;
    else if(_grade == "B0") score = 3.0;
    else if(_grade == "C+") score = 2.5;
    else if(_grade == "C0") score = 2.0;
    else if(_grade == "D+") score = 1.5;
    else if(_grade == "D0") score = 1.0;
    else if(_grade == "F") score = 0.0;
    else score = 0.0; // 여기서는 P인 경우도 포함되어 0으로 처리

    return score;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    double sum = 0;  // 학점의 총합
    double tot = 0;  // 학점*과목평점의 합

    for(int i = 0; i < 20; i++) {
        string str, grade;
        double score;
        
        cin >> str >> score >> grade;
        
        if(grade == "P") continue; // P 등급 과목은 계산에서 제외
        
        double temp = grade_to_score(grade);
        tot += score * temp;
        sum += score;
    }

    cout << fixed << setprecision(6) << tot / sum << "\n";
    return 0;
}
