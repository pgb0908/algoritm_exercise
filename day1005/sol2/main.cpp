#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    vector<int> vec(100001, 0);
    vec[0] = 0;
    vec[1] = 1;
    vec[2] = 1;

    if(n <= 2) return vec[n];

    int index = 3;
    while(true){
        vec[index] = (vec[index-2] + vec[index-1]) % 1234567;
        if(index == n) break;
        index++;
    }

    return vec[index];
}


int main() {
    /*
    n	return
    3	2
    5	5
    */

    int n;

    n = 2;
    auto rtn = solution(n);

    cout << rtn << " ";


    return 0;
}