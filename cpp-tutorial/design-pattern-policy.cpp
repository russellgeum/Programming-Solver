#include "header.h"

// Policy Base Design
// C++에서 널리 사용
// STL 구현에서 널리 사용
// 전략 패턴 + 성능 향상
// 템플릿 메서드, Strategy 말고 다른 방법 -> Policy base Design
// 정책 기반, 전략 기반 모두 클래스의 알고리즘을 분리하는 것은 동일
// 어떻게 교체할 것인가의 차이점 (정책: 인라인 치환, 전략: 가상함수 기반)

// cppconference의 예제 참고


int main() {
    std::vector<int> v;
    
    std::cout << "----" << std::endl;
    v.resize(5);
    std::cout << "----" << std::endl;
}