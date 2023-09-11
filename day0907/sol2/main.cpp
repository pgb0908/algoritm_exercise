#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string s) {
    std::vector<int> str_vec;
    string temp;
    for(auto item : s){
        if(item != ' '){
            temp += item;
        }else{
            if(!temp.empty()){
                str_vec.push_back(stoi(temp));
                temp = "";
            }
        }
    }
    if(!temp.empty()){
        str_vec.push_back(stoi(temp));
        temp = "";
    }

    sort(str_vec.begin(), str_vec.end());


    return to_string(*str_vec.begin()) + " " + to_string(*(str_vec.end()-1));
}


int main() {
    /*
        s	return
        "1 2 3 4"	"1 4"
        "-1 -2 -3 -4"	"-4 -1"
        "-1 -1"	"-1 -1"
    */

    string s = "1 2 3 4";
    auto rtn = solution(s);

    cout << rtn << " ";


    return 0;
}