// https://www.acmicpc.net/problem/1769
// 1. 숫자를 입력받는다.
// 2. 각 숫자의 자릿수를 모두 더한다.
// 3. 더한 숫자가 한 자리 숫자가 될 때까지 반복한다.
// 4. 더한 숫자가 한 자리 숫자가 되면 종료한다.
// 5. 더한 횟수를 출력한다.

#include <iostream>

int main() {
    std::string X;
    std::cin >> X;
    int sum = 0;
    int count = 0;

    // 한 자리 숫자가 될 때까지 반복
    while (X.length() != 1) {
        for (int i = 0; i < X.length(); i++) {
            sum += X[i] - '0';
        }
        // 더한 숫자를 문자열로 다시 변환
        X = std::to_string(sum);
        sum = 0;
        count++;
    }

    // 마지막 숫자는 2자리 수이므로 다시 한 번 더하기
    sum = 0;
    for (int i = 0; i < X.length(); i++) {
        sum += X[i] - '0';
    }
    std::cout << count << std::endl;
    std::cout << (sum % 3 == 0 ? "YES" : "NO") << std::endl;
    return 0;
}