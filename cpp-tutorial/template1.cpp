// 템플릿 문법
#include <iostream>
#include <string>
using namespace std;


class Vector {
    private:
        float x, y;
    
    public:
        Vector() : x(0), y(0) {}
        Vector(float x, float y) : x(x), y(y) {}
        
        float GetX() const { return x; }
        float GetY() const { return y; }
        Vector operator+(const Vector other) {
            return Vector(x+other.x, y+other.y);
        }
        
        Vector operator-(const Vector other) {
            return Vector(x-other.x, y-other.y);
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


template<typename T>
T getArraySum(const T arr[], int n) {
    T sum = arr[0];
    for (int i = 1; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}


int main() {
    int iarr[5]    = {3, 1, 4, 5};
    double darr[5] = {3.5, 1.2, 4.3, 1.1, 5.7};
    Vector varr[3] = {Vector(1, 2), Vector(3, 4), Vector(5, 6)};
    string sarr[3] = {"hello", "world", "doodle"};

    int isum    = getArraySum<int>(iarr, 5);
    double dsum = getArraySum<double>(darr, 5);
    Vector vsum = getArraySum(varr, 3);
    string ssum = getArraySum<string>(sarr, 3);

    cout << isum << endl;
    cout << dsum << endl;
    cout << vsum.GetX() << ", " << vsum.GetY() << endl;
    cout << ssum << endl;
}