//
// Created by bong on 23. 7. 14.
//
#include <iostream>
#include <vector>

std::vector<int> solution(int brown, int yellow){

    // X * Y 조합 구하기 (X < Y)
    std::vector<std::vector<int>> comb;
    int sum = brown + yellow;

    for(int i=2; i<= sum; i++){
        if(sum % i != 0) continue;
        int j = sum/i;
        if(i > j) break;

        comb.push_back({i, j});
    }

    for(auto outer : comb){
        for(auto inner : outer){
            std::cout << inner << " ";
        }
        std::cout << std::endl;
    }

    // X-Y = 1 혹은 2 조합 구하기
    int y, x;
    for(auto list : comb){
        int val = list[1] - list[0];
        if(val == 1 || val == 2){
            y = list[1];
            x = list[0];
            break;
        }
    }

    return {y, x};
}


int main() {


    int b,y;

    b = 10;
    y = 2;

    auto rtn = solution(b, y);
    std::cout << rtn[0] << ", " <<  rtn[1] << std::endl;
    return 0;
}