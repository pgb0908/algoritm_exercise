#include<vector>
#include <iostream>
#include <queue>
using namespace std;

struct NODE{
    int x_;
    int y_;
    int time;
};

int max_value = 99999;

int solution(vector<vector<int>> maps)
{
    int answer = max_value;
    int sizeY = maps.size();
    int sizeX = maps[0].size();
    vector<vector<bool>> visited(sizeY, vector<bool>(sizeX, false));

    queue<NODE> queue;
    visited[0][0] = true;

    NODE first;
    first.x_ = 0;
    first.y_ = 0;
    first.time = 0;
    queue.push(first);

    bool done = false;

    while(!queue.empty()){
        auto curr = queue.front();
        queue.pop();

        if(curr.x_ == sizeX-1 && curr.y_ == sizeY-1){
            if(answer > curr.time){
                answer = curr.time;
            }
            done = true;
            break;
        }

/*        for(auto item : visited){
            for(auto bb : item){
                cout << bb << " ";
            }
            cout << endl;
        }cout << endl;*/

        for(int i=0; i< 4; i++){
            NODE new_step;
            new_step = curr;

            if(i ==0){
                // up
                new_step.y_++;
                if(new_step.x_ < 0 || new_step.x_ >= sizeX ||
                    new_step.y_ < 0 || new_step.y_ >= sizeY)
                    continue;

                if(visited[new_step.y_][new_step.x_]
                || maps[new_step.y_][new_step.x_] == 0) continue;

                visited[new_step.y_][new_step.x_] = true;
                new_step.time++;
                queue.push(new_step);

            }else if(i == 1){
                // right
                new_step.x_++;

                if(new_step.x_ < 0 || new_step.x_ >= sizeX ||
                   new_step.y_ < 0 || new_step.y_ >= sizeY)
                    continue;

                if(visited[new_step.y_][new_step.x_]
                   || maps[new_step.y_][new_step.x_] == 0) continue;

                visited[new_step.y_][new_step.x_] = true;
                new_step.time++;
                queue.push(new_step);
            }else if(i == 2){
                // down
                new_step.y_--;

                if(new_step.x_ < 0 || new_step.x_ >= sizeX ||
                   new_step.y_ < 0 || new_step.y_ >= sizeY)
                    continue;

                if(visited[new_step.y_][new_step.x_]
                   || maps[new_step.y_][new_step.x_] == 0) continue;

                visited[new_step.y_][new_step.x_] = true;
                new_step.time++;
                queue.push(new_step);
            }else{
                // left
                new_step.x_--;

                if(new_step.x_ < 0 || new_step.x_ >= sizeX ||
                   new_step.y_ < 0 || new_step.y_ >= sizeY)
                    continue;

                if(visited[new_step.y_][new_step.x_]
                   || maps[new_step.y_][new_step.x_] == 0) continue;

                visited[new_step.y_][new_step.x_] = true;
                new_step.time++;
                queue.push(new_step);
            }
        }
    }


    if(!done){
        return -1;
    }


    return ++answer;
}

int main() {
    /*
    {{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}}	11
    {{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,0},{0,0,0,0,1}}	-1
    */

    vector<vector<int>> map = {{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}};
    auto rtn = solution(map);

    cout << rtn << " ";


    return 0;
}