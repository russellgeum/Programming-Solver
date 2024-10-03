// https://www.acmicpc.net/problem/1789
// 1. 자연수 S를 입력받는다.
// 2. 자연수 S를 만들 수 있는 가장 큰 수를 출력한다.

// 원리가 왜 그럴까?
// 1부터 시작해서 더하는 것이 가장 큰 수를 만들 수 있는 방법이라는 것을 증명할 수 있을까?
// 1부터 더해서 S를 넘어가면, 그 전까지 더한 숫자 중 차이만큼 빼면 된다.
#include <iostream>

int main() {
    long long S;
    std::cin >> S;
    long long sum = 0;
    int count = 0;

    for (int i = 1; i <= S; i++) {
        sum += i;
        count++;
        if (sum > S) {
            count--;
            break;
        }
    }
    std::cout << count << std::endl;
}