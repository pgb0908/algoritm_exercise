#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int n) {
    long long answer = 0;

    vector<long long> vec(2001, 0);
    vec[1] = 1;
    vec[2] = 2;

    if(n == 1) return 1;
    if(n == 2) return 2;

    int index = 3;
    while(true){
        vec[index] = (vec[index-2] + vec[index-1]) % 1234567;
        if(index == n) break;
        index++;
    }

    return vec[index];
}


int main() {

/**
 *
    n	result
    4	5
    3	3
 *
 */

    int n = 4;
    

    auto rtn = solution(n);

    cout << rtn << endl;

    return 0;
}