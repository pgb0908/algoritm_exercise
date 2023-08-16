#include <vector>
#include <iostream>
#include <map>
#include <string>

using namespace std;

bool checkMap(int x, int y){
    bool rtn = false;
    if(x > 10 || y > 10 || x < 0 || y < 0){
        rtn = true;
    }

    return rtn;
}

int solution(string dirs) {
    int answer = 0;
    // U(0), R(1), L(2), D(3)
    int x[] =  {0, 1, -1, 0};
    int y[] =  {1, 0, 0, -1};

    int start_x = 5;
    int start_y = 5;

    map<pair<pair<int, int>, pair<int,int>>, bool> visited;

    for(auto op : dirs){
        int next_x = start_x;
        int next_y = start_y;

        switch (op) {
            case 'U':
                if(checkMap(start_x + x[0],start_y+ y[0]))
                    continue;
                next_x = start_x +x[0];
                next_y = start_y +y[0];
                break;
            case 'R':
                if(checkMap(start_x + x[1],start_y+ y[1]))
                    continue;
                next_x = start_x +x[1];
                next_y = start_y +y[1];
                break;
            case 'L':
                if(checkMap(start_x + x[2],start_y+ y[2]))
                    continue;
                next_x = start_x +x[2];
                next_y = start_y +y[2];
                break;
            case 'D':
                if(checkMap(start_x + x[3],start_y+ y[3]))
                    continue;
                next_x = start_x +x[3];
                next_y = start_y +y[3];
                break;
            default:
                break;
        }


        if(visited[{{start_x, start_y},{next_x, next_y}}]) {
            start_x = next_x;
            start_y = next_y;
            continue;
        }

        visited[{{start_x, start_y},{next_x, next_y}}] = true;
        visited[{{next_x, next_y},{start_x, start_y}}] = true;
        answer++;

        start_x = next_x;
        start_y = next_y;
    }


    return answer;
}

int main() {

    string s1 = "ULURRDLLU";  // 7
    string s2 = "LULLLLLLU";  // 7
    string s3 = "RRRRRLLLLL";  // 5

    auto rtn = solution(s1);

    cout << rtn << std::endl;

    return 0;
}