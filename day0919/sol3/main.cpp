#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int sizeY;
int sizeX;

int removeBrick(vector<string>& board){
    int count = 0;
    vector<pair<int, int>> list= {{0, 1}, {1, 0}, {1,1}, {0, 0}};
    vector<vector<bool>> remove_list(sizeY, vector<bool>(sizeX, false));

    for(int y=0; y < sizeY-1; y++){
        for(int x = 0; x < sizeX-1; x++){
            char temp = board[y][x];
            bool flag = true;
            for(auto region : list){
                auto next = board[y+region.second][x+region.first];
                if(next == '-'){
                    flag = false;
                    break;
                }
                if(temp != next){
                    flag = false;
                    break;
                }
            }

            if(flag){
                for(auto region : list){
                    remove_list[y+region.second][x+region.first] = true;
                }
            }
        }
    }

    // 빈 값에 '-' 넣기
    for(int y= 0; y < sizeY; y++){
        for(int x=0; x < sizeX; x++){
            if(remove_list[y][x]){
                board[y][x] = '-';
                count++;
            }
        }
    }

    // 빈 값 아래로 내리기
    for(int x=0; x < sizeX; x++){
        queue<char> temp;
        for(int y = sizeY-1; y >= 0; y--){
            if(board[y][x] != '-'){
                temp.push(board[y][x]);
            }
        }

        for(int y=sizeY-1; y >= 0; y--){
            if(!temp.empty()){
                auto item = temp.front();
                temp.pop();
                board[y][x] = item;
            }else{
                board[y][x] = '-';
            }
        }
    }

    return count;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    sizeY = m;
    sizeX = n;

    vector<string> old = board;

    while(true){
        int temp = removeBrick(old);
        answer += temp;

/*        for(int y=0; y < sizeY; y++){
            for(int x = 0; x < sizeX; x++){
                cout << old[y][x] << " ";
            }
            cout << endl;
        }
        cout << endl;*/

        if(temp == 0) break;
    }


    return answer;
}

int main() {
    /*
    4	5	["CCBDE", "AAADE", "AAABF", "CCBBF"]	14
    6	6	["TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"]	15
    */

    int m,n;

/*    m= 4; //y
    n = 5; //x
    vector<string> s = {"CCBDE", "AAADE", "AAABF", "CCBBF"};*/

    m= 6; //y
    n = 6; //x
    vector<string> s = {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"};

    auto rtn = solution(m, n, s);

    cout << rtn << " ";


    return 0;
}