//
// Created by bong on 23. 7. 27.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

std::unordered_map<std::string, int> hash[11];
int maxCount[11];


void comb(std::string str, int cnt, std::string result){
    if(cnt == str.size()){
        int num = result.size();
        hash[num][result]++;
        maxCount[num] = std::max(maxCount[num], hash[num][result]);
        return;
    }


    comb(str, cnt+1, result+str[cnt]);
    comb(str, cnt+1, result);
}

std::vector<std::string> solution(std::vector<std::string> orders, std::vector<int> course) {
    std::vector<std::string> answer;

    for(auto order : orders){
        std::sort(order.begin(), order.end());
        comb(order, 0, "");
    }

    for(auto num : course){
        for(auto temp : hash[num]){
            if(temp.second == maxCount[num] && temp.second >= 2){
                answer.push_back(temp.first);
            }
        }
    }

    std::sort(answer.begin(), answer.end());
    return answer;
}

int main() {
    std::cout << "======================================================" << std::endl;
    std::vector<std::string> rtn;

    std::vector<std::string> orders1 = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
    std::vector<int> course1 = {2, 3, 4};

    rtn = solution(orders1, course1);
    for(auto item : rtn){
        std::cout << item << " ";
    }
    std::cout << std::endl;

    std::cout << "======================================================" << std::endl;

/*    std::vector<std::string> orders2 = {"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"};
    std::vector<int> course2 = {2,3,5};

    rtn = solution(orders2, course2);
    for(auto item : rtn){
        std::cout << item << " ";
    }
    std::cout << std::endl;

    std::cout << "======================================================" << std::endl;

    std::vector<std::string> orders3 = {"XYZ", "XWY", "WXA"};
    std::vector<int> course3 = {2,3,4};

    rtn = solution(orders3, course3);
    for(auto item : rtn){
        std::cout << item << " ";
    }
    std::cout << std::endl;*/




    return 0;
}