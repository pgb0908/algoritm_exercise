//
// Created by bong on 23. 7. 18.
//

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

int solution1(int n, int k, std::vector<int> enemy) {
    int answer = 0;
    std::vector<int> copy = enemy;

    for(int i : enemy){

        n -= i;
        if(n <= 0){
            break;
        }

        answer++;
    }

    return answer;
}

int solution(int n, int k, std::vector<int> enemy) {
    int answer = 0;

    std::priority_queue<int> pq;

    for(int step : enemy){
        pq.push(step);
        n = n - step;

        // priority_queue 사용할지 결정
        if(n < 0){
            if(k > 0){
                auto big_one = pq.top();
                pq.pop();

                n += big_one;
                k--;
            }
        }


        if(n < 0){
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

    //n = 2;
    //k=4;
    //enemy = {3,3,3,3};

    auto rtn = solution(n, k, enemy);

    std::cout << rtn << std::endl;


    return 0;
}