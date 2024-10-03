#include <iostream>

// 백준: https://www.acmicpc.net/problem/1110
// 1. 0보다 크거나 같고, 99보다 작거나 같은 정수가 주어질 때 다음과 같은 연산을 할 수 있다. 
// 2. 먼저 주어진 수가 10보다 작다면 앞에 0을 붙여 두 자리 수로 만들고, 각 자리의 숫자를 더한다.
// 3. 그 다음, 주어진 수의 가장 오른쪽 자리 수와 앞에서 구한 합의 가장 오른쪽 자리 수를 이어 붙이면 새로운 수를 만들 수 있다.

// 1. 26부터 시작한다. 2+6 = 8이다. 
// 2. 새로운 수는 68이다. 6+8 = 14이다. 
// 3. 새로운 수는 84이다. 8+4 = 12이다. 
// 4. 새로운 수는 42이다. 4+2 = 6이다. 
// 5. 새로운 수는 26이다.
// 6. 원래 수로 돌아오면은 종료

// std::string int2string(int num) {
//     return std::to_string(num);
// }

// int string2int(std::string num) {
//     return std::stoi(num);
// }

int main() {
    int init_num;
    int new_num;
    int count = 0;
    // 초기 숫자 입력
    std::cin >> init_num;
    // // 초기 숫자를 문자열로 변환
    // std::string init_string = int2string(init_num);
    // std::cout << init_num << std::endl;
    int original_num = init_num;

    do {
        // 주어진 수를 10으로 나눈 몫
        int tens = init_num / 10;
        // 주어진 수를 10으로 나눈 나머지
        int ones = init_num % 10;
        // 각 자리 수의 합
        int sum = tens + ones;

        // 몫과 나머지를 더한 값 -> 새로운 수로 초기화
        init_num = (ones * 10) + (sum % 10);
        count++; // 카운트 증가

    } while (init_num != original_num); // 새로운 수가 원래 수와 같을때까지 종료

    std::cout << count << std::endl;
    return 0;
}