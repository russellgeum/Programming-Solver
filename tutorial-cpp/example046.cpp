#include <iostream>
using namespace std;

template<typename T>
class Vector {
    private:
        T x, y;
    public:
        Vector() : x(0), y(0) {}
        Vector(T x, T y) : x(x), y(y) {}
        T GetX() const { return x; }
        T GetY() const { return y; }
        
        Vector operator-(const Vector other) {
            return Vector(x - other.x, y - other.y);
        }

        Vector operator+(const Vector other) {
            return Vector(x + other.x, y + other.y);
        }

        Vector& operator+=(const Vector other) {
            x += other.x;
            y += other.y;
            return *this;
        }

        Vector& operator-=(const Vector other) {
            x -= other.x;
            y -= other.y;
            return *this;
        }
};

int main() {
    Vector<int> v1(1, 2);
    Vector<double> v2(3.1, 4.2);
    cout << v1.GetX() << ", " << v1.GetY() << endl;
    cout << v2.GetX() << ", " << v2.GetY() << endl;
}