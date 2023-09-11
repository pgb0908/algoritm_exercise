#include <string>
#include <vector>
#include <iostream>
using namespace std;


int checkRow(vector<string> board, char maker) {
    int bingo = 0;
    for(int i = 0; i < 3; i++){
        char temp = board[i][0];
        bool flag = true;
        for(int j=0; j < 3; j++){
            if(temp != board[i][j])
                flag = false;
        }
        if(flag){
            if(temp == maker){
                bingo++;
            }
        }
    }

    return bingo;
}

int checkCol(vector<string> board, char maker) {
    int bingo = 0;

    for(int i = 0; i < 3; i++){
        char temp = board[0][i];
        bool flag = true;
        for(int j=0; j < 3; j++){
            if(temp != board[j][i])
                flag = false;
        }
        if(flag){
            if(temp == maker){
                bingo++;
            }
        }
    }
    return bingo;
}

int checkDiagonal(vector<string> board, char maker) {
    int bingo = 0;

    bool flag1 = false;
    bool flag2 = false;
    if((board[0][0] == board[1][1])
            &&  board[1][1] == board[2][2])
        flag1 = true;

    if(flag1){
        if(board[0][0] == maker){
            bingo++;
        }
    }

    if(board[2][0] == board[1][1] &&
            board[1][1]  == board[0][2])
        flag2 = true;

    if(flag2){
        if(board[2][0] == maker){
            bingo++;
        }
    }

    return  bingo;
}

bool checkBingo(vector<string> board, char maker) {
    auto row = checkRow(board, maker);
    auto col = checkCol(board, maker);
    auto dia = checkDiagonal(board, maker);

    if(row + col + dia > 0) return true;

    return false;
}

int solution(vector<string> board) {
    // 후공만 있을 때
    int o_cnt = 0;
    int x_cnt = 0;
    int dot_cnt = 0;
    for(const auto& row : board){
        for(const auto& tic : row){
            if(tic == 'O') o_cnt++;
            else if(tic == 'X') x_cnt++;
            else dot_cnt++;
        }
    }
    if(dot_cnt == 9) return 1;
    if(o_cnt == 0 && x_cnt != 0) return 0;
    if( o_cnt - x_cnt > 1) return 0;
    if( o_cnt < x_cnt) return 0;

    //승부가 났는가?
    bool o_bingo = checkBingo(board, 'O');
    bool x_bingo = checkBingo(board, 'X');

    if(o_bingo && x_bingo){
        return 0;
    }else if(o_bingo ){
        if(o_cnt-1 != x_cnt) return 0;
    }else if(x_bingo){
        if(o_cnt != x_cnt) return 0;
    }
    return 1;
}




int main() {
    /*
    board	result
    ["O.X", ".O.", "..X"]	1
    ["OOO", "...", "XXX"]	0
    ["...", ".X.", "..."]	0
    ["...", "...", "..."]	1
    ["XXX", "XOO", "OO."]  1
         ["XXO", "XXO", "OOO"]  0
    */

    vector<string> s1= {"O.X", ".O.", "..X"};
    vector<string> s2= {"OOO", "...", "XXX"};
    vector<string> s3= {"...", ".X.", "..."};
    vector<string> s4= {"...", "...", "..."};
    vector<string> s5= {"XXX", "XOO", "OO."};
    vector<string> s6= {"XXO", "XXO", "OOO"};
    auto rtn = solution(s5);

    cout << rtn << " ";


    return 0;
}