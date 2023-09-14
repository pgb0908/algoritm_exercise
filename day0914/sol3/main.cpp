#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;


int getInt(double x) {
    return floor(x)+1;
}

int getOutLine(double x) {
    double temp = 0.;
    int cnt = 0;
    while(x > temp){
        temp++;
        cnt++;
    }
    return cnt;
}

int getSpotWithCircle(int radius) {
    int total = 0;
    for(int i=0; i<= radius; i++){
        double x = sqrt(pow(radius, 2) - pow(i, 2));
        total += getInt(x);
    }

    total *=4;
    total -= radius*4;
    total -= 3;

    return total;
}

int getSpotWithoutCircle(int radius) {
    int total = 0;
    for(int i=0; i<= radius; i++){
        double x = sqrt(pow(radius, 2) - pow(i, 2));
        total += getOutLine(x);
    }

    total *=4;
    total -= (radius-1)*4;
    total -= 3;

    return total;
}


long long solution(int r1, int r2) {
    long long answer = 0;

    int outer = getSpotWithCircle(r2);
    int inner = getSpotWithoutCircle(r1);

    return outer - inner;
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