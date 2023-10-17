#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;


struct Line {
    int start;
    int end;
    map<string, int> map_;
};

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    Line line;
    line.start = 0;
    line.end = gems.size()-1;
    answer.push_back(line.start);
    answer.push_back(line.end);
    int minLine = line.end - line.start;

    for(const auto& item : gems){
        line.map_[item]++;
    }

    for(; line.end > 0; line.end--){
        auto it = gems[line.end];

        if(line.map_[it] -1 > 0){
            line.map_[it]--;
        }else{
            break;
        }
    }

    while(line.end < gems.size()){
        for(; line.start < line.end; line.start++){
            auto it = gems[line.start];

            if(line.map_[it] -1 > 0){
                line.map_[it]--;
            }else{
                break;
            }
        }

        auto temp_line = line.end - line.start;
        if(temp_line < minLine){
            minLine = temp_line;
            answer[0] = line.start;
            answer[1] = line.end;
        }

        if(line.end + 1 == gems.size()) break;
        line.end++;
        line.map_[gems[line.end]]++;
    }

    return {answer[0]+1, answer[1]+1};
}


int main() {

/**
 *
    gems	result
    ["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]	[3, 7]
    ["AA", "AB", "AC", "AA", "AC"]	[1, 3]
    ["XYZ", "XYZ", "XYZ"]	[1, 1]
    ["ZZZ", "YYY", "NNNN", "YYY", "BBB"]	[1, 5]
   ["AA", "AB", "AC", "AA", "AC", "AB"]	[3, 6]
 *
 */

    vector<string> s1;

    //s1 = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
    //s1  = {"ZZZ", "YYY", "NNNN", "YYY", "BBB"};
    s1 = {"A", "B", "B",  "B",  "C", "D", "D", "D", "D", "D", "D", "D", "B" ,"C" ,"A"}; //[12, 15]

    auto rtn = solution(s1);

    cout << "{";
    for(auto item : rtn){
        cout << item << " ";
    }

    cout << "}";

    return 0;
}