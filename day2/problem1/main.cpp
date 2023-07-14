//
// Created by bong on 23. 7. 14.
//
#include <iostream>
#include <vector>

std::vector<int> solution(int brown, int yellow){

    // 노란색의 X*Y를 구하라
    std::vector<std::vector<int>> comb;
    int sum = yellow + brown;

    for(int i=1; i<= yellow; i++){
        if(yellow % i != 0) continue;
        int j = yellow/i;
        if(i > j) break;

        comb.push_back({i, j});
    }

    // (X+2) * (Y+2) = 동형의 수인지 구하라
    for(auto outer : comb){
        for(auto inner : outer){
            std::cout << inner << " ";
        }
        std::cout << std::endl;
    }

    // X-Y = 1 혹은 2 조합 구하기
    int c_y;
    int c_x;
    for(auto list : comb){
        int val = (list[1]+2) * (list[0]+2);
        if(val == sum){
            c_x = list[1]+2;
            c_y = list[0]+2;
            break;
        }
    }



    return {c_x, c_y};
}


int main() {


    int b,y;

    b = 8;
    y = 1;

    auto rtn = solution(b, y);
    std::cout << rtn[0] << ", " <<  rtn[1] << std::endl;
    return 0;
}