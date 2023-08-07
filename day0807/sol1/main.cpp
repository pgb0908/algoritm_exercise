#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;




// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    vector<vector<bool>> found(m, vector<bool>(n, false));
    vector<int> coloerCnt;

    const int dirX[4] = {0, -1, 0, 1};
    const int dirY[4] = {1, 0, -1, 0};

    for(int i= 0; i< picture.size(); i++){
        for(int j=0; j < picture[i].size(); j++){

            if(picture[i][j] ==0 || found[i][j]) continue;

            // BFS 시작
            int row = i;
            int col = j;
            queue<pair<int, int>> q;
            q.emplace(row, col);
            found[row][col] = true;

            coloerCnt.push_back(1);

            while(!q.empty()){
                auto pos = q.front();
                row = pos.first;
                col = pos.second;

                q.pop();

                for(int k =0; k < 4; k++){
                    int new_row = row + dirX[k];
                    int new_col = col + dirY[k];

                    // 다음 스텝이 만족할 조건
                    if(new_row < 0 || new_row > m-1
                            || new_col < 0 || new_col > n-1){
                        continue;
                    }
                    if(found[new_row][new_col]){
                        continue;
                    }
                    if(picture[row][col] != picture[new_row][new_col]){
                        continue;
                    }

                    found[new_row][new_col]= true;

                    coloerCnt.back()++;

                    q.emplace(new_row, new_col);

                }
            }

        }
    }
    number_of_area = coloerCnt.size();
    max_size_of_one_area = *max_element(coloerCnt.begin(), coloerCnt.end());

    return {number_of_area, max_size_of_one_area};
}


int main() {

    // {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}}
    vector<vector<int>> input = {
            {1, 1, 1, 0},
            {1, 2, 2, 0},
            {1, 0, 0, 1}, 
            {0, 0, 0, 1},
            {0, 0, 0, 3},
            {0, 0, 0, 3}
    };

    auto rtn = solution(6, 4, input);
    //auto rtn = solution(param{1}{0}, param{1}{1}, param{1}{2});
    //auto rtn = solution(param{2}{0}, param{2}{1}, param{2}{2});


    for(auto item : rtn){
        cout << item << " ";
    }
    cout << endl;

    return 0;
}