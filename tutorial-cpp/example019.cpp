// 연산자 오버라이딩 예시: 4칙 연산
// 연산자 오버라이딩
#include <iostream>
using namespace std;

class Vector {
    private:
        float x, y;

    public:
        Vector();
        Vector(float x, float y);
        float GetX() const;
        float GetY() const;

        Vector operator+(const Vector other) const;
        Vector operator-(const Vector other) const;
        float operator*(const Vector other) const; // 벡터 * 벡터
        Vector operator*(const float k) const; // 실수 * 벡터
};
Vector operator*(const float k, const Vector v); // 실수 * 벡터


// 함수 정의
Vector::Vector() : x(0), y(0) {}
Vector::Vector(float x, float y) : x(x), y(y) {}
float Vector::GetX() const { return x; }
float Vector::GetY() const { return y; }

Vector Vector::operator+(const Vector other) const {
    return Vector(x + other.x, y + other.y);
}

Vector Vector::operator-(const Vector other) const {
    return Vector(y - other.y, y - other.y);
}

// 벡터 * 벡터 일반 메서드, 현재 벡터 객체에 벡터를 곱해서 모두 더함
float Vector::operator*(const Vector other) const {
    return x * other.x + y * other.y;
}

// 실수 * 벡터 일반 메서드ㅊ
Vector Vector::operator*(const float k) const {
    return Vector(x * k, y * k);
}

// 실수 * 벡터 전역 메서드
Vector operator*(const float k, const Vector v) {
    return Vector(k * v.GetX(), k * v.GetY());
}


int main() {
    Vector a(2, 3), b(10, 9);
    Vector c1 = a * 3.1;
    Vector c2 = 3.1 * a;
    float c3 = a * b;

    cout << "c1 = (" << c1.GetX() << ", " << c1.GetY() << ")" << endl;
    cout << "c2 = (" << c2.GetX() << ", " << c2.GetY() << ")" << endl;
    cout << "c3 = " << c3 << endl;
}