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
};


int main() {
    Vector a(2, 3), b(10, 9);
    Vector c = a+b;
    Vector d = a-b;

    cout << "c = (" << c.GetX() << ", " << c.GetY() << ")" << endl;
    cout << "d = (" << d.GetX() << ", " << d.GetY() << ")" << endl;
}


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