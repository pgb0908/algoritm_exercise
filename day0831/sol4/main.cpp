#include <vector>
#include <iostream>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    set<int> set;
    int size = elements.size();

    for(int num = 1; num <= size; num++){
        int cnt = size;
        while(cnt > 0){
            int temp = 0;
            for(int i=0; i<num; i++){
                temp += elements[i];
            }
            set.insert(temp);

            auto value = elements[0];
            elements.erase(elements.begin(), elements.begin()+1);
            elements.insert(elements.end(), value);
            cnt--;
        }
    }

    return set.size();
}



int main() {

    /*
    [7,9,1,1,4]	18

     [1, 2, 3]
     */

    vector<int> arr = {7,9,1,1,4};
    //arr = {1, 2, 3};

    auto rtn = solution(arr);

    cout << rtn << " ";

    return 0;
}