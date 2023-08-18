#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> s;
    int size = prices.size();
    for(int i=0;i<size;i++){
        while(!s.empty()&&prices[s.top()]>prices[i]){
            answer[s.top()] = i-s.top();
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        answer[s.top()] = size-s.top()-1;
        s.pop();
    }
    return answer;
}

vector<int> solution2(vector<int> prices) {
    vector<int> answer;

    for(int i=0; i< prices.size(); i++){
        int value = 0;
        auto temp = prices[i];

        for(int j=i+1; j < prices.size(); j++){
            if(temp <= prices[j]){
                value++;
            }else{
                value++;
                break;
            }
        }

        answer.push_back(value);
    }

    return answer;
}

int main() {

    vector<int> arr = {1, 2, 3, 2, 3};

    auto rtn = solution(arr);
    for(auto item : rtn){
        cout << item << " ";
    }

    return 0;
}