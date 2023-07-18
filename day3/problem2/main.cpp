//
// Created by bong on 23. 7. 18.
//

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

int solution(int n, int k, std::vector<int> enemy) {
    int answer = 0;

    std::vector<int> copy = enemy;

    std::sort(copy.begin(), copy.end(), [](int a, int b){ return  a> b;});

    std::vector<int> k_vec;
    for(int i=0; i< k; i++){
        k_vec.push_back(copy[i]);
    }

    std::vector<int> skips;
    for(auto item : k_vec){
        auto idx = std::find(enemy.begin(), enemy.end(), item)-enemy.begin();
        enemy.at(idx) = -1;
    }


    for(int i : enemy){

        if(i == -1){
            answer++;
            continue;
        }

        n -= i;
        if(n <= 0){
            break;
        }

        answer++;
    }

    return answer;
}

int main() {

    int n,k;
    std::vector<int> enemy;

    n = 7;
    k=3;
    enemy = {4, 2,4, 5, 3, 3, 1};

    n = 2;
    k=4;
    enemy = {3,3,3,3};

    auto rtn = solution(n, k, enemy);

    std::cout << rtn << std::endl;


    return 0;
}