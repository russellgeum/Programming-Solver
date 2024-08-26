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

        // 일반 메서드 선언
        Vector Add(Vector other);
        // 정적 메서드 선언
        static Vector Sum(Vector a, Vector b);
};


// // 전역 함수 선언
// Vector Sum(Vector a, Vector b);


Vector::Vector() : x(0), y(0) {}
Vector::Vector(float x, float y) : x(x), y(y) {}
float Vector::GetX() const { return x; }
float Vector::GetY() const { return y; }

// 일반 메서드 정의
Vector Vector::Add(Vector other) {
    return Vector(x + other.x, y + other.y);
}

// 정적 메서드 정의
Vector Vector::Sum(Vector a, Vector b) {
    return Vector(a.x + b.x, a.y + b.y);
}

// // 전역 함수 정의
// Vector Sum(Vector a, Vector b) {
//     return Vector(a.GetX() + b.GetX(), a.GetY() + b.GetY());
// }


/****************** main 함수 ******************/

int main() {
    Vector a(2, 3), b(5, 6);
    // Vector c1 = Sum(a, b);          // 전역 함수 호출
    Vector c3 = a.Add(b);           // 일반 메서드 호출
    Vector c2 = Vector::Sum(a, b);  // 정적 메서드 호출 = 선언 없이 모든 객체에서 접근 가능한 함수

    // cout << "c1 = (" << c1.GetX() << ", " << c1.GetY() << ")" << endl;
    cout << "c2 = (" << c2.GetX() << ", " << c2.GetY() << ")" << endl;
    cout << "c3 = (" << c3.GetX() << ", " << c3.GetY() << ")" << endl;
}