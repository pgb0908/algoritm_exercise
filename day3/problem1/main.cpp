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


std::vector<long long> solution_timeout(std::vector<long long> numbers) {
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


std::vector<long long> solution(std::vector<long long> numbers) {
    std::vector<long long> answer;
    for(const auto number : numbers){

        if( (number %2) ==0){ // 짝수
            // 짝수이면 맨끝자리 0, 1비트로 현재보다 더 큰 자리 가능
            answer.push_back(number+1);

        }else{ // 홀수
            // 홀수이면 끝자리 1, 최소 2비트의 수정이 일어남
            // 최초 0의 자리를 찾는게 포인트!
            long long bit = 1;
            while(true){
                if((number & bit) == 0 ){
                    break;
                }
                bit = bit <<= 1;
            }
            bit /=2;
            answer.push_back(number + bit);
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

    long long bit = 1;
    bit >>=1;
    std::cout << bit  << std::endl;

    return 0;
}