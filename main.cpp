#include <iostream>
#include <vector>

using namespace std;

double DIS[4] = {10, 20, 30, 40};

void getAllCase(vector<int> sale, vector<vector<int>> users, vector<int> emoticons){
    if(sale.size() == emoticons.size()){

    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons){
    int value = 0;
    int plus = 0;

    // 할인률 * 최대 7개의 이모티콘 조합구합
    getAllCase();

    // 위 조합으로 루프 돌려 {합, 가입자}의 리스트 구하기

    // max 가입자, max 합 으로 최종 결과 구하기


    return {value, plus};
}

int main() {
    //vector<vector<int>> user{{40, 2900}, {23, 10000}, {11, 5200}, {5, 5900}, {40, 3100}, {27, 9200}, {32, 6900}};
    //vector<int> emo{1300, 1500, 1600, 4900};
    vector<vector<int>> user{{40, 10000}, {25, 10000}};
    vector<int> emo{7000, 9000};

    auto ans = solution(user, emo);

    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
