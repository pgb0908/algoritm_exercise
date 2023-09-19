#include <iostream>
#include<string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> stack;

    for(char item : s){
        if(!stack.empty() && stack.top() == item){
            stack.pop();
        }else{
            stack.push(item);
        }
    }

    if(stack.empty()){
        return 1;
    }

    return 0;
}

string extractSame(string str){
    string rtn;

    for(int i=0; i< str.size()-1; i++){
        if(str[i] == str[i+1]){
            str[i] = '-';
            str[i+1] = '-';
            i++;
        }
    }

    for(auto c : str){
        if(c != '-'){
            rtn.push_back(c);
        }
    }

    return rtn;
}

// 효율성 테스트 실패
int solution2(string s)
{
    bool empty = false;
    string old_str = s;

    while (true){
        string new_str = extractSame(old_str);
        if(new_str.empty()){
            empty = true;
            break;
        }
        if(old_str == new_str){
            break;
        }

        old_str = new_str;
    }

    if(empty){
        return 1;
    }

    return 0;
}




int main() {
    /*
        baabaa	1
        cdcd	0
    */

    string s = "baabaa";
    string s1 = "cdcd";
    auto rtn = solution(s1);

    cout << rtn << " ";


    return 0;
}