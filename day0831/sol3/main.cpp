#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end());

    int size = citations.size();
    int idx = size;
    while(true){
        int over_h = size - idx+1;
        if(citations[idx-1] >= over_h){
            idx--;
            answer++;

        }else{
            break;
        }
    }

    return answer;
}



int main() {

    /*
    [3, 0, 6, 1, 5]	3
     [6, 5, 5, 5, 3, 2, 1, 0]	4
     */

    vector<int> arr = {3, 0, 6, 1, 5};
    arr = {0, 5, 6, 7, 8};

    auto rtn = solution(arr);

    cout << rtn << " ";

    return 0;
}