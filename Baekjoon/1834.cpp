#include <iostream>

// 문제 링크 : https://www.acmicpc.net/problem/1834
// 나머지와 몫이 같은 수
// N으로 나누었을 때 나머지와 몫이 같은 모든 자연수의 합을 구하는 프로그램을 작성하시오. 
// 예를 들어 N=3일 때, 나머지와 몫이 모두 같은 자연수는 4와 8 두 개가 있으므로, 그 합은 12이다.
// 해당 수식을 구현하면 나머지 == 몫이고, 나머지는 0부터 N-1까지 가능하다.
// 따라서 1부터 N-1까지 반복하면서 N * i + i를 더하면 된다.

int main() {
    int N;
    std::cin >> N;
    long long sum = 0;
    for (long long i = 1; i < N; i++) {
        sum += N * i + i;
    }
    std::cout << sum << std::endl;
    return 0;
}