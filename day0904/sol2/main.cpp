#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if(n ==1) return false;
    for (int i = 2; i <= sqrt(n); i++) {//2~n의 제곱근까지
        if (n%i == 0) {//i가 n의 약수라면 소수가 아니므로 false return
            return false;
        }
    }
    //2 ~ n-1까지 약수가 없다면 소수이므로, true return
    return true;
}

vector<int> convertN(int n, int k){
    vector<int> vec;

    while(n > 0){
        vec.push_back(n % k);
        int val = n / k;
        n = val;
    }

    reverse(vec.begin(), vec.end());

    return vec;
}

int solution(int n, int k) {
    int answer = 0;

    auto vec = convertN(n, k);

    vector<string> prims;
    string str;
    for(auto number : vec){
        if(number != 0){
            str += to_string(number);
        }else{
            if(!str.empty()){
                prims.push_back(str);
                str.clear();
            }
        }
    }
    if(!str.empty()) prims.push_back(str);
    if(prims.empty()) return -1;

    for(auto& p : prims){
       if(isPrime(stol(p))) answer++;
    }

    return answer;
}

int main() {
    /*
    n	k	result
    437674	3	3
    110011	10	2
    */

    int n = 9999999999999;
    int k = 3;
    auto rtn = solution(n, k);

    cout << rtn << " ";


    return 0;
}