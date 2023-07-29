#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    vector<pair<int, bool>> vec;
    for(int i=0; i< priorities.size(); i++){
        if(location == i){
            vec.push_back({priorities[i], true});
        }else{
            vec.push_back({priorities[i], false});
        }
    }


    while(!vec.empty()){

        auto pick = vec[0];
        auto max = *std::max_element(vec.begin()+1, vec.end(), [](pair<int, bool> a, pair<int, bool> b ){
            return a.first < b.first;
        });

        if(pick.first >= max.first){
            //실행
            answer++;
            vec.erase(vec.begin());
            if(pick.second) break;

        }else{
            // 다시
            vec.erase(vec.begin());
            vec.push_back(pick);
        }
    }

    return answer;
}

int main() {

    vector<int> priorities1{2, 1, 3, 2};
    int loc1 = 2;
    vector<int> priorities2{    1, 1, 9, 1, 1, 1};
    int loc2 = 0;


    auto rtn = solution(priorities2, loc2);

    std::cout << rtn << std::endl;


    return 0;
}
