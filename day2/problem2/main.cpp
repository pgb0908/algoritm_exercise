//
// Created by bong on 23. 7. 14.
//
#include <iostream>
#include <vector>

int solution(std::string word){
    int rtn= 0;
    char list[5] = {'a', 'e', 'e', 'o', 'u'};
    int next_val = 1;
    int word_size = word.size();

    // 현재 자리수 = 자리수 + 4 * abs(word_size - 현재위치) +  next_val  <-- A기준


    if(word_size > 4){
        // 맨 마지막 자리
        auto five = word[4];
        int index;
        for(int i=0; i< word_size; i++){
            if(five == list[i]){
                index = i;
            }
        }
        rtn = 5 + index;
    }

    if(word_size > 3){
        // 네번째
        auto four = word[3];
        int index = 0;
        for(int i=0; i< word_size; i++){
            if(four == list[i]){
                index = i;
            }
        }
        rtn = 4 + index * 5;
    }







}


int main() {


    std::string word1 = "AAAAE";

    auto rtn = solution(word1);
    std::cout <<rtn << std::endl;
    return 0;
}