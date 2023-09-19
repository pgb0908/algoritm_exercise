#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

pair<int, int> basePoint(pair<int, int> point, char base, int line){
    int fx = point.first;
    int fy = point.second;

    if(base == 'x' ){
        if(line == 0){
            fy = -1*fy;
        }else{
            int temp = abs(line - fy);
            fy = fy + 2*temp;
        }
    }else{
        if(line == 0){
            fx = -1*fx;
        }else{
            int temp = abs(line - fx);
            fx = fx + 2*temp;
        }
    }

    return {fx, fy};
}

int getLengthSquare(pair<int, int> start, pair<int, int> end){
    return pow((end.second - start.second), 2) + pow((end.first - start.first), 2);
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    pair<int, int> start(startX, startY);
    vector<pair<int ,char>> all_case = {{n, 'x'}, {0, 'x'}, {m, 'y'}, {0, 'y'}};


    for(auto round : balls){
        pair<int, int> target(round[0], round[1]);

        vector<int> temp;
        for(int i=0; i < 4; i++){
            auto cur = all_case[i];
            auto base = basePoint(start, cur.second, cur.first);

            if(base.second == target.second){
                // y좌표가 같을 때

                // 치는 돌이 왼쪽이냐 오른쪽이냐


            }else if(base.first == target.first){
                // x좌표가 같을 때

                // 치는 돌이 위쪽이냐 아래쪽이냐
            }else{
                // 둘다 다를때
                auto length = getLengthSquare(target, base);
                temp.push_back(length);
            }





            if(cur.second == 'y' && (cur.first == 0) && (base.second == target.second)
                && (start.first >= target.first)) continue;

            if(cur.second == 'y' && (cur.first != 0) && (base.second == target.second)
               && (start.first <= target.first)) continue;

            if(cur.second == 'x' && (cur.first == 0) && (base.first == target.first)
               && (start.first >= target.first)) continue;

            if(cur.second == 'x' && (cur.first != 0) && (base.first == target.first)
               && (start.first <= target.first)) continue;

            if(cur.second == 'y' && (cur.first == 0) && (0 == target.second)
               && (start.first >= target.first)) continue;

            if(cur.second == 'y' && (cur.first != 0) && (n == target.second)
               && (start.first <= target.first)) continue;

            if(cur.second == 'x' && (cur.first == 0) && (0== target.first)
               && (start.first >= target.first)) continue;

            if(cur.second == 'x' && (cur.first != 0) && (m == target.first)
               && (start.first <= target.first)) continue;

            if(base == start){
                continue;
            }


        }

        auto item = min_element(temp.begin(), temp.end());
        answer.push_back(*item);
    }


    return answer;
}

int main() {

    /*
    m	n	startX	startY	balls	result
    10	10	3	7	{{7, 7}, {2, 7}, {7, 3}}	{52, 37, 116}
     3, 3, 1, 1, [[1, 2]]: [5]
     */

    int m, n, startX, startY;
/*    m = 10;
    n = 10;
    startX = 3;
    startY = 7;
    vector<vector<int>> balls = {{7, 7}, {2, 7}, {7, 3}};*/

    m = 5;
    n = 5;
    startX = 2;
    startY = 2;
    vector<vector<int>> balls = {{1, 0}};
    

    auto rtn = solution(m, n, startX, startY, balls);

    for(auto item : rtn){
        cout << item << " " << endl;
    }


    return 0;
}