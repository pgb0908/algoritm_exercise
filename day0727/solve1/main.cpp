//
// Created by bong on 23. 7. 27.
//

#include <vector>
#include <iostream>
#include <algorithm>

char array[] = {'1', '2', '4'};



std::string solution(int number) {
    std::string answer;

    while(number != 0){
        auto val = number % 3;
        if(val ==0){
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