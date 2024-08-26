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
};

// 클래스에는 기능 선언한 하고 구현은 분리
Vector::Vector() : x(0), y(0) {}

Vector::Vector(float x, float y) : x(x), y(y) {}

float Vector::GetX() const { 
    return x; 
    }

float Vector::GetY() const { 
    return y; 
    }


int main() {
    Vector a(2, 3);
    cout << "a = (" << a.GetX() << ", " << a.GetY() << ")" << endl;
}