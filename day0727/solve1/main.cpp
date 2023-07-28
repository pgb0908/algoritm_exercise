//
// Created by bong on 23. 7. 27.
//

#include <vector>
#include <iostream>
#include <algorithm>

//https://school.programmers.co.kr/learn/courses/30/lessons/12899#qna

char array[] = {'1', '2', '4'};



std::string solution(int number) {
    std::string answer;

    while(number != 0){
        auto val = number % 3;
        if(val ==0){
            // 012는 412로 표현할 시
            // 20(3) --> 13(3) --> 14(124)와 동일하게 표현할 수 있음
            number = (number-1) /3;
            answer = std::to_string(4) + answer;
        }else{
            number = number /3;
            answer = std::to_string(val) + answer;
        }
    }


    return answer;
}

int main() {

    int num =15;

    auto rtn = solution(num);
    std::cout << rtn << std::endl;

    return 0;
}