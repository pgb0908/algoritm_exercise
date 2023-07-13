#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double DIS[4] = {10, 20, 30, 40};


void getAllCase(vector<vector<int>>& all_sale, vector<int>& sale, const vector<int>& emoticons){
    if(sale.size() == emoticons.size()){
        all_sale.push_back(sale);
        return;
    }

    for(int i=0; i< 4; i++){
        sale.push_back(DIS[i]);
        getAllCase(all_sale, sale, emoticons);
        sale.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons){
    int value = 0;
    int plus = 0;

    vector<int> sale;
    vector<vector<int>> all_sale;
    // 할인률 * 최대 7개의 이모티콘 조합구합
    getAllCase(all_sale, sale, emoticons);

    std::cout << "************** all case ****************" << std::endl;
    for(auto outer : all_sale){
        for(auto inner : outer){
            std::cout << inner;
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "**************all case ****************" << std::endl;

    // 위 조합으로 루프 돌려 {합, 가입자}의 리스트 구하기
    vector<vector<int>> total_list;
    for(auto item_list : all_sale){
        int total = 0;
        int service = 0;
        for(auto user : users){
            // 한 사람이 구매
            int sub_total = 0;
            for(int i =0; i< item_list.size();i++){
                if(user[0] <= item_list[i]){
                    double discount = (100 - item_list[i]);
                    double percent = discount/100;
                    double count = static_cast<double>(emoticons[i]) * percent;
                    sub_total += static_cast<int>(count);
                }

                if(sub_total >= user[1]){
                    service++;
                    sub_total = 0;
                }
            }
            total += sub_total;
        }

        total_list.push_back({total, service});
    }

    std::cout << "************** total list ****************" << std::endl;
    for(auto outer : total_list){
        for(auto inner : outer){
            std::cout << inner;
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "**************total list****************" << std::endl;

    // max 가입자, max 합 으로 최종 결과 구하기
    std::sort(total_list.begin(), total_list.end(),
              [](const std::vector<int>& row1, const std::vector<int>& row2)
              {

                      if(row1[1] != row2[1]){
                          return row1[1] > row2[1];
                      }

                    return row1[0] > row2[0];
              });

    std::cout << "************** sorted total list ****************" << std::endl;
    for(auto outer : total_list){
        for(auto inner : outer){
            std::cout << inner;
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "************** sorted total list****************" << std::endl;




    return {total_list[0][1], total_list[0][0]};
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
