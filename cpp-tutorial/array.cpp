#include <iostream>
#include <array>

// 템플릿 함수 정의
template <typename T>
T convert(double num) {
    return static_cast<T>(num);
};

int main() {
    // std::array를 int 타입으로 선언하고 convert 템플릿을 명시적으로 호출
    std::array<int, 10> arrayValue = {convert<int>(1.1), convert<int>(2.5), convert<int>(3.9)};

    // 배열 출력
    for (auto i : arrayValue) {
        std::cout << i << std::endl;  // 1, 1, 1, 0, 0, 0, 0
    }

    // array의 시작과 끝을 가리키는 주소
    std::cout << arrayValue.begin() << std::endl;
    std::cout << arrayValue.end() << std::endl;

    return 0;
}