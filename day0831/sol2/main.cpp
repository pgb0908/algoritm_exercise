#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define MODULER 1000000007


int solution(int n) {
    if(n%2 == 1) return 0;

    vector<int64_t> vec(5000, 0);
    vec[0] = 1;
    vec[2] = 3;

    for(int i= 4; i <= n; i += 2){
        vec[i] += vec[i-2]*3;

        for(int j= 0; j<= i-4; j += 2){
            vec[i] += vec[j]*2;
        }
        vec[i] %= MODULER;
    }

    return (int)vec[n];
}

int solution2(int n)
{
    if(n % 2 == 1) return 0;
    long long DP[5010] = { 0, };
    DP[0] = 1;
    DP[2] = 3;
    for(int i = 4; i <= n ; i = i + 2)
    {
        DP[i] = DP[i - 2] * 3;
        for(int j = i - 4; j >= 0 ; j = j - 2)
        {
            DP[i] = DP[i] + DP[j] * 2;
        }
        DP[i] = DP[i] % MODULER;
    }

    return (int)DP[n];
}


int main() {

    // 4	11
    int n = 200;
    auto rtn = solution(n);
    auto rtn2 = solution2(n);

    cout << rtn << " " << rtn2;


    return 0;
}