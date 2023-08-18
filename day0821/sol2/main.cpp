#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

struct Plan {
public:
    string name;
    int start{0};
    int work{0};
};

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    if(plans.empty()) return answer;

    // 입력 시간 순으로 오름차순
    sort(plans.begin(), plans.end(),
         [](vector<string> s1, vector<string> s2){return s1[1] < s2[1];});

    stack<Plan> stack;
    queue<Plan> process;
    for(auto& item : plans ){
        auto temp = item[1];
        auto hour = temp.substr(0,2);
        auto min = temp.substr(3, 5);

        int total_min = std::stoi(hour)*60 + std::stoi(min);

        Plan plan;
        plan.name = item[0];
        plan.start = total_min;
        plan.work = stoi(item[2]);

        process.push(plan);
    }

    while(!process.empty()){
        auto cur = process.front();
        process.pop();

        if(!process.empty()){
            auto next = process.front();
            auto rest = next.start - cur.start ;
            if(rest >= cur.work){
                answer.push_back(cur.name);
                rest -= cur.work;

                /* 다음 작업과 시간이 많이 떠버리면
                 * 이전에 남은 작업들을 처리해줘야함 */
                while(rest > 0 && !stack.empty()){
                    auto& old = stack.top();
                    if(old.work <= rest){
                        answer.push_back(old.name);
                        rest -= old.work;
                        stack.pop();
                    }else{
                        old.work -= rest;
                        rest = 0;
                    }
                }

            }else{
                cur.work = cur.work-rest;
                stack.push(cur);
            }
        }else{
            answer.push_back(cur.name);
        }
    }

    while(!stack.empty()){
        auto cur = stack.top();
        answer.push_back(cur.name);
        stack.pop();
    }


    return answer;
}

int main() {

    // ["korean", "english", "math"]
    vector<vector<string>> input1 = {{"korean", "11:00", "10"}, {"english", "11:05", "10"}, {"math", "11:10", "20"}, {"excer", "11:38", "20"},};

    // 	["science", "history", "computer", "music"]
    vector<vector<string>> input2 = {{"science", "12:40", "50"}, {"music", "12:20", "40"}, {"history", "14:00", "30"}, {"computer", "12:30", "100"}};

    // 	["bbb", "ccc", "aaa"]
    vector<vector<string>> input3 = {{"aaa", "12:00", "20"}, {"bbb", "12:10", "30"}, {"ccc", "12:40", "10"}};
    
    auto rtn = solution(input1);


    for(auto item : rtn){
        cout << item << endl;
    }



    return 0;
}