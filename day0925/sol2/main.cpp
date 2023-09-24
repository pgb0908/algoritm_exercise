#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

vector<int> getBin(int n){
    vector<int> rtn;

    while( n > 0){
        auto d = n % 2;
        rtn.push_back(d);
        n = n / 2;
    }

    //reverse(rtn.begin(), rtn.end());

    return rtn;
}

int getOneNum(int n){
    int one = 0;

    while( n > 0){
        auto d = n % 2;
        if(d == 1) one++;
        n = n / 2;
    }

    //reverse(rtn.begin(), rtn.end());

    return one;
}

int solution(int n) {
    int answer = 0;
    int origin_from_n = getOneNum(n);


    while(true){
        n++;
        if(origin_from_n == getOneNum(n)){
            answer = n;
            break;
        }
    }


    return answer;
}



int main() {
    /*
        n	result
        78	83
        15	23
    */

    int n;

    n = 78;
    auto rtn = solution(n);

    cout << rtn << " ";


    return 0;
}