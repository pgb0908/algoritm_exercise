#include <string>
#include <vector>
#include <iostream>
using namespace std;

void tower(vector<vector<int>>& answer, int n, int start, int dst){
    if(n==1){
        answer.push_back({start, dst});
        return;
    }


    tower(answer, n-1, start, 6-start-dst);
    answer.push_back({start, dst});
    tower(answer, n-1, 6-start-dst, dst);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;

    tower(answer, n, 1, 3);

    return answer;
}

int main() {

    auto rtn = solution(2);

    //[ [1,2], [1,3], [2,3] ]
    for(auto data : rtn){
        for(auto inner : data){
            cout << inner << " ";
        }
        cout << endl;
    }
    cout << endl;



    return 0;
}