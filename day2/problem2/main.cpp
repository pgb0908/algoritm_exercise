//
// Created by bong on 23. 7. 14.
//
#include <iostream>
#include <vector>
#include <cmath>


int count = 0;
char c[5] = {'A', 'E', 'I', 'O', 'U'};

std::vector<char> final = {'I'};

void testRecursive(std::vector<int> vector, int cnt){

    if(vector.size() == cnt){

        for(auto item : vector){
            std::cout << item << " ";
        }
        std::cout << std::endl;

        return;
    }

    for(int i=0; i < 2; i++){
        vector.push_back(i);
        testRecursive(vector, cnt);
        vector.pop_back();
    }

}

void testRecursive2(std::vector<char> vector){

    for(auto item : vector){
        std::cout << item << " ";
    }
    std::cout << std::endl;

    if(vector == final){
        // do
        return;

    }

    for(int i=0; i< 5; i++) {
        if(vector.size() < 5){
            vector.push_back(c[i]);
            testRecursive2(vector);
        }
    }
}

void DFS(std::string word, std::string str, int *rtn) {

    std::cout << str <<  std::endl;

    if(word == str){
        *rtn = count;
        return;

    }

    for(int i=0; i< 5; i++) {
        if(str.length() < 5){
            count++;
            auto new_word = str+c[i];
            DFS(word, new_word, rtn);
        }
    }
}

int solution(std::string word){
    int rtn= 0;
    DFS(word, "", &rtn);

    return rtn;

}

int main() {

    std::vector<char> test;
    //testRecursive(test, 4);

    //testRecursive2(test);




    std::string word1 = "AAAAE";
    std::string word2 = "AAAE";
    std::string word3 = "I";
    std::string word4 = "EIO";

    auto rtn = solution(word3);
    //std::cout <<rtn << std::endl;

    //auto dd = (std::pow(5,4))*2 + (std::pow(5,3)) + (std::pow(5,2)) + (std::pow(5,1));
    //std::cout << dd << std::endl;
    return 0;
}