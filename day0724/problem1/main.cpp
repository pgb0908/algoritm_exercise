//
// Created by bong on 23. 7. 18.
//
// https://school.programmers.co.kr/learn/courses/30/lessons/12924

#include <vector>
#include <iostream>
#include <algorithm>


int sumFromIdx(int idx, int size){
    int sum = 0;
    while(size != 0){
        sum += idx;
        size--;
        idx++;
    }

    return sum;
}

int solution(int numbers) {
    int answer = 0;

    for(int size=1; size<= numbers; size++){

        // 첫번째 인덱스 + size 만큼
        int bound = numbers - size;
        for(int idx=0; idx <= bound; idx++){

            int sum = sumFromIdx(idx+1, size);
            if(sum > numbers) break;
            if(sum == numbers){
                //std::cout << idx+1 << ", " << size << std::endl;
                answer++;
            }
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
