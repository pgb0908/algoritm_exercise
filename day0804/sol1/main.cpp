//
// Created by bong on 23. 8. 4.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long MAX = -1;

// 0 - +
// 1 - -
// 2 - *
char[]

long long solution(string expression) {
    long long answer = 0;

    std::vector<int> nums;
    std::vector<char> op;
    std::string temp_num;
    // vec에 수자와 연산 나누기
    for(int i=0; i < expression.size(); i++){
        if(expression[i] <= '9' && expression[i] >= '0'){
            temp_num += expression[i];
            continue;
        }

        nums.push_back(stoi(temp_num));
        temp_num.clear();
        op.push_back( expression[i]);
    }
    nums.push_back(stoi(temp_num));

    // 모든 조합으로 계산
    recursive(nums, op);


    return answer;
}

int main() {

    string s = "100-200*300-500+20";
    string s2 = "50*6-3*2";

    auto rtn = solution(s);
    //auto rtn = solution(param[1][0], param[1][1], param[1][2]);
    //auto rtn = solution(param[2][0], param[2][1], param[2][2]);


    cout << rtn << endl;

    return 0;
}