#include <iostream>

// https://www.acmicpc.net/problem/1357
// 1. 어떤 수 X가 주어졌을 때, X의 모든 자리수가 역순이 된 수를 얻을 수 있다.
// 2. Rev(X)를 X의 모든 자리수를 역순으로 만드는 함수라고 하자.
//    예를 들어, X=123일 때, Rev(X) = 321이다. 그리고, X=100일 때, Rev(X) = 1이다.
// 3. 두 양의 정수 X와 Y가 주어졌을 때, Rev(Rev(X) + Rev(Y))를 구하는 프로그램을 작성하시오


int Rev(int x) {
    int reversed  = 0;
    while (x > 0) {
        // 예시
        // 123이면
        // 123 % 10 = 3
        // 12 % 10 = 2
        // 1 % 10 = 1

        // 초기 0에서 3을 더하면 3이 된다.
        // 3을 곱하면 30이 된다.
        // 30에서 2를 더하면 32가 된다.
        // 32에서 1을 더하면 321이 된다.
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return reversed;
}


int main() {
    int x, y;
    std::cin >> x >> y;
    std::cout << Rev(Rev(x) + Rev(y)) << std::endl;
    return 0;
}