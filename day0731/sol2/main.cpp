#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;



int solution(vector<int> scoville, int K) {
    int answer = 0;
    std::priority_queue<int, vector<int>, greater<>> pq(scoville.begin(), scoville.end());

    while(true){
        if(pq.size() < 2) break;
        if(pq.top() >= K) break;

        answer++;

        auto one = pq.top();
        pq.pop();
        auto two = pq.top();
        pq.pop();
        pq.push(one + two*2);
    }

    if(pq.top() < K){
        answer = -1;
    }



    return answer;
}



int solution2(vector<int> scoville, int K) {
    int answer = 0;

    std::sort(scoville.begin(), scoville.end());

    while(true){
        if(scoville.size() < 2) break;
        if(scoville[0] >= K) break;
        answer++;

        auto new_one = scoville[0] + scoville[1]*2;
        scoville.erase(scoville.begin(), scoville.begin()+2);

        bool flag = false;
        for(int i=0; i< scoville.size(); i++){
            if(scoville[i] > new_one){
                flag = true;
                scoville.insert(scoville.begin()+i, new_one);
                break;
            }
        }
        if(!flag){
            scoville.push_back(new_one);
        }
    }

    if(scoville[0] < K){
        answer = -1;
    }

    return answer;
}


int main() {

    vector<int> s{1, 2, 3, 9, 10, 12};
    int k = 7;



    auto rtn = solution(s, k);

    std::cout << rtn << std::endl;


    return 0;
}
