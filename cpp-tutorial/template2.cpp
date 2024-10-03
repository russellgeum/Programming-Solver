#include<iostream>
#include<string>
using namespace std;


class Vector2 {
    private:
        float x, y;
    public:
        Vector2() : x(0), y(0) {}
        Vector2(float x, float y) : x(x), y(y) {}
        float GetX() const { return x; }
        float GetY() const { return y; }
        
        Vector2 operator-(const Vector2 other) {
            return Vector2(x - other.x, y - other.y);
        }

        Vector2 operator+(const Vector2 other) {
            return Vector2(x + other.x, y + other.y);
        }

        Vector2& operator+=(const Vector2 other) {
            x += other.x;
            y += other.y;
            return *this;
        }

        Vector2& operator-=(const Vector2 other) {
            x -= other.x;
            y -= other.y;
            return *this;
        }  
};


template<typename T>
T getArraySum(const T arr[], int size) {
    T sum = arr[0];
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}


int main() {
    int iarr[5]     = {3, 1, 4, 1, 5};
    double darr[5]  = {3.1, 4.1, 5.9, 2.6, 5.3};
    Vector2 varr[5] = {Vector2(1, 2), Vector2(3, 4), Vector2(5, 6), Vector2(7, 8), Vector2(9, 10)};
    string sarr[3]  = {"Hello", "World", "!"};
    
    int isum     = getArraySum<int>(iarr, 5);
    double dsum  = getArraySum<double>(darr, 5);
    Vector2 vsum = getArraySum<Vector2>(varr, 5);
    string ssum  = getArraySum<string>(sarr, 3);

    cout << "isum: " << isum << endl;
    cout << "dsum: " << dsum << endl;
    cout << "vsum: " << vsum.GetX() << ", " << vsum.GetY() << endl;
    cout << "ssum: " << ssum << endl;
}