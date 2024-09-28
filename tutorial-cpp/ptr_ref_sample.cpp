// 지금부터 이 코드는 C++의 포인터와 레퍼런스의 다양한 예시를 작성하는 코드 바닥
// 포인터와 레퍼런스의 예시
// 포인터와 레퍼런스를 함수의 인자로 전달하는 예시
// 포인터와 레퍼런스를 클래스에서 활용하는 예시
// 포인터와 레퍼런스를 반환하는 예시
// 포인터와 레퍼런스를 비교하는 예시
// 포인터와 레퍼런스를 사용하여 메모리를 할당하는 예시
// 포인터와 레퍼런스를 사용하여 메모리를 해제하는 예시
// 포인터와 레퍼런스를 사용하여 메모리를 복사하는 예시

#include <iostream>

// 포인터와 레퍼런스를 클래스에서 사칙연산에 활용하는 간단한 예시
class Calculator {
    private:
        int* ptr;
        int& ref;
    public:
        // 이게 왜 필요해?
        // 포인터와 레퍼런스를 클래스에서 사칙연산에 활용하기 위해서는 포인터와 레퍼런스를 클래스의 멤버 변수로 선언해야 함
        Calculator(int* ptr, int& ref) : ptr(ptr), ref(ref) {}
        int add(int* ptr, int& ref);
        int subtract(int* ptr, int& ref);
        int multiply(int* ptr, int& ref);
        int divide(int* ptr, int& ref);
};

// 이건 뭐야?
int Calculator::add(int* ptr, int& ref) {
    // 포인터와 레페런스의 연산에는 주의해야 함
    // ptr은 메모리 주소이므로 *ptr은 메모리 주소에 저장된 값을 가리키는 변수
    // ref는 메모리 주소를 가리키는 변수
    // 따라서 *ptr + ref는 메모리 주소에 저장된 값과 메모리 주소를 가리키는 변수를 더하는 것
    int result = *ptr + ref;
    std::cout << "덧셈 결과 : " << result << std::endl;
    return result;
}

int Calculator::subtract(int* ptr, int& ref) {
    int result = *ptr - ref;
    std::cout << "뺄셈 결과 : " << result << std::endl;
    return result;
}

int Calculator::multiply(int* ptr, int& ref) {
    int result = *ptr * ref;
    std::cout << "곱셈 결과 : " << result << std::endl;
    return result;
}

int Calculator::divide(int* ptr, int& ref) {
    int result = *ptr / ref;
    std::cout << "나눗셈 결과 : " << result << std::endl;
    return result;
}


int main() {
    int number = 10;
    int* ptr = &number;
    int& ref = number;
    
    std::cout << "number의 값 : " << number << std::endl;
    std::cout << "ptr의 값 : " << ptr << std::endl;
    std::cout << "ref의 값 : " << ref << std::endl;

    Calculator calc(ptr, ref);
    calc.add(ptr, ref);
    calc.subtract(ptr, ref);
    calc.multiply(ptr, ref);
    calc.divide(ptr, ref);
    return 0;
}