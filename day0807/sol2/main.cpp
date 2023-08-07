//
// Created by bong on 23. 8. 4.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;


bool findAndErase(string& str, const string& find){
    bool chk = false;
    auto idx = str.find(find);
    if(idx != string::npos){
        chk = true;
        str.erase(idx, find.length());
    }

    return chk;
}

int solution(string s) {
    int count = 0;
    for(int i=0; i< s.size(); i++){

        auto temp = s[0];
        s.erase(s.begin());
        s.insert(s.end(), temp);

        auto copy = s;
        while(!copy.empty()){
            bool chk1 = findAndErase(copy, "[]");
            bool chk2 = findAndErase(copy, "{}");
            bool chk3 = findAndErase(copy, "()");

            if(!chk1 && !chk2 && !chk3) break;
        }

        if(copy.empty()) count++;
    }


    return count;
}

int main() {

//    "[](){}"	3
//    "}]()[{"	2
//    "[)(]"	0
//    "}}}"
    string s1 = "[](){}";
    string s2 = "}]()[{";
    string s3 = "[)(]";
    string s4 = "}}}";



    auto rtn = solution(s3);
    //auto rtn = solution(param[1][0], param[1][1], param[1][2]);
    //auto rtn = solution(param[2][0], param[2][1], param[2][2]);


    cout << rtn << endl;

    return 0;
}