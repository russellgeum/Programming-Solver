#include <iostream>
#include <unordered_map>
#include <cctype>

// 백준 https://www.acmicpc.net/problem/1157
// 알파벳 단어가 주어진다.
// 가장 많이 입력된 알파벳을 찾는다.
// 1. 문자열을 순회
// 2. 문자열이 메모리에 없으면 추가
// 3. 문자열이 메모리에 있으면 카운트

int main() {
    std::string inputs;
    std::cin >> inputs;
    std::unordered_map<char, int> memory;
    std::cout << inputs << std::endl; // 테스트 문자 출력

    // 알파벳을 대문자로 변경 (입력값의 참조자를 사용)
    for (auto& c : inputs) {
        c = std::toupper(c);
    }

    // 각 알파벳의 빈도를 계산
    for (char c : inputs) {
        memory[c]++;
    }

    // 최대 빈도를 찾기 위한 변수
    char most_frequent_char = '?';
    int max_count = 0;
    bool is_tie = false; // 가장 많이 나온 알파벳이 여러 개일 때 체크

    // memory의 pair로 순회하여 pair의 second가 max_count보다 크면 pair.first를 most_frequent_char로 대체
    // 순회값이 max_count이면 is_tie = True
    for (const auto& pair : memory) {
        if (pair.second > max_count) {
            max_count = pair.second;
            most_frequent_char = pair.first;
            is_tie = false;
        } else if (pair.second == max_count) {
            is_tie = true;
        }
    }

    // 가장 많이 나온 알파벳 출력 (동률일 경우 ? 출력)
    if (is_tie) {
        std::cout << "?" << std::endl;
    } else {
        std::cout << most_frequent_char << std::endl;
    }
}