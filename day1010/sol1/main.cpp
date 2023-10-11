#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool oneCharDiff(string& one, string& two){
    int size = one.size();

    int diff = 0;
    for(int i =0; i< size; i++){
        if(one[i] == two[i]) diff++;
    }

    if(diff == size-1){
        return true;
    }else{
        return false;
    }
}

struct STR{
    int cnt;
    string str;
};

int visited[51]; //중복체크용 배열

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    int size = words.size();

    bool find = false;
    for(const auto& w : words){
        if(w == target){
            find = true;
            break;
        }
    }

    if(!find) return answer;

    queue<STR> q;
    STR str;
    str.cnt = 1;
    str.str = target;
    q.push(str);

    while(!q.empty()){
       auto item =  q.front();
       // begin과 하나 차이이면 탈출
       if(oneCharDiff(item.str, begin)){
           return item.cnt;
       }
       q.pop();

        for(int i=0; i<words.size(); i++){ //모든 문자열 탐색
            if(visited[i]==1) continue; //만약 방문한 문자열이면 건너뛰기

            if(oneCharDiff(item.str, words[i])){
                STR newOne;
                newOne.str = words[i];
                newOne.cnt=item.cnt+1;
                visited[i]=1;
                q.push(newOne); //다른 문자 1개 이하라면 변환 가능, 큐에 삽입
            }
        }


    }


    return answer;
}


int main() {

/**
 *
    begin	target	words	return
    "hit"	"cog"	["hot", "dot", "dog", "lot", "log", "cog"]	4
    "hit"	"cog"	["hot", "dot", "dog", "lot", "log"]	0
 *
 */

    string s1, s2;
    vector<string> words;

    s1 = "hit";
    s2 = "cog";
    words = {"hot", "dot", "dog", "lot", "log", "cog"};

    auto rtn = solution(s1, s2, words);

    cout << rtn << endl;

    return 0;
}