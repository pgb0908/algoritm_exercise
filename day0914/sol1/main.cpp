#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


vector<string> normalize(string& str){
    vector<string> rtn;
    for(int i=0; i< str.size()-1; i++){
        bool flag1 = false;
        bool flag2 = false;
        string temp;
        char first, second;
        first = str[i];
        second = str[i+1];

        if((first >= 65 && first <= 90)  ||
           (first >= 97 && first <= 122)){
            flag1 = true;
        }

        if((second >= 65 && second <= 90)  ||
           (second >= 97 && second <= 122)){
            flag2 = true;
        }

        if(flag1 && flag2){
            temp += _tolower(first);
            temp += _tolower(second);
            rtn.push_back(temp);
        }
    }

    return rtn;
}

int solution(string str1, string str2) {
    int answer = 0;

    // 정규화
    // 1. 2글자씩
    // 2. 대/소 --> 소문자
    // 3. 특수문자, 숫자 제외
    auto normal_str1 = normalize(str1);
    auto normal_str2 = normalize(str2);

    unordered_map<string, int> map1;
    for(auto item : normal_str1){
        map1[item]++;
    }

    unordered_map<string, int> map2;
    for(auto item : normal_str2){
        map2[item]++;
    }

    // 교집합
    int co = 0;
    for(auto pair : map1){
        auto found = map2.find(pair.first);
        if(found != map2.end()){
            if(found->second == map1[pair.first]){
                co += map1[pair.first];
            }else if(found->second > map1[pair.first]){
                co += map1[pair.first];
            }else{
                co += found->second;
            }
        }
    }

    // 합집합
    int hap = 0;
    for(auto pair : map1){
        auto found = map2.find(pair.first);
        if(found != map2.end()){
            if(found->second > map1[pair.first]){
                hap += found->second;
            }
        }else{
            hap += pair.second;
        }
    }

    for(auto pair : map2){
        auto found = map1.find(pair.first);
        if(found != map1.end()){
            if(found->second >= map2[pair.first]){
                hap += found->second ;
            }
        }else{
            hap += pair.second;
        }
    }

    // 분수
    // !! 공집합일 경우
    int x = 65536;
    if(hap == 0) return 1*x;

    double ans = double(co)/double(hap);
    answer = ans*x;
    return answer;
}

int main() {

    /*
        str1	str2	answer
        FRANCE	french	16384
        handshake	shake hands	65536
        aa1+aa2	AAAA12	43690
        E=M*C^2	e=m*c^2	65536
     */

    string str1, str2;

/*    str1 = "FRANCE";
    str2 = "french";*/

    str1 = "aa1+aa2";
    str2 = "AAAA12";

    auto rtn = solution(str1, str2);

    cout << rtn << endl;

    return 0;
}