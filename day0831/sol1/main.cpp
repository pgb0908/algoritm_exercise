#include <string>
#include <vector>
#include <iostream>
using namespace std;

void recursive(vector<int> numbers, vector<int> arr, int size, int target, int idx, int* rtn){
    if(size == arr.size()){
        int temp = 0;
        for(auto item : arr){
            cout << item << " ";
            temp += item;
        }
        cout << endl;
        if(temp == target) (*rtn)++;

        return;
    }

    auto temp = std::abs(numbers[idx]);
    arr.push_back(temp);
    recursive(numbers, arr, size, target, idx+1, rtn);
    arr.pop_back();
    arr.push_back(-temp);
    recursive(numbers, arr, size, target, idx+1, rtn);
}

int solution(vector<int> numbers, int target) {
    int size = numbers.size();
    int rtn = 0;

    vector<int> arr;
    recursive(numbers, arr, size, target, 0, &rtn);

    return rtn;
}

int main() {

    /*
     * [1, 1, 1, 1, 1]	3	5
     * [4, 1, 2, 1]	4	2
     */

    vector<int> arr = {1, 1, 1, 1, 1};
    vector<int> arr2 = {4, 1, 2, 1};

    auto rtn = solution(arr2, 4);

    cout << rtn << " ";

    return 0;
}