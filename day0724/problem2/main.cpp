//
// Created by bong on 23. 7. 18.
//

#include <vector>
#include <iostream>
#include <algorithm>


void getRecursive(std::vector<int> map,int cnt, std::vector<std::vector<int>>& maps){


    if(map.size() == cnt){
        maps.push_back(map);

        return;
    }


    for(int i=0; i < cnt; i++){
        auto found = std::find(map.begin(), map.end(), i);
        if(found == map.end()){
            map.push_back(i);
            getRecursive(map, cnt, maps);
            map.pop_back();
        }

    }
}

int solution(int k, std::vector<std::vector<int>> dungeons) {
    int answer = -1;

    std::vector<std::vector<int>> maps;
    std::vector<int> map;
    int cnt = dungeons.size();
    getRecursive(map, cnt, maps);

    for(const auto& one_map : maps){

        auto energy = k;
        auto solved = 0;
        for(auto senario : one_map){
            auto temp = dungeons[senario];
            if(energy < temp[0]) break; //입장불가

            energy -= temp[1];
            if(energy < 0) break;

            solved++;
        }

        if(answer < solved){
            answer = solved;
        }
    }


    return answer;
}

int main() {

    int num = 80;
    std::vector<std::vector<int>> dungeons = {{80, 20}, {50, 40}, {30, 10}};

    auto rtn = solution(num, dungeons);
    std::cout << rtn << std::endl;

    return 0;
}