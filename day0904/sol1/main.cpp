#include <string>
#include <vector>
#include <iostream>

using namespace std;

int NUM_ZERO = 0;
int NUM_ONE = 0;
vector<vector<int>> G_ARR;

void  recursive(int x, int y, int Size){
    bool break_flag;
    bool flag = false;
    int old = G_ARR[x][y];
    for(int i = x; i < x+ Size; i++){
        break_flag = false;
        for(int j=y; j < y + Size; j++){
            if(old != G_ARR[i][j]){
                break_flag = true;
                flag = false;
                break;
            } else {
                flag = true;
            }
        }
        if(break_flag) break;
    }

    if(flag){
        if(G_ARR[x][y] == 0){
            NUM_ZERO++;
            return;
        }else{
            NUM_ONE++;
            return;
        }
    }


    recursive(x, y, Size / 2);
    recursive(x, y + Size / 2, Size / 2);
    recursive(x + Size / 2, y, Size / 2);
    recursive(x + Size / 2, y + Size / 2, Size / 2);
}

vector<int> solution(vector<vector<int>> arr) {

    G_ARR = arr;
    recursive(0, 0, G_ARR.size());

    return {NUM_ZERO, NUM_ONE};
}

int main() {

    /*
     {{1,1,0,0},
     {1,0,0,0},
     {1,0,0,1},
     {1,1,1,1}}	{4,9}


{{1,1,1,1,1,1,1,1},{0,1,1,1,1,1,1,1},{0,0,0,0,1,1,1,1},{0,1,0,0,1,1,1,1},{0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,1},{0,0,0,0,1,0,0,1},{0,0,0,0,1,1,1,1}}	{10,15}
     */

    vector<vector<int>> arr = {{1,1,0,0},{1,0,0,0},{1,0,0,1},{1,1,1,1}};
    vector<vector<int>> arr2 = {{1,1,1,1,1,1,1,1},{0,1,1,1,1,1,1,1},{0,0,0,0,1,1,1,1},{0,1,0,0,1,1,1,1},{0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,1},{0,0,0,0,1,0,0,1},{0,0,0,0,1,1,1,1}};

    auto rtn = solution(arr);

    cout << rtn[0] << " " << rtn[1] << " ";

    return 0;
}