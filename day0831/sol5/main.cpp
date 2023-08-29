#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int,int> map;

    for(auto item : tangerine){
        map[item]++;
    }

    vector<int> spec;
    for(auto item : map){
        spec.push_back(item.second);
    }

    sort(spec.begin(), spec.end(), greater<int>());

    int total =0;
    for(int i=0; i< spec.size(); i++){
        total += spec[i];
        answer++;
        if(total >= k) break;
    }

    return answer;
}



int main() {

    /*
6	[1, 3, 2, 5, 4, 5, 2, 3]	3
4	[1, 3, 2, 5, 4, 5, 2, 3]	2
2	[1, 1, 1, 1, 2, 2, 2, 3]	1
     */

    vector<int> arr = {1, 3, 2, 5, 4, 5, 2, 3};

    auto rtn = solution(6, arr);

    cout << endl;
    cout << rtn << " ";

    return 0;
}