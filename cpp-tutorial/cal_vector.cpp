#include <iostream>
using namespace std;

class Vector {
private:
    // 벡터 연산 결과를 저장할 원소 변수
    float x, y;

    // 생성자를 private으로 변경
    Vector();
    Vector(float x, float y);

    // 유일한 인스턴스를 저장할 정적 변수
    static Vector* instance;

public:
    // 소멸자
    ~Vector() {}

    // 인스턴스에 접근할 수 있는 정적 메서드
    static Vector* getInstance(float x, float y) {
        if (instance == nullptr) {
            instance = new Vector(x, y);  // 인스턴스가 없으면 생성
        }
        return instance;
    }

    // 원소 값 얻기
    float GetX() const;
    float GetY() const;

    // 벡터 합 비정적 메서드
    void sum(Vector& vec1, Vector& vec2);
    // 벡터 리셋 비정적 메서드
    void reset();

    // 벡터 출력
    void printVector();

    // 벡터 합 정적 메서드
    static Vector sumStatic(Vector& vec1, Vector& vec2);
};

// 정적 변수 초기화
Vector* Vector::instance = nullptr;

Vector::Vector() : x(0), y(0) {}

Vector::Vector(float x, float y) : x(x), y(y) {}

float Vector::GetX() const { 
    return this->x; 
}

float Vector::GetY() const { 
    return this->y; 
}

void Vector::sum(Vector& vec1, Vector& vec2) {
    this->x = vec1.x + vec2.x;
    this->y = vec1.y + vec2.y;
}

void Vector::reset() {
    this->x = 0;
    this->y = 0;
}

void Vector::printVector() {
    std::cout << "(" << this->x << ", " << this->y << ")" << std::endl;
}

// 정적 메서드 정의
Vector Vector::sumStatic(Vector& vec1, Vector& vec2) {
    Vector result(vec1.x + vec2.x, vec1.y + vec2.y);  // 두 벡터의 합으로 새로운 벡터 생성
    return result;
}


/****************** main 함수 ******************/
int main() {
    // 싱글톤 객체를 가져옴
    Vector* c = Vector::getInstance(0, 0); // 결과값 저장
    Vector* a = Vector::getInstance(5, 5);
    Vector* b = Vector::getInstance(5, 5);

    c->printVector();
    c->sum(*a, *b);
    c->printVector();  // 결과 출력

    return 0;
}
