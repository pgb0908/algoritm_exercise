#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;

    for(int i =1; i < r2; i++){
        double outer = 0;
        double inner = 0;
        outer = sqrt((double)pow(r2, 2) - (double)pow(i, 2));

        if(i < r1){
            inner = sqrt((double)pow(r1, 2) - (double)pow(i, 2));
        }else{
            inner = 1;
        }

        outer = floor(outer);
        inner = ceil(inner);

        answer += (outer - inner+1);
    }

    return (answer+r2-r1+1)*4;
}




int main() {
    /*
    r1	r2	result
    2	3	20
    */

    auto rtn = solution(2, 3);

    cout << rtn << " ";


    return 0;
}