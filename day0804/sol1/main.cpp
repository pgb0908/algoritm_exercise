//
// Created by bong on 23. 8. 4.
//
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long MAX = -1;

// 0 - +
// 1 - -
// 2 - *

long long calculate(long long int &a, long long int &b, char &op) {
    if(op == '+'){
        return a + b;
    }
    else if(op == '-'){
        return a - b;
    }else if(op == '*'){
        return a * b;
    }
}
long long solution(string expression) {
    long long answer = 0;

    std::vector<long long> nums;
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
    vector<int> comb = {0, 1, 2};
    string operator_values = "+-*";

    do{
        vector<long long> temp_nums = nums;
        std::vector<char> temp_op = op;

        for(int i=0; i < comb.size(); i++){
            for(int j =0; j < temp_op.size();){
                if(temp_op[j] == operator_values[comb[i]]){
                    auto res = calculate(temp_nums[j],temp_nums[j+1], temp_op[j]);

                    temp_nums.erase(temp_nums.begin()+j);
                    temp_nums.erase(temp_nums.begin()+j);
                    temp_nums.insert(temp_nums.begin()+j, res);

                    temp_op.erase(temp_op.begin()+j);
                }else{
                    j++;
                }
            }
        }

        answer = max(answer, abs(temp_nums[0]));
    }while(next_permutation(comb.begin(), comb.end()));


    return answer;
}



int main() {

    string s = "100-200*300-500+20";
    string s2 = "50*6-3*2";

    auto rtn = solution(s);
    //auto rtn = solution(param[1][0], param[1][1], param[1][2]);
    //auto rtn = solution(param[2][0], param[2][1], param[2][2]);


    cout << rtn << endl;



/*    vector<int> comb = {0, 1, 2};
    do{

        for(auto item : comb){
            cout << item << " ";
        }
        cout << endl;
    }while(next_permutation(comb.begin(), comb.end()));*/

    return 0;
}