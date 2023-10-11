#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> changMius(vector<int>& s, bool flag){
    vector<int> temp;

    for(const auto item : s){

        if(flag){
            temp.push_back(item * -1);
            flag = false;
        }else{
            temp.push_back(item);
            flag = true;
        }
    }

    return temp;
}


long long solution(vector<int> sequence) {
    auto seq1 = changMius(sequence, true);
    auto seq2 = changMius(sequence, false);

    long long answer = -999999999;
    long long dp1[seq1.size()]; // 1 dp 배열
    long long dp2[seq2.size()];// -1 dp 배열

    dp1[0] = seq1[0];
    dp2[0] = seq2[0];
    for(int i = 1; i < seq1.size(); i++){
        // max로 비교위해 자료형 치환
        dp1[i] = max(dp1[i-1]+(long long)seq1[i],(long long)seq1[i]);
        answer = max(answer,dp1[i]);
    }
    for(int i = 1; i < seq2.size(); i++){
        // 아까 했던 점화식
        dp2[i] = max(dp2[i-1]+(long long)seq2[i],(long long)seq2[i]);
        answer = max(answer,dp2[i]);
    }
    // 1일때는 그냥 둘 중 더 큰거
    if(sequence.size() == 1){
        answer = max(seq1[0],seq2[0]);
        return answer;
    }

    return answer;
}



int main() {
    /*
    sequence	result
    [2, 3, -6, 1, 3, -1, 2, 4]	10
    */

    vector<int> v = {2, 3, -6, 1, 3, -1, 2, 4};
    auto rtn = solution(v);

    cout << rtn << " ";


    return 0;
}