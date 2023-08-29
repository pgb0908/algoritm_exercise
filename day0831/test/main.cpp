#include <iostream>
#include <vector>

void generateCombinations(std::vector<int>& arr, std::vector<int>& currentCombination, int startIndex) {
    // 현재 조합을 출력
    for (int num : currentCombination) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 재귀적으로 모든 가능한 조합 생성
    for (int i = startIndex; i < arr.size(); ++i) {
        currentCombination.push_back(arr[i]);
        generateCombinations(arr, currentCombination, i + 1);
        currentCombination.pop_back();
    }
}

int main() {
    std::vector<int> array = {1, 2, 3}; // 조합을 구할 배열
    std::vector<int> currentCombination; // 현재 조합을 저장할 벡터
    generateCombinations(array, currentCombination, 0); // 조합 생성 시작
    return 0;
}
