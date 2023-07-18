//
// Created by bong on 23. 7. 18.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

std::vector<int> makeNumToBit(long long num){
    std::vector<int> bits;
    while(num != 0){
        int bit = num % 2;
        bits.push_back(bit);
        num = num/2;
    }

    int size = 15 - bits.size();
    while(size != 0){
        bits.push_back(0);
        size--;
    }

    return bits;
}

int cmpVec(const std::vector<int>& one, const std::vector<int>& two){
    int cnt = 0;

    for(int idx=0; idx < 15; idx++){
        if(one[idx] != two[idx])
            cnt++;
    }

    return cnt;

}


std::vector<long long> solution(std::vector<long long> numbers) {
    auto max = static_cast<long long>(std::pow(10, 15));
    std::vector<long long> answer;


    for(const auto number : numbers){
        // 2비트로 만들기 --> 벡터로
        auto temp = makeNumToBit(number);

        for(long long num = number; num <= max;){
            num++;
            auto cmp_vec = makeNumToBit(num);
            int cnt = cmpVec(temp, cmp_vec);

            // 1 혹은 2개 이하면 값에 넣기
            if(cnt <= 2){
                answer.push_back(num);
                break;
            }
        }
    }



    return answer;
}

int main() {

    std::vector<long long> num{2, 7};

    auto rtn = solution(num);

    for(auto outer : rtn){
        std::cout << outer;
        std::cout << " ";
    }
    std::cout << std::endl;

    return 0;
}