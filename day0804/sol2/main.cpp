//
// Created by bong on 23. 8. 4.
//


#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 0. x에 n을 더하기
// 1. x에 2를 곱하기
// 2. x에 3을 곱하기
int largest = 999999;
int MIN = largest;


int solution(int x, int y, int n) {
    int answer = 0;

    vector<int> DP(1000001, 1000001);
    DP[y] = 0;

    for(int i = y; i > x; i--)
    {
        if (DP[i] != 1000001)
        {
            if(i % 3 == 0)
                DP[i/3] = min(DP[i/3], DP[i] + 1);
            if(i % 2 == 0)
                DP[i/2] = min(DP[i/2], DP[i] + 1);
            if(i - n > 0)
                DP[i - n] = min(DP[i-n], DP[i] + 1);
        }
    }

    if(DP[x] == 1000001)
        DP[x] = -1;
    answer = DP[x];
    return answer;
}


void recursive(int x, int y, int n, int answer){
    if(x == y){
        if(answer < MIN){
            MIN = answer;
        }
        return;
    }
    else if( x > y){
        return;
    }

    recursive(x+n, y, n, answer+1);
    recursive(x*2, y, n, answer+1);
    recursive(x*3, y, n, answer+1);
}


int solution2(int x, int y, int n) {
    int answer = 0;

    recursive(x, y, n, answer);

    if(MIN != largest){
        answer = MIN;
    }else{
        answer = -1;
    }

    return answer;
}

int main() {

    vector<vector<int>> param = {{10, 40, 5},      // 2
                                 {10, 40, 30},     // 1
                                 {2, 5, 4}         // -1
    };

    auto rtn = solution(param[0][0], param[0][1], param[0][2]);
    //auto rtn = solution(param[1][0], param[1][1], param[1][2]);
    //auto rtn = solution(param[2][0], param[2][1], param[2][2]);


    cout << rtn << endl;

    return 0;
}