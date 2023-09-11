#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int xSize;
int ySize;
vector<string> MAP;


struct NODE{
    NODE(){};
    NODE(pair<int, int> loc){
        loc_ = loc;
        time_ = 0;
    }
    pair<int, int> loc_;
    int time_{0};
};

bool checkRange(NODE step, vector<vector<bool>>& visited){
    int row = step.loc_.first;
    int col = step.loc_.second;

    if(row >= 0 && row < ySize && col >=0 && col < xSize ){
        if(MAP[row][col] != 'X'){
            if(!visited[row][col]){
                return true;
            }
        }
    }

    return false;
}

int moveTo(pair<int, int> src, pair<int, int> dst){
    bool done =false;
    int time = 2147000000;
    auto visited = vector<vector<bool>>(ySize, vector<bool>(xSize, false));
    queue<NODE> queue;

    NODE node({src.first, src.second});
    queue.push(node);
    visited[src.first][src.second] = true;

    while(!queue.empty()){
        auto temp = queue.front();
        queue.pop();

        if(temp.loc_.first == dst.first &&
           temp.loc_.second == dst.second){

            done = true;
            time = min(time, temp.time_);

            break;
        }

        for(int i=0; i< 4; i++){
            NODE next_node;
            if(i == 0){
                // 위 0, +1
                next_node.loc_.first = temp.loc_.first;
                next_node.loc_.second = temp.loc_.second+1;

                auto result = checkRange(next_node, visited);
                if(!result) continue;

                visited[next_node.loc_.first][next_node.loc_.second] = true;
                next_node.time_ = temp.time_ +1;
                queue.push(next_node);

            }else if(i == 1){
                // 오른 +1, 0
                next_node.loc_.first = temp.loc_.first+1;
                next_node.loc_.second = temp.loc_.second;

                auto result = checkRange(next_node, visited);
                if(!result) continue;

                visited[next_node.loc_.first][next_node.loc_.second] = true;
                next_node.time_ = temp.time_ +1;
                queue.push(next_node);

            }else if(i == 2){
                // 아래 0, -1
                next_node.loc_.first = temp.loc_.first;
                next_node.loc_.second = temp.loc_.second-1;

                auto result = checkRange(next_node, visited);
                if(!result) continue;

                visited[next_node.loc_.first][next_node.loc_.second] = true;
                next_node.time_ = temp.time_ +1;
                queue.push(next_node);
            }else {
                // 왼 -1, 0
                next_node.loc_.first = temp.loc_.first-1;
                next_node.loc_.second = temp.loc_.second;

                auto result = checkRange(next_node, visited);
                if(!result) continue;

                visited[next_node.loc_.first][next_node.loc_.second] = true;
                next_node.time_ = temp.time_ +1;
                queue.push(next_node);
            }
        }
    }

    if(done){
        return time;
    }else{
        return -1;
    }


}


int solution(vector<string> maps) {
    int answer = 0;
    MAP = maps;
    xSize = maps[0].length();
    ySize = maps.size();
    pair<int, int> src, lever, fin;

    for(int i= 0; i < ySize; i++){
        for(int j=0; j< xSize; j++){
            if(MAP[i][j] == 'S'){
                src.first = i;
                src.second = j;
            }

            if(MAP[i][j] == 'L'){
                lever.first = i;
                lever.second = j;
            }

            if(MAP[i][j] == 'E'){
                fin.first = i;
                fin.second = j;
            }
        }
    }

    auto flag_step = moveTo(src, lever);
    auto fin_step = moveTo(lever, fin);
    if(flag_step == -1 || fin_step == -1 ) return -1;

    answer = flag_step + fin_step;
    return answer;
}

int main() {

    /*
        maps	result
        ["SOOOL","XXXXO","OOOOO","OXXXX","OOOOE"]	16
        ["LOOXS","OOOOX","OOOOO","OOOOO","EOOOO"]	-1
     */

    vector<string> arr = {"SOOOL","XXXXO","OOOOO","OXXXX","OOOOE"};
    vector<string> arr2 = {"LOOXS","OOOOX","OOOOO","OOOOO","EOOOO"};

    auto rtn = solution(arr2);

    cout << rtn << endl;

    return 0;
}