#include <iostream>
#include <vector>

// 백준 1292번
// 문제 링크: https://www.acmicpc.net/problem/1292

int main() {
    int A;
    int B;
    std::cin >> A >> B;
    std::vector<int> sequence;

    // 수열 생성
    // 1에서부터 B까지 1을 더해가며 수열을 생성
    for (int i = 1; sequence.size() < B; ++i) {
        // 1에서는 1번 반복하여 1을 추가, 2에서는 2번 반복하여 2를 추가
        for (int j = 0; j < i; ++j) {
            sequence.push_back(i);
        }
    }

    // 구간 합 계산
    // 인덱스가 A-1에서부터 B 미만까지 i를 늘려가며 sequence의 i번째 인덱스의 원소를 누적
    int sum = 0;
    for (int i = A - 1; i < B; ++i) {
        sum += sequence[i];
    }

    std::cout << sum << std::endl;
    return 0;
}
