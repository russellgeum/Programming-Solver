#include <iostream>
#include <vector>

// 백준 1546번
// 문제 링크: https://www.acmicpc.net/problem/1546

int main() {
    // 과목 수와 과목별 점수 입력
    int N;
    std::cin >> N;

    std::vector<double> seqeunce_score(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> seqeunce_score[i];  // 성적을 입력받아 벡터에 저장
    }

    // 과목별 점수 벡터에서 최댓값 선택
    double max_score = seqeunce_score[0];
    for (int i = 1; i < seqeunce_score.size(); i++) {
        if (seqeunce_score[i] > max_score) {
            max_score = seqeunce_score[i];
        }
    }
    // std::cout << "과목의 최댓값은 " << max_score << std::endl;

    // 모든 과목을 최댓값으로 나누고 100을 곱하기
    double mean = 0;
    for (int i = 0; i < seqeunce_score.size(); i++) {
        double new_value;
        new_value = seqeunce_score[i] / max_score; // 과목 점수를 최댓값으로 나누기
        new_value *= 100; // 과목 점수에 100을 곱하기
        mean += new_value; // 과목 점수 누적
    }
    mean = mean / N;
    std::cout << mean << std::endl;
}